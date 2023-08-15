cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(mesh2glb)

# ASSIMP options from https://github.com/kovacsv/assimpjs/blob/main/CMakeLists.txt
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "")
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "")
set(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF CACHE BOOL "")
set(ASSIMP_BUILD_ASSJSON_EXPORTER ON CACHE BOOL "")
set(ASSIMP_BUILD_GLTF_EXPORTER ON CACHE BOOL "")
# undefined behaviour because of alignment issues, crashes and memory leaks
# https://github.com/assimp/assimp/pull/4044
set(ASSIMP_BUILD_M3D_IMPORTER OFF CACHE BOOL "")
# assertion failed because of a memory error
set(ASSIMP_BUILD_RAW_IMPORTER OFF CACHE BOOL "")
# removed from assimp, so doesn't need to compile at all
# https://github.com/assimp/assimp/issues/3647
set(ASSIMP_BUILD_X3D_IMPORTER OFF CACHE BOOL "")
# doesn't work because of xml parsing error
set(ASSIMP_BUILD_IRR_IMPORTER OFF CACHE BOOL "")
set(ASSIMP_BUILD_IRRMESH_IMPORTER OFF CACHE BOOL "")
# doesn't work
set(ASSIMP_BUILD_TERRAGEN_IMPORTER OFF CACHE BOOL "")
# this dramatically decreases the wasm file size
set(ASSIMP_BUILD_IFC_IMPORTER OFF CACHE BOOL "")
# No warnings as errors, UNCOMMENT IF emscripten build reports lots of warnings.
#set(ASSIMP_WARNINGS_AS_ERRORS OFF CACHE BOOL "No werror")
add_subdirectory(third_party/assimp EXCLUDE_FROM_ALL)

set(MESH2GLB_SOURCES
    src/mesh2glb.cpp
)

if (EMSCRIPTEN)
    list(APPEND MESH2GLB_SOURCES src/bind.cpp)
endif ()

add_executable(mesh2glb ${MESH2GLB_SOURCES})

target_include_directories(mesh2glb PUBLIC include/)

target_link_libraries(mesh2glb PRIVATE assimp)

if (EMSCRIPTEN)
    target_compile_options(mesh2glb PUBLIC
        -O3
    )

    target_link_options(mesh2glb PUBLIC
        -lembind
        -sMODULARIZE -sEXPORT_NAME="Mesh2Glb" -sEXPORT_ES6
        -sASSERTIONS=0  # No assertions
        -sALLOW_MEMORY_GROWTH
        -O3
    )

    install(FILES
        "$<TARGET_FILE_DIR:mesh2glb>/mesh2glb.js"
        "$<TARGET_FILE_DIR:mesh2glb>/mesh2glb.wasm"
        DESTINATION ${CMAKE_SOURCE_DIR}/dist
    )
endif ()
