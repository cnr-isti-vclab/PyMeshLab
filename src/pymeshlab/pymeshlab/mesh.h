#ifndef PYMESHLAB_MESH_H
#define PYMESHLAB_MESH_H

#include <ml_mesh_type.h>

namespace pymeshlab {

class Mesh
{
public:
	static void updateBBox(CMeshO& m);

private:
	Mesh();
};

}

#endif // PYMESHLAB_MESH_H
