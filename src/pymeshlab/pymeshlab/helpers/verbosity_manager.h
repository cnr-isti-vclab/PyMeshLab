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
	
	void disableVersbosity();
	void enableVerbosity();
	
	static bool filterCallBack(const int pos, const char* str);
	static GLLogStream* staticLogger;
private:
	
	CoutRedirect* coutRed;
	CerrRedirect* cerrRed;
	QDebugRedirect* qdebRed;
};

} //namespace pymeshlab

#endif // PYMESHLAB_VERBOSITYMANAGER_H
