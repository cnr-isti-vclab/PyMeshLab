#ifndef PYMESHLAB_NAMEBINDER_H
#define PYMESHLAB_NAMEBINDER_H

#include <pluginmanager.h>

namespace pymeshlab {

class NameBinder
{
public:
	NameBinder();
	void popolate(const PluginManager pm);

	QString toPythonName(const QString& name) const;

private:

};

}

#endif // PYMESHLAB_NAMEBINDER_H
