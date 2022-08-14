# Quest Description

The developer said they have good test coverage and that our key was safe, but it seems that somehow our key leaked. Can you figure out how they managed to do this?


# The Dev's Build/Test Instructions

Windows:

```
cmake -G "Visual Studio 16 2019" -A Win32 -S . -B "build"
cmake --build build
./build/Debug/test_encryptedBuffer.exe [flag]
```

Linux:

```
cmake -S . -B build
cd build
make
./test_encryptedBuffer.exe [flag]
```