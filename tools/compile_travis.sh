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
        BUILD_FOR=OSX
	elif uname -s | grep -i Linux &> /dev/null; then
		TRAVIS_OS_NAME=linux
        BUILD_FOR=Linux
		if [ "${CCX:-}" == "" ]; then
			# default to g++
			export CXX=g++
		fi
	else
		echo "Failed to guess OS"; exit 1
	fi
fi

if [ "${BUILD_FOR:-}" == "" ]; then
    BUILD_FOR=unknown
fi

EXTRA=""
if [ "${BUILD_FOR:-}" == "Linux" ]; then
	EXTRA="-Wno-unused-result" # Supress warnings
fi

mkdir -p build
echo "OS Detected: ${TRAVIS_OS_NAME}"
ALL_MODULES=`ls src/modules/*.cpp`
OUTPUT_FILE="build/OperCooked_${BUILD_FOR}"

echo "[${TRAVIS_OS_NAME}_${BUILD_FOR}] Building..."
echo "[${TRAVIS_OS_NAME}_${BUILD_FOR}] Executing: ${CXX} src/main.cpp ${ALL_MODULES} -o ${OUTPUT_FILE} -O1 -s"
$CXX src/main.cpp $ALL_MODULES -o $OUTPUT_FILE $EXTRA -O2 -s
echo "[${TRAVIS_OS_NAME}_${BUILD_FOR}] Hashing File for verifcation..."
sha256sum $OUTPUT_FILE
echo "[${TRAVIS_OS_NAME}_${BUILD_FOR}] Artifact build!"
