#!/bin/bash
set -e

BUILD_DIR=build
mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja
