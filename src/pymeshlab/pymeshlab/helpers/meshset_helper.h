/*****************************************************************************
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
#ifndef PYMESHLAB_MESHSET_HELPER_H
#define PYMESHLAB_MESHSET_HELPER_H

#include <QAction>
#include <QString>
#include <string>

#include "verbosity_manager.h"

class RichParameterList;
class RichParameter;
class MeshDocument;
class MeshModel;
class RasterModel;
class FilterPlugin;
class FilterScript;
class QGLWidget;

namespace pybind11 {
class kwargs;
class dict;
class handle;
} // namespace pybind11

namespace pymeshlab {

class Function;
class FunctionSet;
class MeshSet;

namespace meshsethelper {

/** RichParameterList Management **/

void updateRichParameterList(
	const std::string&       filtername,
	const RichParameterList& base,
	RichParameterList&       toUpdate);

void updateRichParameterListFromKwargs(
	const Function&         f,
	const pybind11::kwargs& kwargs,
	const MeshDocument*     md,
	RichParameterList&      rps,
	bool                    ignoreFileName = false);

pybind11::dict pydictFromRichParameterList(const RichParameterList& rps);

/** QVariant map management **/

pybind11::dict toPyDict(const std::map<std::string, QVariant>& qVariantMap);

/** Filter name management **/

FilterPlugin* pluginFromFilterName(const QString& filterName, QAction*& action);

bool pythonFilterNameExists(const std::string& filtername, const FunctionSet& filterFunctionSet);

/** Load/Save Mesh **/

void loadMeshUsingPlugin(
	const std::string& filename,
	pybind11::kwargs   kwargs,
	MeshDocument&      md,
	VerbosityManager&  verbose,
	const FunctionSet& filterFunctionSet);

void loadRasterUsingPlugin(const std::string& filename, MeshDocument& md);

int currentMeshIOCapabilityMask(const MeshModel* mm);
int computeSaveSettingsMaskFromKwargs(
	pybind11::kwargs kwargs,
	int              startingMask,
	int              capabilityMask);

void saveMeshUsingPlugin(
	std::string filename,
	MeshModel*         mm,
	bool               saveTextures,
	int                qualityTextures,
	pybind11::kwargs   kwargs,
	MeshDocument&      md,
	VerbosityManager&  verbose,
	const FunctionSet& filterFunctionSet);

/** Apply Filter **/

pybind11::dict applyFilterRPL(
	const std::string&       filtername,
	const QString&           meshlabFilterName,
	QAction*                 action,
	FilterPlugin*            fp,
	const RichParameterList& rpl,
	VerbosityManager&        verbose,
	FilterScript&            filterScript,
	bool                     updateFilterScript,
	MeshSet&                 md);

} // namespace meshsethelper
} // namespace pymeshlab

#endif // PYMESHLAB_MESHSET_HELPER_H
