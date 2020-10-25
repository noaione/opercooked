#!/bin/bash
ALL_MODULES=`ls src/modules/*.cpp`
echo Building...
g++ src/main.cpp $ALL_MODULES -o OperCooked_Linux -O1 -s