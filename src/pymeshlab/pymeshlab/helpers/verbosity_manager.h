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
	static void disableVersbosity();
	static void enableVerbosity();
	
	static bool filterCallBack(const int pos, const char* str);
	static GLLogStream* staticLogger;
private:
	VerbosityManager();
	static CoutRedirect* coutRed;
	static CerrRedirect* cerrRed;
	static QDebugRedirect* qdebRed;
};

} //namespace pymeshlab

#endif // PYMESHLAB_VERBOSITYMANAGER_H
