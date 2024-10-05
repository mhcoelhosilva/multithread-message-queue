# Multi-threaded Message Queue

The goal of this simple project is to showcase multi-threaded data processing using the C++ standard library. 

The MMQ1 implementation (in `./src/mmq.cpp`) uses an atomic bitmap to keep track of available threads, and deploys messages to those threads synchronously. The `AddMessage` call is therefore blocking whenever all threads are busy, but the data processing itself takes place asynchronously in the worker threads.

The MMQ 2 implementation (in `./src/mmq2.cpp`) uses a lock-free queue (in `./include/lock_free_queue.hpp`) to deploy messages to threads asynchronously. MMQ 2 is lockess and non-blocking throughout. This is reflected in MMQ 2's better performance with higher thread counts when compared to MMQ 1.

The plot below was produced on an 8-core CPU in a Release build, and shows maximum efficiency at around 8 threads.

![Plot](./plot.png)

## Usage

To build using CMake and run:

```
cd ./build/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
make
./MMQ
```