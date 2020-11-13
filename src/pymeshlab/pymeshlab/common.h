#ifndef PYMESHLAB_PYMESHLABCOMMON_H
#define PYMESHLAB_PYMESHLABCOMMON_H

#include <string>
#include <iostream>
#include <sstream>
#include <array>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <vcg/../wrap/io_trimesh/io_mask.h>
#include <QtMessageHandler>

#define PYMESHLAB_STRINGIFY(a) PYM_STR_TMP(a)
#define PYM_STR_TMP(a) #a

#define PYMESHLAB_MODULE_NAME pmeshlab
#define PYMESHLAB_MODULE_NAME_STR PYMESHLAB_STRINGIFY(PYMESHLAB_MODULE_NAME)

namespace pybind11 {
class dict;
}

namespace pymeshlab {

const static std::array<int, 14> capabilitiesBits= {
	vcg::tri::io::Mask::IOM_VERTQUALITY,
	vcg::tri::io::Mask::IOM_VERTFLAGS,
	vcg::tri::io::Mask::IOM_VERTCOLOR,
	vcg::tri::io::Mask::IOM_VERTTEXCOORD,
	vcg::tri::io::Mask::IOM_VERTNORMAL,
	vcg::tri::io::Mask::IOM_VERTRADIUS,
	vcg::tri::io::Mask::IOM_FACEQUALITY,
	vcg::tri::io::Mask::IOM_FACEFLAGS,
	vcg::tri::io::Mask::IOM_FACECOLOR,
	vcg::tri::io::Mask::IOM_FACENORMAL,
	vcg::tri::io::Mask::IOM_WEDGCOLOR,
	vcg::tri::io::Mask::IOM_WEDGTEXCOORD,
	vcg::tri::io::Mask::IOM_WEDGNORMAL,
	vcg::tri::io::Mask::IOM_BITPOLYGONAL
};

const static std::array<QString, 14> saveCapabilitiesStrings = {
	"Save Vertex Quality",
	"Save Vertex Flag",
	"Save Vertex Color",
	"Save Vertex Coord",
	"Save Vertex Normal",
	"Save Vertex Radius",
	"Save Face Quality",
	"Save Face Flag",
	"Save Face Color",
	"Save Face Normal",
	"Save Wedge Color",
	"Save Wedge TexCoord",
	"Save Wedge Normal",
	"Save Polygonal"
};

const char PYTHON_TYPE_ENUM[] = "str";
const char PYTHON_TYPE_ABSPERC[] = "Percentage";
const char PYTHON_TYPE_DYNAMIC_FLOAT[] = "float (bounded)";
const char PYTHON_TYPE_BOOL[] = "bool";
const char PYTHON_TYPE_INT[] = "int";
const char PYTHON_TYPE_FLOAT[] = "float";
const char PYTHON_TYPE_STRING[] = "str";
const char PYTHON_TYPE_MATRIX44F[] = "numpy.ndarray[numpy.float32[4, 4]]";
const char PYTHON_TYPE_POINT3F[] = "numpy.ndarray[numpy.float32[3]]";
const char PYTHON_TYPE_SHOTF[] = "Shotf [still unsupported]";
const char PYTHON_TYPE_COLOR[] = "Color";
const char PYTHON_TYPE_MESH[] = "int";
const char PYTHON_TYPE_FILENAME[] = "str";

const char MESHLAB_TYPE_ENUM[] = "RichEnum";
const char MESHLAB_TYPE_ABSPERC[] = "RichAbsPerc";
const char MESHLAB_TYPE_DYNAMIC_FLOAT[] = "RichDynamicFloat";
const char MESHLAB_TYPE_BOOL[] = "RichBool";
const char MESHLAB_TYPE_INT[] = "RichInt";
const char MESHLAB_TYPE_FLOAT[] = "RichFloat";
const char MESHLAB_TYPE_STRING[] = "RichString";
const char MESHLAB_TYPE_MATRIX44F[] = "RichMatrix44f";
const char MESHLAB_TYPE_POINT3F[] = "RichPoint3f";
const char MESHLAB_TYPE_SHOTF[] = "RichShotf";
const char MESHLAB_TYPE_COLOR[] = "RichColor";
const char MESHLAB_TYPE_MESH[] = "RichMesh";
const char MESHLAB_TYPE_OPENFILE[] = "RichOpenFile";
const char MESHLAB_TYPE_SAVEFILE[] = "RichSaveFile";

const static QStringList pythonKeywords = {
	"False", "await", "else", "import", "pass",
	"None", "break", "except", "in", "raise",
	"True", "class", "finally", "is", "return",
	"and", "continue", "for", "lambda", "try",
	"as", "def	from", "nonlocal", "while",
	"assert", "del", "global", "not", "with",
	"async", "elif", "if", "or", "yield"
};

/**
 * @brief The CoutRedirect class
 * Will redirect the cout buffer in the scope that is declared an instance this class.
 */
class CoutRedirect {
public:
	CoutRedirect(std::streambuf& new_buffer = *buffer.rdbuf())
		: old(std::cout.rdbuf(&new_buffer)) {}
	~CoutRedirect() {
		std::cout.rdbuf(old);
	}
private:
	static std::stringstream buffer;
	std::streambuf* old;
};

/**
 * @brief The CerrRedirect class
 * Will redirect the cout buffer in the scope that is declared an instance this class.
 */
class CerrRedirect {
public:
	CerrRedirect(std::streambuf& new_buffer = *buffer.rdbuf())
		: old(std::cerr.rdbuf(&new_buffer)) {}
	~CerrRedirect() {
		std::cerr.rdbuf(old);
	}
private:
	static std::stringstream buffer;
	std::streambuf* old;
};

/**
 * @brief The QDebugRedirect class
 * Will redirect the cout buffer in the scope that is declared an instance this class.
 */
class QDebugRedirect {
public:
	QDebugRedirect()
		: old(qInstallMessageHandler(myMessageOutput)) {}
	~QDebugRedirect() {
		qInstallMessageHandler(old);
	}
private:
	static void myMessageOutput(QtMsgType, const QMessageLogContext &, const QString &){}
	QtMessageHandler old;
};

/** Utilities **/
std::string getRootPath();
std::string getPluginsPath();
std::string getSamplesPath();

void printVersion();

pybind11::dict toPyDict(const std::map<std::string, QVariant>& qVariantMap);

}

#endif // PYMESHLAB_PYMESHLABCOMMON_H
