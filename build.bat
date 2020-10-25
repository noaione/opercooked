@echo off
FOR /F "tokens=* USEBACKQ" %%F IN (`python _collect_files.py`) DO (
	SET CPP_FILES=%%F
)
echo Building...
g++ src/main.cpp %CPP_FILES% -o OperCooked_Windows -O1 -s