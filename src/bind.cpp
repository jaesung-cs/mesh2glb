#include <mesh2glb.h>

#include <emscripten/bind.h>

namespace {

int add(int x, int y) { return x + y; }

auto meshToGlb(std::string data) {
    std::vector<uint8_t> memory(data.begin(), data.end());

    auto result = mesh_to_glb(memory);

    return emscripten::val(
        emscripten::typed_memory_view(result.size(), result.data()));
}

}  // namespace

EMSCRIPTEN_BINDINGS(mesh2glb) {
    emscripten::function("add", &add);
    emscripten::function("meshToGlb", &meshToGlb);
}
