#!/bin/bash

echo "Preparing to compile..."
if [ "${CXX_TOOLS:-}" != "" ]; then
    export CXX=${CXX_TOOLS}
    echo "Using: ${CXX}"
fi

if [ "${TRAVIS_OS_NAME:-}" == "" ]; then
	echo "Guessing OS"
	if uname -s | grep -i Darwin &> /dev/null; then
		TRAVIS_OS_NAME=osx
	elif uname -s | grep -i Linux &> /dev/null; then
		TRAVIS_OS_NAME=linux
		if [ "${CCX:-}" == "" ]; then
			# default to g++
			export CCX=g++
		fi
	else
		echo "Failed to guess OS"; exit 1
	fi
fi

echo "OS Detected: ${TRAVIS_OS_NAME}"
ALL_MODULES=`ls src/modules/*.cpp`
OUTPUT_FILE="OperCooked_${TRAVIS_OS_NAME}"

echo "[${TRAVIS_OS_NAME}] Building..."
echo "[${TRAVIS_OS_NAME}] Executing: ${CXX} src/main.cpp ${ALL_MODULES} -o ${OUTPUT_FILE} -O1 -s"
$CXX src/main.cpp $ALL_MODULES -o $OUTPUT_FILE -O1 -s
echo "[${TRAVIS_OS_NAME}] Artifact build!"
