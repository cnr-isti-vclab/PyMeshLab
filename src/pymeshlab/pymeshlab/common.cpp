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
	py::gil_scoped_acquire acquire;
	py::object pyml = py::module::import(PYMESHLAB_MODULE_NAME_STR);
	std::string basePath = pyml.attr("__file__").cast<std::string>();
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
	dir.cd("lib/plugins");
	return dir.absolutePath().toStdString();
}

std::string pymeshlab::getSamplesPath()
{
	std::string rootPath = getRootPath();
	return rootPath + "/tests/sample/";
}
