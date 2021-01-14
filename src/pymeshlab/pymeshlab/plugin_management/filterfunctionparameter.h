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
#ifndef PYMESHLAB_FILTERFUNCTIONPARAMETER_H
#define PYMESHLAB_FILTERFUNCTIONPARAMETER_H

#include <QString>

class Value;
class RichParameter;

namespace pymeshlab {

class FilterFunctionParameter
{
public:
	FilterFunctionParameter(
			const QString& pName,
			const RichParameter& parameter);
	FilterFunctionParameter(const FilterFunctionParameter& oth);
	FilterFunctionParameter(FilterFunctionParameter&& oth);
	virtual ~FilterFunctionParameter();
	QString pythonName() const;
	QString meshlabName() const;
	QString pythonTypeString() const;
	QString meshlabTypeString() const;
	QString description() const;
	QString longDescription() const;
	const Value& defaultValue() const;
	const RichParameter& richParameter() const;
	void printDefaultValue(std::ostream& o) const;
	QString defaultValueString() const;

	FilterFunctionParameter& operator=(FilterFunctionParameter oth);
	bool operator< (const FilterFunctionParameter& oth) const;
	bool operator==(const FilterFunctionParameter& oth) const;
	void swap(FilterFunctionParameter& oth);
private:
	QString computePythonTypeString(const RichParameter& par);
	QString pName;
	QString pType;
	RichParameter* parameter;
};

}

#endif // PYMESHLAB_FILTERFUNCTIONPARAMETER_H
