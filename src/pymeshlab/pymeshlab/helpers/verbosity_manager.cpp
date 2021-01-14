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
#include "verbosity_manager.h"

#include "common.h"
#include <common/GLLogStream.h>

namespace pymeshlab {

GLLogStream* VerbosityManager::staticLogger = nullptr;
CoutRedirect* VerbosityManager::coutRed = nullptr;
CerrRedirect* VerbosityManager::cerrRed = nullptr;
QDebugRedirect* VerbosityManager::qdebRed = nullptr;

VerbosityManager::VerbosityManager()
{
}

void VerbosityManager::disableVersbosity()
{
	coutRed = new CoutRedirect();
	cerrRed = new CerrRedirect();
	qdebRed = new QDebugRedirect();
}

void VerbosityManager::enableVerbosity()
{
	delete coutRed;
	delete cerrRed;
	delete qdebRed;
	coutRed = nullptr;
	cerrRed = nullptr;
	qdebRed = nullptr;
}

bool VerbosityManager::filterCallBack(const int pos, const char* str)
{
	int static lastPos=-1;
	if(pos==lastPos) return true;
	lastPos=pos;
	std::string s = std::string(str) + "    [ " + std::to_string(pos) +"% ]";
	if (staticLogger)
		staticLogger->Log(GLLogStream::FILTER, s);
	return true;
}

}
