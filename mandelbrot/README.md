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

If you are using _icc_ you have to replace _clang++_ with _icc_ **AND** you have to append the _-O1_ option to the above listed commands. The _-O1_ option disables some speed optimizations of the compiler. Without that option in our tests the results obtained with the SIMD implementation are different with respect to the ones obtained with the scalar implementation (even though the resulting pictures are very similar and very nice).    

You can find a more sophisticated version of this example in the repository of the [Vc library](http://code.compeng.uni-frankfurt.de/projects/vc). 
