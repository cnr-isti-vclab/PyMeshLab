#include "pymeshlabcommon.h"

#include <pybind11/pybind11.h>
#include <QDir>

namespace py = pybind11;

std::stringstream pymeshlab::CoutRedirect::buffer;
std::stringstream pymeshlab::CerrRedirect::buffer;

std::string pymeshlab::getRootAbsolutePath()
{
#ifndef PYMESHLAB_DEBUG
	py::gil_scoped_acquire acquire;
	py::object pyml = py::module::import("pymeshlab");
	std::string basePath = pyml.attr("__file__").cast<std::string>();
	QDir dir(QString::fromStdString(basePath));
	dir.cdUp();
#else
	QDir dir;
#endif
	return dir.absolutePath().toStdString();
}




