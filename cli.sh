#!/bin/bash
mkdir build

cd build
cmake ..

make

mv EchoChat ..

cp compile_commands.json ..

