# L6 and L7
Material from lectures 6 and 7 rewritten in C++. 
Calculating an integral using the trapezoidal rule.
Link to youtube video: 
- [L6](https://youtu.be/HHKYdce0vZI)
- [L7](https://youtu.be/GZdtYKbBq_k)

There are three different versions
- Version 1 (`v1`) passes the result to each thread using a points
- Version 2 (`v2`) uses a reduction clause
- Version 3 (`v3`) uses a parallel for loop

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
./build/trapezoidal_v1 <num_threads>
```
for example
```
./build/trapezoida_v1_ 2
Compiled with OpenMP and using 2 threads
The area under the curve of (1 + six(x)) between 0 and PI is 5.14143
```
