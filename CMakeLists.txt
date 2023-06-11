cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(mesh2glb)

set(ASSIMP_WARNINGS_AS_ERRORS OFF CACHE BOOL "No werror")
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
    target_link_options(mesh2glb PUBLIC
        -lembind
        -sALLOW_MEMORY_GROWTH
    )

    install(FILES
        "$<TARGET_FILE_DIR:mesh2glb>/mesh2glb.js"
        "$<TARGET_FILE_DIR:mesh2glb>/mesh2glb.wasm"
        DESTINATION ${CMAKE_SOURCE_DIR}/dist
    )
endif ()
