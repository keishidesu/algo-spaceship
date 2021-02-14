@echo off

set buildconf=%1
set buildall=0
set debug=

:: Make build file if not exists
if not exist build\NUL (
  echo Creating build directory...
  mkdir build
) else (
  echo Build directory exists!
)

if "%2" == "debug" (
  echo This is a debug build!
  set debug=-DBUILD_DEBUG
)
if "%buildconf%" == "generator" goto buildGenerator
if "%buildconf%" == "1" goto build1
if "%buildconf%" == "2" goto build2
if "%buildconf%" == "3" goto build3
goto buildAll

:: Generator
:buildGenerator
echo Building Generator executable...
g++ src/*.cpp -o build/generator.exe -DBUILD_GENERATOR %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue0
goto buildExit

:: Hash Table
:build1
echo Building Program 1 executable...
g++ src/*.cpp -o build/p1.exe -DBUILD_PROGRAM_1 %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue1
goto buildExit

:: Binary Tree
:build2
echo Building Program 2 executable...
g++ src/*.cpp -o build/p2.exe -DBUILD_PROGRAM_2 %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue2
goto buildExit

:: Priority Heap
:build3
echo Building Program 3 executable...
g++ src/*.cpp -o build/p3.exe -DBUILD_PROGRAM_3 %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue3
goto buildExit

:: Build Everything
:buildAll
set buildall=1
if "%buildconf%" == "debug" (
  echo This is a debug build for all!
  set debug=-DBUILD_DEBUG
)
echo Building all artifacts...
goto buildGenerator
:buildAllContinue0
goto build1
:buildAllContinue1
goto build2
:buildAllContinue2
goto build3
:buildAllContinue3
goto buildExit

:buildExit
if errorlevel 1 (
  echo Build Failure!
) else (
  echo Build Complete!
)
