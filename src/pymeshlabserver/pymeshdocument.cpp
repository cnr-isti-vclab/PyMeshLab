#include "pymeshdocument.h"

#include "pymeshlabcommon.h"
#include "extendedmeshdocument.h"
#include <vcg/../wrap/io_trimesh/import_obj.h>
#include <pybind11/eval.h>

namespace py = pybind11;

CMeshO& currentMesh(pymeshlab::ExtendedMeshDocument& m)
{
	return m.mm()->cm;
}

//std::vector<QString> loadFunctionNamesFromPlugins(PluginManager& pm)
//{
//	std::vector<QString> functionNames;

//	for (MeshIOInterface* ioplug : pm.meshIOPlug){
//		for (MeshIOInterface::Format f: ioplug->importFormats()) {
//			for (QString ext : f.extensions){
//				functionNames.push_back("load_" + ext.toLower());
//			}
//		}
//	}

//	return functionNames;
//}

//std::vector<QString> saveFunctionNamesFromPlugins(PluginManager& pm)
//{
//	std::vector<QString> functionNames;

//	for (MeshIOInterface* ioplug : pm.meshIOPlug){
//		for (MeshIOInterface::Format f: ioplug->exportFormats()){
//			for (QString ext : f.extensions){
//				functionNames.push_back("save_" + ext.toLower());
//			}
//		}
//	}

//	return functionNames;
//}

void pymeshlab::initMeshDocument(pybind11::module& m)
{
	py::class_<ExtendedMeshDocument> meshDocumentClass(m, "MeshDocument");

	//empty constructor
	meshDocumentClass.def(py::init());

	meshDocumentClass.def("number_meshes", &ExtendedMeshDocument::size);
	meshDocumentClass.def("set_current_mesh", &ExtendedMeshDocument::setCurrentMesh, py::arg("new_curr_id"));
	meshDocumentClass.def("current_mesh", &currentMesh, py::return_value_policy::reference);

	meshDocumentClass.def("load_mesh", &ExtendedMeshDocument::loadMesh, py::arg("filename"));

	meshDocumentClass.def("save_mesh", &ExtendedMeshDocument::saveMesh, py::arg("filename"));

//	QDir dir(QString::fromStdString(pymeshlab::getPluginsPath()));

//	pymeshlab::QDebugRedirect qdbr; //redirect qdebug to null, just for this scope
//	RichParameterSet tmprps;
//	PluginManager pm;
//	pm.loadPlugins(tmprps, dir);

//	std::vector<QString> fn = loadFunctionNamesFromPlugins(pm);
//	for (const QString functionName : fn) {
//		meshDocumentClass.def(functionName.toStdString().c_str(), &ExtendedMeshDocument::loadMesh, py::arg("filename"));
//	}
}
