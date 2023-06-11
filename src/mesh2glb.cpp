#include <mesh2glb.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Exporter.hpp>

std::vector<uint8_t> mesh_to_glb(const std::vector<uint8_t>& memory) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFileFromMemory(
        memory.data(), memory.size(), aiProcess_Triangulate);

    Assimp::Exporter exporter;
    const aiExportDataBlob* blob = exporter.ExportToBlob(scene, "glb2");

    const auto* data = static_cast<uint8_t*>(blob->data);
    return std::vector<uint8_t>(data, data + blob->size);
}
