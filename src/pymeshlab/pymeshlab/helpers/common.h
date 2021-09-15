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
#ifndef PYMESHLAB_PYMESHLABCOMMON_H
#define PYMESHLAB_PYMESHLABCOMMON_H

#include <QString>
#include <QStringList>
#include <QVariant>
#include <QtMessageHandler>
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vcg/../wrap/io_trimesh/io_mask.h>

#define PYMESHLAB_STRINGIFY(a) PYM_STR_TMP(a)
#define PYM_STR_TMP(a) #a

#define PYMESHLAB_MODULE_NAME pmeshlab
#define PYMESHLAB_MODULE_NAME_STR PYMESHLAB_STRINGIFY(PYMESHLAB_MODULE_NAME)

namespace pybind11 {
class dict;
}

namespace pymeshlab {

const char MESHLAB_TYPE_ENUM[]          = "RichEnum";
const char MESHLAB_TYPE_ABSPERC[]       = "RichAbsPerc";
const char MESHLAB_TYPE_DYNAMIC_FLOAT[] = "RichDynamicFloat";
const char MESHLAB_TYPE_BOOL[]          = "RichBool";
const char MESHLAB_TYPE_INT[]           = "RichInt";
const char MESHLAB_TYPE_FLOAT[]         = "RichFloat";
const char MESHLAB_TYPE_STRING[]        = "RichString";
const char MESHLAB_TYPE_MATRIX44F[]     = "RichMatrix44f";
const char MESHLAB_TYPE_POSITION[]      = "RichPosition";
const char MESHLAB_TYPE_DIRECTION[]     = "RichDirection";
const char MESHLAB_TYPE_SHOTF[]         = "RichShotf";
const char MESHLAB_TYPE_COLOR[]         = "RichColor";
const char MESHLAB_TYPE_MESH[]          = "RichMesh";
const char MESHLAB_TYPE_OPENFILE[]      = "RichOpenFile";
const char MESHLAB_TYPE_SAVEFILE[]      = "RichSaveFile";

const char PYMESHLAB_GLOBAL_SETTING_MAXGPUMEM[] = "MeshLab::System::maxGPUMemDedicatedToGeometry";

/**
 * @brief The CoutRedirect class
 * Will redirect the cout buffer in the scope that is declared an instance this class.
 */
class CoutRedirect
{
public:
	CoutRedirect(std::streambuf& new_buffer = *buffer.rdbuf()) : old(std::cout.rdbuf(&new_buffer))
	{
	}
	~CoutRedirect() { std::cout.rdbuf(old); }

private:
	static std::stringstream buffer;
	std::streambuf*          old;
};

/**
 * @brief The CerrRedirect class
 * Will redirect the cerr buffer in the scope that is declared an instance this class.
 */
class CerrRedirect
{
public:
	CerrRedirect(std::streambuf& new_buffer = *buffer.rdbuf()) : old(std::cerr.rdbuf(&new_buffer))
	{
	}
	~CerrRedirect() { std::cerr.rdbuf(old); }

private:
	static std::stringstream buffer;
	std::streambuf*          old;
};

/**
 * @brief The QDebugRedirect class
 * Will redirect the qdebug buffer in the scope that is declared an instance this class.
 */
class QDebugRedirect
{
public:
	QDebugRedirect() : old(qInstallMessageHandler(myMessageOutput)) {}
	~QDebugRedirect() { qInstallMessageHandler(old); }

private:
	static void      myMessageOutput(QtMsgType, const QMessageLogContext&, const QString&) {}
	QtMessageHandler old;
};

/** Utilities **/
std::string getRootPath();
std::string getPluginsPath();
std::string getSamplesPath();

std::string filterListRSTDocumentation();
std::string ioFormatListRSTDocumentation();

} // namespace pymeshlab

#endif // PYMESHLAB_PYMESHLABCOMMON_H
