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
#include <common/plugins/interfaces/filter_plugin.h>
#include <common/python/function_set.h>

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

/** docs **/

void endLineHTMLSubstitution(QString& htmlString)
{
	htmlString.replace("\n", "<br>");
}

std::string filterRSTDocumentation(
		const pymeshlab::Function& it,
		bool loadSave)
{
	std::string doc;

	doc += ".. data:: ";
	if (!loadSave) {
		doc += it.pythonFunctionName().toStdString() + "\n\n";
		doc += "   *MeshLab filter name*: '" + it.meshlabFunctionName().toStdString() + "'\n\n";
	}
	else {
		doc += it.meshlabFunctionName().toStdString() + "\n   :noindex:\n\n";
	}
	doc += "   .. raw:: html\n\n";
	QString desc = it.description();
	endLineHTMLSubstitution(desc);
	doc += "      " + desc.toStdString() + "</p>\n\n";

	if (it.parametersNumber() > 0) {

		doc += "   **Parameters:**\n\n";

		for (const pymeshlab::FunctionParameter& p : it){

			if (! p.richParameter().isOfType<RichEnum>()){
				doc += "   ``" + p.pythonName().toStdString() + " : " +
						p.pythonTypeString().toStdString() +
						" = " + p.defaultValueString().toStdString() + "``\n\n";
			}
			else {
				doc += "   ``" + p.pythonName().toStdString() + " : " +
						p.pythonTypeString().toStdString() +
						" = " + p.defaultValueString().toStdString() +
						" (or int = " + std::to_string(p.defaultValue().getInt()) +
						")``\n\n";
				doc += "      Possible enum values:\n\n";

				const RichEnum& ren = dynamic_cast<const RichEnum&>(p.richParameter());
				unsigned int i = 0;
				for (const QString& v : ren.enumvalues){
					doc += "         " + std::to_string(i++) +". ``'" + v.toStdString() +
							"'``\n";
				}
				doc +="\n";
			}

			doc += "      .. raw:: html\n\n";
			QString desc = p.longDescription();
			endLineHTMLSubstitution(desc);
			doc += "         <i>" + p.description().toStdString() + "</i>: " +
					desc.toStdString() + "\n\n";
		}

	}

	return doc;
}

std::string pymeshlab::filterListRSTDocumentation()
{
	pymeshlab::FunctionSet& functionSet = pymeshlab::functionSetInstance();
	std::string doc;

	doc += ".. _filter_list:\n\nList of Filters\n===============\n\n";

	doc +=
			"Here are listed all the filter names that can be given as a parameter "
			"to the function :py:meth:`pmeshlab.MeshSet.apply_filter`.\n\n"

			"Each filter accepts a list of parameters, that can be semantically classified as follows:\n\n"

			"   * `Boolean`: a classic ``bool`` value;\n"
			"   * `Integer`: a classic ``int`` value;\n"
			"   * `String`: a classic ``str`` value;\n"
			"   * `Float`: a classic ``float`` value;\n"
			"   * `Bounded Float`: a classic ``float`` that is expected to be bounded between a ``min`` and a ``max`` value; an out-of-bounds value will be clamped in [min-max];\n"
			"   * `Percentage`: represents a parameter that is relative to some other measure, specified in the documentation of the filter. This parameter can be of two different types:\n\n"

			"     * :py:class:`pmeshlab.Percentage` (recommended): the parameter will be treated as relative percentage value; see the documentation of the :py:class:`pmeshlab.Percentage` for further info;\n"
			"     * :py:class:`pmeshlab.AbsoluteValue`: the parameter will be treated as absolute value; see the documentation of the :py:class:`pmeshlab.AbsoluteValue` for further info;\n\n"

			"   * `Enum`: represents a parameter that can accept just one of a limited set of possible values. These values type can be ``int`` or ``str``; see the documentation of the specific filter for further info;\n"
			"   * `Color`: represents a color, and the parameter can be of type  :py:class:`pmeshlab.Color`; see the documentation of the  :py:class:`pmeshlab.Color` for further info;\n"
			"   * `3D Point (or 3D Vector)`: represents a 3D point or vector, and the parameter can be of type ``numpy.ndarray[numpy.float64[3]]`` (a numpy array containing three floats);\n"
			"   * `4x4 Matrix`: represents a 4x4 Matrix of floats, and the parameter can be of type ``numpy.ndarray[numpy.float64[4, 4]]`` (a 4x4 numpy array of floats);\n"
			"   * `Mesh`: represents a parameter that links to one of the meshes contained in the MeshSet on which the filter is applied. This parameter is of type ``int``, which indicates the ``id`` of the mesh in the MeshSet;\n"
			"   * `File Name`: a classic ``str`` that represents the path of a file that is going to be saved or loaded by the filter. The string is expected to have at least an extension on its final characters; see the documentation of the specific filter for further info;\n"
			"   * `Camera`: *still not supported*;\n\n"

			"The :py:meth:`pmeshlab.MeshSet.apply_filter` returns a dictionary that may contain some values returned by the "
			"applied filter. Most of the filters do not return nothing, therefore the dictionary will be empty.\n\n"

			"**Please note**: some filter parameters depend on the mesh(es) used as "
			"input of the filter. Default values listed here are computed on a 1x1x1 cube "
			"(pymeshlab/tests/sample/cube.obj), but their value will be computed on the input mesh "
			"if they are left as default.\n\n"
			"Filter documentation\n----------------------\n\n";

	/// apply_filter parameters
	for (const Function& f : functionSet.filterFunctionIterator()) {
		doc += filterRSTDocumentation(f, false);
	}

	return doc;
}

std::string pymeshlab::ioFormatListRSTDocumentation()
{
	pymeshlab::FunctionSet& functionSet = pymeshlab::functionSetInstance();
	std::string doc;

	doc += ".. _io_format_list:\n\nList of I/O Formats\n===================\n\n";

	//load parameters
	doc +=
			".. _load_mesh_parameters:\n\n"
			"load mesh parameters\n--------------------\n\n"
			"Here are listed all the file formats that can be loaded using"
			"the functions :py:meth:`pmeshlab.MeshSet.load_new_mesh` and "
			":py:meth:`pmeshlab.MeshSet.load_current_mesh`, with all the possible "
			"parameters that can be accepted by these functions.\n\n";

	for (const Function& f : functionSet.loadMeshFunctionIterator()) {
		doc += filterRSTDocumentation(f, true);
	}

	//save parameters
	doc +=
			".. _save_mesh_parameters:\n\n"
			"save mesh parameters\n--------------------\n\n"
			"Here are listed all the file formats that can be saved using"
			"the function :py:meth:`pmeshlab.MeshSet.save_current_mesh`, "
			"with all the possible parameters that can be accepted by these "
			"functions.\n\n";

	for (const Function& f : functionSet.saveMeshFunctionIterator()) {
		doc += filterRSTDocumentation(f, true);
	}

	//load raster parameters

	doc +=
			".. _load_raster_parameters:\n\n"
			"load raster parameters\n----------------------\n\n"
			"Here are listed all the raster file formats that can be loaded using"
			"the functions :py:meth:`pmeshlab.MeshSet.load_new_raster`.\n\n";

	for (const Function& f : functionSet.loadRasterFunctionIterator()) {
		doc += filterRSTDocumentation(f, true);
	}

	return doc;
}
