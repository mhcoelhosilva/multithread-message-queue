# Multi-threaded Message Queue

The goal of this simple project is to showcase multi-threaded data processing using the C++ standard library. The plot below was produced on an 8-core CPU in a Release build, and shows maximum efficiency at 8 threads.

![Plot](./plot.png)

## Usage

To build using CMake and run:

```
cd ./build/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
make
./MMQ
```