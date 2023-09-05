#!/bin/bash

cd ~/Documents/projects/math-expression-parser/
cd src
cmake -S . -B ../build
cd ..
cd build
make
cd ..
