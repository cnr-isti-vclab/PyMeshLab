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
#ifndef PYMESHLAB_NAMEBINDER_H
#define PYMESHLAB_NAMEBINDER_H

#include <common/plugin_manager.h>
#include "filterfunction.h"

namespace pymeshlab {

class FilterFunctionSet
{
public:
	FilterFunctionSet();
	void populate(const PluginManager& pm);

	QStringList pythonFunctionNames() const;

	using iterator = std::set<FilterFunction>::iterator;

	iterator begin() const {return functionSet.begin();}
	iterator end() const {return functionSet.end();}

	iterator find(const QString& pythonFunctionName) const;
	bool contains(const QString& pythonFunctionName) const;

	static QString toPythonName(const QString& name);

private:
	void addFunction(const FilterFunction& f);
	void deleteFunction(const FilterFunction& f);
	void updateSaveParameters(
			IOMeshPluginInterface* plugin,
			const QString& outputFormat,
			FilterFunction& f);
	std::set<FilterFunction> functionSet;
};

}

#endif // PYMESHLAB_NAMEBINDER_H
