#include "mesh.h"

#include <vcg/../wrap/io_trimesh/import_obj.h>

void loadMesh(CMeshO& m, std::string filename){
	vcg::tri::io::ImporterOBJ<CMeshO>::Info oi;
	vcg::tri::io::ImporterOBJ<CMeshO>::Open(m, filename.c_str(), oi);
	vcg::tri::UpdateBounding<CMeshO>::Box(m);
}

void pymeshlab::Mesh::updateBBox(CMeshO& m)
{
	vcg::tri::UpdateBounding<CMeshO>::Box(m);
}

pymeshlab::Mesh::Mesh()
{
}
