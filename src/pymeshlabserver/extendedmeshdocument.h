#ifndef PYMESHLAB_EXTENDEDMESHDOCUMENT_H
#define PYMESHLAB_EXTENDEDMESHDOCUMENT_H

#include <pybind11/pybind11.h>
#include <meshmodel.h>
#include <pluginmanager.h>


namespace pymeshlab {

class ExtendedMeshDocument : public MeshDocument
{
public:
	ExtendedMeshDocument();

	void loadMesh(const std::string& filename, pybind11::kwargs kwargs);
	void saveMesh(const std::string& filename, pybind11::kwargs kwargs);

private:

	void updateRichParameterSet(const pybind11::kwargs& kwargs, RichParameterSet& rps);

	std::string basePath;
	RichParameterSet globalRPS;
	PluginManager pm;
};

}

#endif // PYMESHLAB_EXTENDEDMESHDOCUMENT_H
