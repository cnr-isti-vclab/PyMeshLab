#ifndef PYMESHLAB_MESHSET_H
#define PYMESHLAB_MESHSET_H

#include <pybind11/pybind11.h>
#include <meshmodel.h>
#include <filterscript.h>
#include <pluginmanager.h>
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

	void loadMesh(const std::string& filename, pybind11::kwargs kwargs = pybind11::kwargs());
	void saveMesh(const std::string& filename, pybind11::kwargs kwargs = pybind11::kwargs());
	void addMesh(CMeshO& mesh, const std::string& name = "new_mesh", bool setAsCurrent = true);

	void loadProject(const std::string& filename);
	void saveProject(const std::string& filename);

	void loadFilterScript(const std::string& filename);
	void saveFilterScript(const std::string& filename) const;
	void clearFilterScript();
	void applyFilterScript();

	void applyFilter(
			const std::string& filtername,
			pybind11::kwargs kwargs = pybind11::kwargs());

	void printStatus() const;

	/** Member functions not binded on Python **/
	std::string filtersRSTDocumentation() const;
private:
	static GLLogStream* staticLogger;

	static bool filterCallBack(const int pos, const char* str);

	void updateRichParameterList(
			const std::string& filtername,
			const RichParameterList& base,
			RichParameterList& toUpdate);

	void updateRichParameterList(
			const FilterFunction& f,
			const pybind11::kwargs& kwargs,
			RichParameterList& rps,
			bool ignoreFileName = false);

	FilterPluginInterface* getPluginFromFilterName(
			const QString& filterName,
			QAction*& action) const;

	void loadMeshUsingPlugin(
			const std::string& filename,
			MeshModel* mm = nullptr,
			FilterFunction ff = FilterFunction(),
			pybind11::kwargs kwargs = pybind11::kwargs());

	void saveMeshUsingPlugin(
			const std::string& filename,
			MeshModel* mm = nullptr,
			FilterFunction ff = FilterFunction(),
			pybind11::kwargs kwargs = pybind11::kwargs());

	int currentMeshIOCapabilityMask(const MeshModel* mm) const;
	int capabilityMaskFromKwargs(pybind11::kwargs kwargs, int startingMask) const;

	void loadALN(const QString& fileName);
	void loadMLP(const QString& fileName);
	void loadBundler(const QString& fileName);
	void loadNVM(const QString& fileName);

	void saveMLP(const QString& fileName);

	void updateRichParameterFromKwarg(
			RichParameter& par,
			const FilterFunctionParameter& ffp,
			const std::pair<pybind11::handle, pybind11::handle>& k);

	void applyFilterRPL(
			const std::string& filtername,
			QString meshlabFilterName,
			QAction* action,
			FilterPluginInterface* filter,
			const RichParameterList& rpl);

	std::string filterRSTDocumentation(FilterFunctionSet::iterator it) const;
	static void cleanHTML(QString& htmlString);

	PluginManager& pm;
	FilterFunctionSet filterFunctionSet;
	FilterScript filterScript;

	bool verbose;
};

}

#endif // PYMESHLAB_MESHSET_H
