# L4
Material from lecture 4 re-written in C++. Printing hello world.
Link to youtube video: https://youtu.be/40qxXGdEq0g


## Compiling

Compile with OpenMP
```
cmake -S . -B build -DUSE_OPENMP=1
cmake --build build
```
Compile without OpenMP
```
cmake -S . -B build -DUSE_OPENMP=0
cmake --build build
```
or just 
```
cmake -S . -B build
cmake --build build
```

## Running
```
./build/hello <num_threads>
```
for example
```
./build/hello 2
Hello from thread 0 of 2
Hello from thread 1 of 2
```
