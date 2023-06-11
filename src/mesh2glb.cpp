#include <mesh2glb.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

void mesh_to_glb(const std::vector<uint8_t>& memory) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFileFromMemory(
        memory.data(), memory.size(), aiProcess_Triangulate);

    // TODO
}
