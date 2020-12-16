#include <pybind11/pybind11.h> //needs to be included before anything else...
#include "common.h"
#include "meshlab_singletons.h"

#include <QDir>
#include <common/mlapplication.h>
#include <common/pluginmanager.h>

/** Ridirects **/

std::stringstream pymeshlab::CoutRedirect::buffer;
std::stringstream pymeshlab::CerrRedirect::buffer;

namespace py = pybind11;

std::string pymeshlab::getRootPath()
{
#ifndef PYMESHLAB_DEBUG
	//py::gil_scoped_acquire acquire;
	py::object pyml;
	std::string basePath;
	try {
		pyml = py::module::import("pymeshlab");
		basePath = pyml.attr("__file__").cast<std::string>();
	}
	catch(...){
		try {
			pyml = py::module::import(PYMESHLAB_MODULE_NAME_STR);
			basePath = pyml.attr("__file__").cast<std::string>();
		} 
		catch (...) {
			std::string err = 
				"Irreversible error: impossible to know the position of the pymeshlab module.";
			std::runtime_error exc(err);
			throw exc;
		}
	}
	QDir dir(QString::fromStdString(basePath));
	dir.cdUp();
#else
	QDir dir;
#endif
	return dir.absolutePath().toStdString();
}

std::string pymeshlab::getPluginsPath()
{
	QDir dir(QString::fromStdString(getRootPath()));
#ifdef __APPLE__
	dir.cd("PlugIns");
#else
	dir.cd("lib/plugins");
#endif
	return dir.absolutePath().toStdString();
}

std::string pymeshlab::getSamplesPath()
{
	std::string rootPath = getRootPath();
	return rootPath + "/tests/sample/";
}

void pymeshlab::printVersion()
{
	std::string pymsversion;
#ifdef PYMESHLAB_VERSION
	pymsversion = PYMESHLAB_STRINGIFY(PYMESHLAB_VERSION);
#else
	pymsversion = "DEV";
#endif
	
	std::cout << "PyMeshLab " << pymsversion << " based on MeshLab " << 
		MeshLabApplication::appVer().toStdString() << "\n";
}

int pymeshlab::numberPlugins()
{
	PluginManager& pm = MeshLabSingletons::pluginManagerInstance();
	return pm.size();
}

pybind11::dict pymeshlab::toPyDict(const std::map<std::string, QVariant>& qVariantMap)
{
	pybind11::dict outDict;
	for (const auto& p : qVariantMap){
		if (std::string(p.second.typeName()) == "int"){
			outDict[p.first.c_str()] = p.second.toInt();
		}
		else if (std::string(p.second.typeName()) == "double"){
			outDict[p.first.c_str()] = p.second.toDouble();
		}
		else if (std::string(p.second.typeName()) == "float"){
			outDict[p.first.c_str()] = p.second.toFloat();
		}
		else if (std::string(p.second.typeName()) == "bool"){
			outDict[p.first.c_str()] = p.second.toBool();
		}
		else {
			std::cerr << "Warning: type " << p.second.typeName() 
				<< " still not supported for py::dict conversion\n"
				<< "Please open an issue on GitHub about this."; 
		}
	}
	return outDict;
}
