/****************************************************************************
* PyMeshLab                                                         o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005-2021                                           \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
#include "meshset.h"

#include <clocale>

#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <common/mlexception.h>
#include <common/utilities/load_save.h>
#include <common/globals.h>
#include <common/python/python_utils.h>
#include "percentage.h"
#include "exceptions.h"
#include "helpers/common.h"
#include "helpers/meshset_helper.h"

namespace py = pybind11;

pymeshlab::MeshSet::MeshSet(bool verbose) :
	MeshDocument(),
	pm(meshlab::pluginManagerInstance()),
	functionSet(pymeshlab::functionSetInstance())
{
	setVerbosity(verbose);
}

pymeshlab::MeshSet::~MeshSet()
{
}

void pymeshlab::MeshSet::setVerbosity(bool verbose)
{
	if (verbose){
		verbosityManager.enableVerbosity();
	}
	else {
		verbosityManager.disableVersbosity();
	}
}

void pymeshlab::MeshSet::setParameterVerbosity(bool verbose)
{
	if (verbose) verbosityManager.enableParameterVerbosity();
	else verbosityManager.disableParameterVerbosity();
}

MeshModel& pymeshlab::MeshSet::currentMesh()
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no current Mesh.");
	return *mm();
}

int pymeshlab::MeshSet::currentMeshId() const
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no current Mesh.");
	return mm()->id();
}

bool pymeshlab::MeshSet::meshIdExists(int id) const
{
	return getMesh(id) != nullptr;
}

MeshModel& pymeshlab::MeshSet::mesh(int id)
{
	MeshModel* tmp = getMesh(id);
	if (tmp == nullptr)
		throw MLException("Mesh ID " + QString::number(id) + " not found in MeshSet.");
	return *tmp;
}

void pymeshlab::MeshSet::setCurrentMeshVisibility(bool visibility)
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no current Mesh.");
	mm()->setVisible(visibility);
}

void pymeshlab::MeshSet::setMeshVisibility(int id, bool visibility)
{
	MeshModel* tmp = getMesh(id);
	if (tmp == nullptr)
		throw MLException("Mesh ID " + QString::number(id) + " not found in MeshSet.");
	tmp->setVisible(visibility);
}

bool pymeshlab::MeshSet::isCurrentMeshVisible() const
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no current Mesh.");
	return mm()->isVisible();
}

bool pymeshlab::MeshSet::isMeshVisible(int id) const
{
	const MeshModel* tmp = getMesh(id);
	if (tmp == nullptr)
		throw MLException("Mesh ID " + QString::number(id) + " not found in MeshSet.");
	return tmp->isVisible();
}

/**
 * @brief prints all the filters (with their parameters) that have been applied on the current 
 * MeshSet. 
 */
void pymeshlab::MeshSet::printFilterScript() const
{
	std::cout << "Filter Script Size : " << filterScript.size() << "\n\n";
	uint i = 0;
	for (const FilterNameParameterValuesPair& p :filterScript){
		std::cout << std::to_string(i) + ": " << computePythonName(p.filterName()).toStdString() <<
					 "\n";
		for (const RichParameter& par : p.second){
			FunctionParameter ffp(par);
			std::cout << "\t" << ffp.pythonName().toStdString() << " : "
					  << ffp.pythonTypeString().toStdString() << " = ";
			ffp.printDefaultValue(std::cout);
			std::cout << "\n";
		}
		std::cout << "\n";
		i++;
	}
}

void pymeshlab::MeshSet::loadNewMesh(const std::string& filename, py::kwargs kwargs)
{
	meshsethelper::loadMeshUsingPlugin(filename, kwargs, *this, verbosityManager, functionSet);
}

void pymeshlab::MeshSet::saveCurrentMesh(
		const std::string& filename,
		bool saveTextures,
		int qualityTextures,
		pybind11::kwargs kwargs)
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	std::setlocale(LC_ALL, "en_US.UTF-8");
	meshsethelper::saveMeshUsingPlugin(
		filename,
		mm(),
		saveTextures,
		qualityTextures,
		kwargs,
		*this,
		verbosityManager,
		functionSet);
}

/**
 * @brief adds the reference of the given mesh to the MeshSet.
 * @param mesh
 * @param name
 * @param setAsCurrent: default value: true
 */
void pymeshlab::MeshSet::addMesh(const MeshModel& mesh, std::string name, bool setAsCurrent)
{
	if (name == "")
		name = mesh.label().toStdString();

	auto* m =this->addNewMesh(mesh.cm, QString::fromStdString(name), setAsCurrent);

	//todo: remove this and better management of polymesh
	bool found = false;
	for (unsigned int i = 0; i < mesh.cm.face.size() && !found; ++i){
		if (mesh.cm.face[i].IsAnyF()) {
			found = true;
			m->enable(vcg::tri::io::Mask::IOM_BITPOLYGONAL);
		}
	}
}

void pymeshlab::MeshSet::loadNewRaster(const std::string& filename)
{
	meshsethelper::loadRasterUsingPlugin(filename, *this);
}

void pymeshlab::MeshSet::loadProject(const py::object& filenames)
{
	std::list<std::string> filenms;
	if (py::isinstance<py::str>(filenames)){
		filenms.push_back(py::str(filenames));
	}
	else if (py::isinstance<py::list>(filenames)){
		py::list l = filenames;
		for (const auto& names : l){
			filenms.push_back(names.cast<std::string>());
		}
	}

	QStringList fn;
	for (const std::string& s : filenms)
		fn.append(QString::fromStdString(s));

	meshlab::loadProject(
			fn, *this,
			VerbosityManager::staticLogger, VerbosityManager::filterCallBack);
}

