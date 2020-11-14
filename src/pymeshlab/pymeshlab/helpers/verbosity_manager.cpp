#include "verbosity_manager.h"

#include "common.h"
#include <common/GLLogStream.h>

namespace pymeshlab {

GLLogStream* VerbosityManager::staticLogger = nullptr;

VerbosityManager::VerbosityManager() :
	coutRed(nullptr),
	cerrRed(nullptr),
	qdebRed(nullptr)
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
