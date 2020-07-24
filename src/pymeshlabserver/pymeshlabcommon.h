#ifndef PYMESHLAB_PYMESHLABCOMMON_H
#define PYMESHLAB_PYMESHLABCOMMON_H

#include <string>
#include <iostream>
#include <sstream>
#include <QtMessageHandler>

namespace pymeshlab {

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

std::string getRootAbsolutePath();

}

#endif // PYMESHLAB_PYMESHLABCOMMON_H
