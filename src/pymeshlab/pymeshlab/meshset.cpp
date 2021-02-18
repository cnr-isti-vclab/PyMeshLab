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

#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <common/mlexception.h>

#include <common/globals.h>
#include "percentage.h"
#include "exceptions.h"
#include "helpers/common.h"
#include "helpers/meshset_helper.h"
#include "helpers/verbosity_manager.h"

namespace py = pybind11;

pymeshlab::MeshSet::MeshSet(bool verbose) :
	MeshDocument(),
	pm(meshlab::pluginManagerInstance())//,
	//sceneGLSharedDataContext(nullptr)
{
	if (!verbose)
		VerbosityManager::disableVersbosity();
	//pm.loadPlugins(QString::fromStdString(getPluginsPath()));
	functionSet.populate(pm);
	setVerbosity(verbose);
	if (!verbose)
		VerbosityManager::enableVerbosity();
}

pymeshlab::MeshSet::~MeshSet()
{
	//delete sceneGLSharedDataContext;
}

void pymeshlab::MeshSet::setVerbosity(bool verbose)
{
	this->verbose = verbose;
	if (verbose){
		for (auto p : pm.filterPluginIterator())
			p->setLog(&Log);
		for (auto p : pm.ioMeshPluginIterator())
			p->setLog(&Log);
		for (auto p : pm.ioRasterPluginIterator())
			p->setLog(&Log);
	}
	else {
		for (auto p : pm.filterPluginIterator())
			p->setLog(nullptr);
		for (auto p : pm.ioMeshPluginIterator())
			p->setLog(nullptr);
		for (auto p : pm.ioRasterPluginIterator())
			p->setLog(nullptr);
	}
}

CMeshO& pymeshlab::MeshSet::currentMesh()
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	return mm()->cm;
}

int pymeshlab::MeshSet::currentMeshId() const
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	return mm()->id();
}

bool pymeshlab::MeshSet::meshIdExists(int id) const
{
	return getMesh(id) != nullptr;
}

CMeshO& pymeshlab::MeshSet::mesh(int id)
{
	MeshModel* tmp = getMesh(id);
	if (tmp == nullptr)
		throw MLException("Mesh ID " + QString::number(id) + " not found in MeshSet.");
	return tmp->cm;
}

/**
 * @brief lists all the filters that can be called using the "apply_filter" function
 */
void pymeshlab::MeshSet::printPythonFilterNamesList() const
{
	QStringList list = functionSet.pythonFilterFunctionNames();
	std::cout << "MeshSet class - list of filter names:\n";
	for (const QString& fname : list){
		std::cout << "\t" << fname.toStdString() << "\n";
	}
}

/**
 * @brief given the function names, lists all its parameters that can be 
 * passed to the "apply_filter" function
 * @param functionName
 */
void pymeshlab::MeshSet::printPythonFilterParameterList(const std::string& functionName) const
{
	const Function& ff = functionSet.filterFunction(QString::fromStdString(functionName));
	std::cout <<
				"Please note: some parameters depend on the mesh(es) used as input of the \n"
				"filter. Default values listed here are computed on a 1x1x1 cube \n"
				"(pymeshlab/tests/sample/cube.obj), and they will be computed on the input mesh\n"
				"if they are left as default.\n";

	std::cout << functionName <<" filter - list of parameter names:\n";
	if (ff.parametersNumber() == 0) {
		std::cout << "\tNone.\n";
	}
	else {
		for (const FunctionParameter& ffp : ff) {
			std::cout << "\t" << ffp.pythonName().toStdString() << " : "
					  << ffp.pythonTypeString().toStdString() << " = ";
			ffp.printDefaultValue(std::cout);
			std::cout << "\n";
		}
	}
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
		std::cout << std::to_string(i) + ": " << FunctionSet::toPythonName(p.filterName()).toStdString() <<
					 "\n";
		for (const RichParameter& par : p.second){
			FunctionParameter ffp(FunctionSet::toPythonName(par.name()), par);
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
	meshsethelper::loadMeshUsingPlugin(filename, nullptr, kwargs, *this, functionSet);
}

void pymeshlab::MeshSet::loadCurrentMesh(const std::string& filename, pybind11::kwargs kwargs)
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	mm()->Clear();
	meshsethelper::loadMeshUsingPlugin(filename, mm(), kwargs, *this, functionSet);
}

void pymeshlab::MeshSet::saveCurrentMesh(const std::string& filename, pybind11::kwargs kwargs)
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	meshsethelper::saveMeshUsingPlugin(filename, mm(), kwargs, *this, functionSet);
}

/**
 * @brief adds the reference of the given mesh to the MeshSet.
 * @param mesh
 * @param name
 * @param setAsCurrent: default value: true
 */
void pymeshlab::MeshSet::addMesh(const CMeshO& mesh, const std::string& name, bool setAsCurrent)
{
	MeshModel* mm = this->addNewMesh("", QString::fromStdString(name), setAsCurrent);
	mm->cm = mesh;
}

void pymeshlab::MeshSet::loadNewRaster(const std::string& filename)
{
	meshsethelper::loadRasterUsingPlugin(filename, nullptr, *this);
}

