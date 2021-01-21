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
#include <pybind11/pybind11.h> //needs to be included before anything else...
#include "common.h"

#include <QDir>
#include <common/ml_document/base_types.h>
#include <common/interfaces/filter_plugin_interface.h>

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

void pymeshlab::printSaveMask(int mask)
{
	for (uint i = 0; i < 14; i++){
		if (mask & capabilitiesBits[i])
			std::cout << saveCapabilitiesStrings[i].toStdString() << "\n";
	}
}
