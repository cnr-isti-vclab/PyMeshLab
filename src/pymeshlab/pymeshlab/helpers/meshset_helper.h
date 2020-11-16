#ifndef PYMESHLAB_MESHSET_HELPER_H
#define PYMESHLAB_MESHSET_HELPER_H

#include <string>
#include <QString>
#include <QAction>

class RichParameterList;
class MeshDocument;
class FilterPluginInterface;
class FilterScript;

namespace pybind11 {
class kwargs;
class dict;
}

namespace pymeshlab {

class FilterFunction;
class FilterFunctionSet;

namespace meshSetHelper {

/** RichParameterList Management **/

void updateRichParameterList(
		const std::string& filtername,
		const RichParameterList& base,
		RichParameterList& toUpdate);

void updateRichParameterList(
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
