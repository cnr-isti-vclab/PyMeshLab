#include "common.h"

#include <pybind11/pybind11.h>
#include <QDir>

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
