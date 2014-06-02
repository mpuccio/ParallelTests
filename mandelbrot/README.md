Mandelbrot Set
=============

This is a simple code to generate a matrix representing the Mandelbrot set. 

It requires the Vc library for the matrix generation and ROOT for the visualization. 

How to build with clang:

```bash
clang++ -std=c++11 -lVc Complex.cpp -o Complex.o
```

If you want to check how much you earn from vectorizing your code, try to compile it forcing the scalar implementation of the Vc library (no SIMD):

```bash
clang++ -std=c++11 -lVc -DVC_IMPL=Scalar Complex.cpp -o Complex.o
```