# mesh2glb
Mesh to glb converter

## Install
```console
$ git submodule update --init --recursive
$ ./third_party/emsdk/emsdk install latest
$ ./third_party/emsdk/emsdk activate latest
$ source ./third_party/emsdk/emsdk_env.sh
```

## Build
- c++ Library
    ```console
    $ cmake . -B build
    $ cmake --build build --config Release -j
    ```
- Emscripten
    ```console
    $ emcmake cmake . -B embuild
    $ cmake --build embuild --config Release -j
    ```