void pymeshlab::MeshSet::saveProject(const std::string& filename)
{
	meshlab::saveProject(QString::fromStdString(filename),
						 *this, true,
						 std::vector<MLRenderingData>());
}

void pymeshlab::MeshSet::loadFilterScript(const std::string& filename)
{
	filterScript.open(QString::fromStdString(filename));
}

void pymeshlab::MeshSet::saveFilterScript(const std::string& filename) const
{
	filterScript.save(QString::fromStdString(filename));
}

void pymeshlab::MeshSet::clearFilterScript()
{
	filterScript.clear();
}

void pymeshlab::MeshSet::applyFilterScript()
{
	for (const FilterNameParameterValuesPair& p : filterScript){
		QString meshlabFilterName = p.first;
		std::string filtername = computePythonName(meshlabFilterName).toStdString();
		QAction* action = nullptr;
		FilterPlugin* fp = meshsethelper::pluginFromFilterName(meshlabFilterName, action);
		RichParameterList rpl = fp->initParameterList(action, *this);
		meshsethelper::updateRichParameterList(filtername, p.second, rpl);
		meshsethelper::applyFilterRPL(
				filtername, meshlabFilterName, action, fp, rpl,
				verbosityManager, filterScript, false, *this);
	}
}

pybind11::dict pymeshlab::MeshSet::applyFilter(const std::string& filtername, pybind11::kwargs kwargs)
{
	py::dict outputValues;
	if (functionSet.containsFilterFunction(QString::fromStdString(filtername))) {
		const Function& f = functionSet.filterFunction(QString::fromStdString(filtername));

		if (f.isDeprecated()){
			py::module_ warn = py::module_::import("warnings");
			warn.attr("warn")("Deprecated Filter Warning: " + f.deprecatedString());
		}

		QString meshlabFilterName = f.meshlabFunctionName();
		
		QAction* action = nullptr;
		FilterPlugin* fp = meshsethelper::pluginFromFilterName(meshlabFilterName, action);
		if (fp->filterArity(action) != FilterPlugin::NONE && meshNumber() == 0){
			throw MLException(QString::fromStdString(filtername) +
				" requires at least one mesh loaded in the MeshSet.");
		}
		RichParameterList rpl= fp->initParameterList(action, *this);
		meshsethelper::updateRichParameterListFromKwargs(f, kwargs, this, rpl);
		outputValues = meshsethelper::applyFilterRPL(
				filtername, meshlabFilterName, action, fp, rpl,
				verbosityManager, filterScript, true, *this);
		
		if(verbosityManager.isVerbosityEnabled())
			std::cout << std::endl;
	}
	else {
		throw MLException(
					"Failed to apply filter: " + QString::fromStdString(filtername) + "\n" +
					"Filter does not exists. Take a look at MeshSet.print_filter_list function.");
	}
	return outputValues;
}

void pymeshlab::MeshSet::printStatus() const
{
	std::cout << "Number meshes: " << meshNumber() << "\n";
	for (const MeshModel& m : meshIterator()){
		std::cout << "\tMesh id: " << m.id() << "\n";
		std::cout << "\tMesh label: " << m.label().toStdString() << "\n";
		std::cout << "\tFull name: " << m.fullName().toStdString() << "\n\n";
	}
}

pybind11::dict pymeshlab::MeshSet::filterParameterValues(
		const std::string& filtername, 
		pybind11::kwargs kwargs)
{
	py::dict outputValues;
	if (functionSet.containsFilterFunction(QString::fromStdString(filtername))) {
		const Function& f = functionSet.filterFunction(QString::fromStdString(filtername));
		QString meshlabFilterName = f.meshlabFunctionName();
		
		QAction* action = nullptr;
		FilterPlugin* fp = meshsethelper::pluginFromFilterName(meshlabFilterName, action);
		if (fp->filterArity(action) != FilterPlugin::NONE && meshNumber() == 0){
			throw MLException(QString::fromStdString(filtername) +
				" requires at least one mesh loaded in the MeshSet.");
		}
		RichParameterList rpl = fp->initParameterList(action, *this);
		meshsethelper::updateRichParameterListFromKwargs(f, kwargs, this, rpl);
		outputValues = meshsethelper::pydictFromRichParameterList(rpl);
	}
	else if (functionSet.containsSaveMeshFunction(QString::fromStdString(filtername))) {
		if (meshNumber() == 0) {
			throw MLException(QString::fromStdString(filtername) +
							  " requires at least one mesh loaded in the MeshSet.");
		}
		const Function& f = functionSet.saveMeshFunction(QString::fromStdString(filtername));
		QString extension = QString::fromStdString(filtername);
		IOPlugin*       plugin = pm.outputMeshPlugin(extension);

		RichParameterList rps = plugin->initSaveParameter(extension, *this->mm());
		meshsethelper::updateRichParameterListFromKwargs(f, kwargs, this, rps, true);
		outputValues = meshsethelper::pydictFromRichParameterList(rps);
	}
	else {
		throw MLException(
					"Failed to get default falues of filter: " + QString::fromStdString(filtername) + "\n" +
					"Filter does not exists. Take a look at MeshSet.print_filter_list function.");
	}
	return outputValues;
}


