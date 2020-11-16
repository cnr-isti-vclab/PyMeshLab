#ifndef PYMESHLAB_MESHSET_H
#define PYMESHLAB_MESHSET_H

#include <pybind11/pybind11.h>
#include <common/meshmodel.h>
#include <common/filterscript.h>
#include <common/pluginmanager.h>
#include "plugin_management/filterfunctionset.h"

namespace pymeshlab {

class MeshSet : public MeshDocument
{
public:
	/** Member functions binded on Python **/
	MeshSet(bool verbose = false);
	virtual ~MeshSet();

	void setVerbosity(bool verbose);

	CMeshO& currentMesh();
	int currentMeshId() const;

	bool meshIdExists(int id) const;
	CMeshO& mesh(int id);

	void printPluginList() const;
	void printPythonFilterNamesList() const;
	void printPythonFilterParameterList(const std::string functionName) const;
	void printFilterScript() const;

	void loadNewMesh(const std::string& filename, pybind11::kwargs kwargs = pybind11::kwargs());
	void loadCurrentMesh(const std::string& filename, pybind11::kwargs kwargs = pybind11::kwargs());
	void saveCurrentMesh(const std::string& filename, pybind11::kwargs kwargs = pybind11::kwargs());
	void addMesh(CMeshO& mesh, const std::string& name = "new_mesh", bool setAsCurrent = true);

	void loadProject(const std::string& filename);
	void saveProject(const std::string& filename);

	void loadFilterScript(const std::string& filename);
	void saveFilterScript(const std::string& filename) const;
	void clearFilterScript();
	void applyFilterScript();

	pybind11::dict applyFilter(
			const std::string& filtername,
			pybind11::kwargs kwargs = pybind11::kwargs());

	void printStatus() const;

	/** Member functions not binded on Python **/
	std::string filtersRSTDocumentation() const;
private:
	void loadALN(const QString& fileName);
	void loadMLP(const QString& fileName);
	void loadBundler(const QString& fileName);
	void loadNVM(const QString& fileName);

	void saveMLP(const QString& fileName);

	PluginManager& pm;
	FilterFunctionSet filterFunctionSet;
	FilterScript filterScript;

	bool verbose;
};

}

#endif // PYMESHLAB_MESHSET_H
