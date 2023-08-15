#include <mesh2glb.h>

#include <emscripten/bind.h>

namespace {

auto meshToGlb(const std::string& data) {
    auto result = mesh_to_glb(data);

    return emscripten::val(emscripten::typed_memory_view<uint8_t>(
        result.size(), reinterpret_cast<uint8_t*>(result.data())));
}

}  // namespace

EMSCRIPTEN_BINDINGS(mesh2glb) { emscripten::function("meshToGlb", &meshToGlb); }
