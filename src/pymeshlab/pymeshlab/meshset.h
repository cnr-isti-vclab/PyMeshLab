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
#ifndef PYMESHLAB_MESHSET_H
#define PYMESHLAB_MESHSET_H

#include <pybind11/pybind11.h>
#include <common/ml_document/mesh_document.h>
#include <common/filterscript.h>
#include <common/plugins/plugin_manager.h>
#include <common/python/function_set.h>

#include "helpers/verbosity_manager.h"

namespace pymeshlab {

/**
 * @brief The MeshSet class
 * 
 * The MeshSet class is a container or Meshes and Rasters that represents a
 * "MeshLab session". It inherits from the class MeshDocument, and implements
 * a set of member functions that can be directly binded in python.
 * 
 * In addition to the members of the MeshDocument, the MeshSet contains:
 * - a reference to a PluginManager, which is managed within a singleton;
 * - a filterFunctionSet, an object containing all the bindings between
 *   meshlab filter names (with their parameters) and their relative python names;
 * - a filterScript, equivalent of the filter script of meshlab, that stores 
 *   the history of applied filters in the meshset.
 */
class MeshSet : public MeshDocument
{
public:
	/** Member functions binded on Python **/
	MeshSet(bool verbose = false);
	virtual ~MeshSet();

	void setVerbosity(bool verbose);
	void setParameterVerbosity(bool verbose);

	MeshModel& currentMesh();
	int currentMeshId() const;

	bool meshIdExists(int id) const;
	MeshModel& mesh(int id);

	void setCurrentMeshVisibility(bool visibility);
	void setMeshVisibility(int id, bool visibility);
	bool isCurrentMeshVisible() const;
	bool isMeshVisible(int id) const;

	void printFilterScript() const;

	void loadNewMesh(const std::string& filename, pybind11::kwargs kwargs = pybind11::kwargs());
	void saveCurrentMesh(const std::string& filename, bool saveTextures, int qualityTextures, pybind11::kwargs kwargs = pybind11::kwargs());
	void addMesh(const MeshModel& mesh, std::string name = "", bool setAsCurrent = true);
	
	void loadNewRaster(const std::string& filename);

	void loadProject(const pybind11::object& filenames);
	void saveProject(const std::string& filename);

	void loadFilterScript(const std::string& filename);
	void saveFilterScript(const std::string& filename) const;
	void clearFilterScript();
	void applyFilterScript();

	pybind11::dict applyFilter(
			const std::string& filtername,
			pybind11::kwargs kwargs = pybind11::kwargs());

	void printStatus() const;
	
	pybind11::dict filterParameterValues(
			const std::string& filtername,
			pybind11::kwargs kwargs = pybind11::kwargs());

private:
	PluginManager& pm;
	FunctionSet& functionSet;
	FilterScript filterScript;
	VerbosityManager verbosityManager;
};

}

#endif // PYMESHLAB_MESHSET_H
