#ifndef PYMESHLAB_MESHSET_HELPER_H
#define PYMESHLAB_MESHSET_HELPER_H

#include <string>
#include <QString>
#include <QAction>

class RichParameterList;
class MeshDocument;
class MeshModel;
class FilterPluginInterface;
class FilterScript;

namespace pybind11 {
class kwargs;
class dict;
}

namespace pymeshlab {

class FilterFunction;
class FilterFunctionSet;

namespace meshsethelper {

/** RichParameterList Management **/

void updateRichParameterList(
		const std::string& filtername,
		const RichParameterList& base,
		RichParameterList& toUpdate);

void updateRichParameterListFromKwargs(
		const FilterFunction& f,
		const pybind11::kwargs& kwargs,
		MeshDocument* md,
		RichParameterList& rps,
		bool ignoreFileName = false);

/** Filter name management **/

FilterPluginInterface* pluginFromFilterName(
		const QString& filterName,
		QAction*& action);

bool pythonFilterNameExists(
		const std::string& filtername, 
		const FilterFunctionSet& filterFunctionSet);

/** Load/Save Mesh **/

void loadMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm,
		pybind11::kwargs kwargs, 
		MeshDocument& md, 
		const FilterFunctionSet& filterFunctionSet);

void saveMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm,
		pybind11::kwargs kwargs,
		MeshDocument& md,
		const FilterFunctionSet& filterFunctionSet);

/** Load/Save Project **/

void loadALN(
		const QString& fileName, 
		MeshDocument& md, 
		const FilterFunctionSet& filterFunctionSet);

void loadMLP(
		const QString& fileName,
		MeshDocument& md, 
		const FilterFunctionSet& filterFunctionSet);

void loadBundler(
		const QString& fileName,
		MeshDocument& md);

void loadNVM(
		const QString& fileName,
		MeshDocument& md);

void saveMLP(
		const QString& fileName,
		MeshDocument& md, 
		const FilterFunctionSet& filterFunctionSet);

/** Apply Filter **/

pybind11::dict applyFilterRPL(const std::string& filtername,
		const QString& meshlabFilterName,
		QAction* action,
		FilterPluginInterface* fp,
		const RichParameterList& rpl,
		bool verbose,
		FilterScript& filterScript,
		bool updateFilterScript,
		MeshDocument& md);

/** RST Documentation **/

std::string RSTDocumentationFromFilterFunctionSet(
		const FilterFunctionSet& filterFunctionSet);

} //namespace pymeshlab::meshset_helper
} //namespace pymeshlab


#endif // PYMESHLAB_MESHSET_HELPER_H
