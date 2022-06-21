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
#ifndef PYMESHLAB_VERBOSITYMANAGER_H
#define PYMESHLAB_VERBOSITYMANAGER_H

class GLLogStream;

namespace pymeshlab {

class CoutRedirect;
class CerrRedirect;
class QDebugRedirect;

class VerbosityManager
{
public:
	VerbosityManager();
	~VerbosityManager();

	void enableVerbosity();
	void disableVersbosity();
	void enableParameterVerbosity();
	void disableParameterVerbosity();
	bool isVerbosityEnabled() const;
	bool isParameterVerbosityEnabled() const;

	void startVerbosityManager();
	void endVerbosityManager();

	static bool         filterCallBack(const int pos, const char* str);
	static GLLogStream* staticLogger;

private:
	bool parameterVerbosity = false;
	bool verbose = false;

	CoutRedirect*   coutRed = nullptr;
	CerrRedirect*   cerrRed = nullptr;
	QDebugRedirect* qdebRed = nullptr;
};

} // namespace pymeshlab

#endif // PYMESHLAB_VERBOSITYMANAGER_H
