# L8
Material from lecture 8 re-written in C++. 
Calculating pi using a parallel for loop. 
Take-home message - we need to be careful with the sign, and we need to make the variable `sign` private to each thread.
Link to youtube video: https://youtu.be/AICtS0JIQNA


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
./build/estimate_pi <num_threads>
```
for example
```
./build/estimate_pi 7
Compiled with OpenMP and using 7 threads
Pi = 3.14149
```
