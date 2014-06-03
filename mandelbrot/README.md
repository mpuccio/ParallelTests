Mandelbrot Set
=============

This is a simple code to generate a matrix representing the Mandelbrot set. 

It requires the Vc library for the matrix generation and ROOT for the visualization. 

How to build with _clang_:

```bash
clang++ -o Complex.o Complex.cpp -lVc -std=c++11
```

If you want to check how much you earn from the vectorization of your code, try to compile it forcing the scalar implementation of the Vc library (no SIMD):

```bash
clang++ -o Complex.o Complex.cpp -lVc -std=c++11 -DVC_IMPL=Scalar
```

If you are using _gcc_ just replace in the commands above _clang++_ with _g++_.

You can find a more sophisticated version of this example in the repository of the [Vc library](http://code.compeng.uni-frankfurt.de/projects/vc). 