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

OUTPUT_FILE="build/OperCooked_${TRAVIS_BRANCH}_${TRAVIS_COMMIT}.tar.gz"

echo "Gunzipping..."
tar -czvf $OUTPUT_FILE build/
echo "Uploading to ihaCDN..."
curl -X POST -F "file=@${OUTPUT_FILE}" -F "secret=${IHATEANIME_APIKEY}" https://p.ihateani.me/upload
