#/usr/bin/env bash

emcmake cmake . -B embuild
cmake --build embuild --config Release -j
cmake --install embuild --config Release
