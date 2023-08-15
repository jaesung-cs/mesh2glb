#include <mesh2glb.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Exporter.hpp>

std::string mesh_to_glb(const std::string& memory) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFileFromMemory(
        memory.data(), memory.size(), aiProcess_Triangulate);

    Assimp::Exporter exporter;
    const aiExportDataBlob* blob = exporter.ExportToBlob(scene, "glb2");

    const auto* data = static_cast<uint8_t*>(blob->data);
    return std::string(data, data + blob->size);
}
