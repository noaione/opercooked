#!/bin/bash

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
			export CCX=g++
		fi
	else
		echo "Failed to guess OS"; exit 1
	fi
fi

if [ "${BUILD_FOR:-}" == "" ]; then
    BUILD_FOR=unknown
fi

OUTPUT_FILE="build/OperCooked_${BUILD_FOR}_${TRAVIS_BRANCH}_${TRAVIS_COMMIT}"
OLD_OUTPUT_FILE="build/OperCooked_${BUILD_FOR}"
if [ "${BUILD_FOR:-}" == "Windows" ]; then
	OUTPUT_FILE="${OUTPUT_FILE}.exe"
	# OLD_OUTPUT_FILE="${OLD_OUTPUT_FILE}"
fi

echo "Reading build folder..."
ls build/

echo "Renaming File for Shard Upload..."
mv $OLD_OUTPUT_FILE $OUTPUT_FILE

echo "Uploading to ihaCDN..."
curl -X POST -F "file=@${OUTPUT_FILE}" -F "forceoriginal=1" -F "secret=${IHATEANIME_APIKEY}" https://p.ihateani.me/upload
