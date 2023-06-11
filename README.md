# mesh2glb
Mesh to glb converter

## Install
- Linux
    ```console
    $ git submodule update --init --recursive
    $ ./third_party/emsdk/emsdk install latest
    $ ./third_party/emsdk/emsdk activate latest
    $ source ./third_party/emsdk/emsdk_env.sh
    ```
- Windows
    ```powershell
    > git submodule update --init --recursive
    > ./third_party/emsdk/emsdk install latest
    > ./third_party/emsdk/emsdk activate latest
    > ./third_party/emsdk/emsdk install mingw-4.6.2-32bit
    > ./third_party/emsdk/emsdk activate mingw-4.6.2-32bit
    ```

## Build
- Library
    ```console
    $ cmake . -B build
    $ cmake --build build --config Release -j
    ```
- Emscripten Linux
    - TODO
- Emscripten Windows
    ```powershell
    > $env:EMSCRIPTEN = $env:EMSDK + "/upstream/emscripten"
    > emcmake cmake . -B embuild -G "Visual Studio 17 2022"
    > cmake --build embuild --config Release -j
    ```
