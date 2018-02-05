#!/usr/bin/bash 

metashell --engine clang -- /usr/bin/clang++ -I "`pwd`/include" -std=c++1z
