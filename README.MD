# Algorithm Assignment 2

## Build

```bash
# this will build all
$ build

# build individual
$ build generator
$ build 1
$ build 2
$ build 3
```

## Debug Build

```bash
# this will build all with debug mode enabled
$ build debug

# build individual in debug mode
$ build generator debug
$ build 1 debug
$ build 2 debug
$ build 3 debug
```

## Manual Commands
Add `-DBUILD_DEBUG` on the end of each command to enable debug build.

```bash
# build individual
$ g++ src/*.cpp -o build/generator.exe -DBUILD_GENERATOR
$ g++ src/*.cpp -o build/p1.exe -DBUILD_PROGRAM_1
$ g++ src/*.cpp -o build/p2.exe -DBUILD_PROGRAM_2
$ g++ src/*.cpp -o build/p3.exe -DBUILD_PROGRAM_3
```
