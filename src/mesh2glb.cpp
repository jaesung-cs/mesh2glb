#include <mesh2glb.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <emscripten/bind.h>

using namespace emscripten;

int add(int x, int y) { return x + y; }

void mesh_to_glb(const std::vector<uint8_t>& memory) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFileFromMemory(
        memory.data(), memory.size(), aiProcess_Triangulate);

    // TODO
}

EMSCRIPTEN_BINDINGS(mesh2glb) {
    function("add", &add);
    function("meshToGlb", &mesh_to_glb);
}