void pymeshlab::MeshSet::loadProject(const std::string& filename)
{
	QString fileName = QString::fromStdString(filename);
	if (filename.empty())
		throw MLException("file_name empty.");

	QFileInfo fi(fileName);
	if((fi.suffix().toLower()!="aln") &&
			(fi.suffix().toLower()!="mlp")  &&
			(fi.suffix().toLower() != "mlb") &&
			(fi.suffix().toLower()!="out") &&
			(fi.suffix().toLower()!="nvm")) {
		throw MLException("Unknown project file extension: " + fi.suffix().toLower());
	}

	setFileName(fileName);
	setDocLabel(fileName);

	if (QString(fi.suffix()).toLower() == "aln") {
		meshsethelper::loadALN(fileName, *this);
	}

	if (QString(fi.suffix()).toLower() == "mlp" || QString(fi.suffix()).toLower() == "mlb") {
		meshsethelper::loadMLP(fileName, *this);
	}

	if (QString(fi.suffix()).toLower() == "out"){
		meshsethelper::loadBundler(fileName, *this);
	}

	if (QString(fi.suffix()).toLower() == "nvm"){
		meshsethelper::loadNVM(fileName, *this);
	}
}

void pymeshlab::MeshSet::saveProject(const std::string& filename)
{
	QString fileName = QString::fromStdString(filename);
	if (filename.empty())
		throw MLException("file_name empty.");

	QFileInfo fi(fileName);
	if((fi.suffix().toLower()!="mlp")  &&
			(fi.suffix().toLower() != "mlb")) {
		throw MLException("Unknown project file extension: " + fi.suffix().toLower());
	}

	if (QString(fi.suffix()).toLower() == "mlp" || QString(fi.suffix()).toLower() == "mlb") {
		meshsethelper::saveMLP(fileName, *this);
	}
}

void pymeshlab::MeshSet::loadFilterScript(const std::string& filename)
{
	pymeshlab::QDebugRedirect* qdbr = nullptr;
	if (!verbose)
		qdbr = new pymeshlab::QDebugRedirect(); //redirect qdebug to null

	filterScript.open(QString::fromStdString(filename));

	delete qdbr;
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
	for (FilterNameParameterValuesPair p : filterScript){
		QString meshlabFilterName = p.first;
		std::string filtername = FunctionSet::toPythonName(meshlabFilterName).toStdString();
		QAction* action = nullptr;
		FilterPluginInterface* fp = meshsethelper::pluginFromFilterName(meshlabFilterName, action);
		RichParameterList rpl;
		fp->initParameterList(action, *this, rpl);
		meshsethelper::updateRichParameterList(filtername, p.second, rpl);
		meshsethelper::applyFilterRPL(
				filtername, meshlabFilterName, action, fp, rpl,
				verbose, filterScript, false, *this);
	}
}

pybind11::dict pymeshlab::MeshSet::applyFilter(const std::string& filtername, pybind11::kwargs kwargs)
{
	py::dict outputValues;
	if (functionSet.containsFilterFunction(QString::fromStdString(filtername))) {
		const Function& f = functionSet.filterFunction(QString::fromStdString(filtername));
		QString meshlabFilterName = f.meshlabFunctionName();
		
		QAction* action = nullptr;
		FilterPluginInterface* fp = meshsethelper::pluginFromFilterName(meshlabFilterName, action);
		RichParameterList rpl;
		fp->initParameterList(action, *this, rpl);
		meshsethelper::updateRichParameterListFromKwargs(f, kwargs, this, rpl);
		outputValues = meshsethelper::applyFilterRPL(
				filtername, meshlabFilterName, action, fp, rpl,
				verbose, filterScript, true, *this);
		
		if(verbose)
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
	std::cout << "Number meshes: " << size() << "\n";
	for (const MeshModel* m : meshList){
		std::cout << "\tMesh id: " << m->id() << "\n";
		std::cout << "\tMesh label: " << m->label().toStdString() << "\n";
		std::cout << "\tFull name: " << m->fullName().toStdString() << "\n\n";
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
		FilterPluginInterface* fp = meshsethelper::pluginFromFilterName(meshlabFilterName, action);
		RichParameterList rpl;
		fp->initParameterList(action, *this, rpl);
		meshsethelper::updateRichParameterListFromKwargs(f, kwargs, this, rpl);
		outputValues = meshsethelper::pydictFromRichParameterList(rpl);
	}
	else {
		throw MLException(
					"Failed to get default falues of filter: " + QString::fromStdString(filtername) + "\n" +
					"Filter does not exists. Take a look at MeshSet.print_filter_list function.");
	}
	return outputValues;
}

//bool pymeshlab::MeshSet::isSceneGLSharedDataContextEnabled() const
//{
//	return sceneGLSharedDataContext != nullptr;
//}

//void pymeshlab::MeshSet::initSceneGLSharedDataContext()
//{
//	//Todo
//}

//MLSceneGLSharedDataContext* pymeshlab::MeshSet::sharedDataContext()
//{
//	return sceneGLSharedDataContext;
//}

std::string pymeshlab::MeshSet::filtersRSTDocumentation() const
{
	return meshsethelper::RSTDocumentationFromFilterFunctionSet(functionSet);
}



