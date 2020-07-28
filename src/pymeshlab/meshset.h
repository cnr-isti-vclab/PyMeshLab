#ifndef PYMESHLAB_MESHSET_H
#define PYMESHLAB_MESHSET_H

#include <pybind11/pybind11.h>
#include <meshmodel.h>
#include <pluginmanager.h>
#include "filterfunctionset.h"


namespace pymeshlab {

class MeshSet : public MeshDocument
{
public:
	MeshSet();
	virtual ~MeshSet();

	void loadMesh(const std::string& filename, pybind11::kwargs kwargs);
	void saveMesh(const std::string& filename, pybind11::kwargs kwargs);

	void printPythonFilterNamesList() const;
	void printPythonFilterParameterList(const std::string functionName) const;

	void applyFilter(const std::string& filtername, pybind11::kwargs kwargs);

private:

	void updateRichParameterSet(const pybind11::kwargs& kwargs, RichParameterSet& rps);
	MeshFilterInterface* getPluginFromFilterName(const QString& filterName, QAction* action) const;

	std::string basePath;
	RichParameterSet globalRPS;
	PluginManager pm;
	FilterFunctionSet filterFunctionSet;
};

}

#endif // PYMESHLAB_MESHSET_H
