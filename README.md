# Vector Matrix library

A tiny, header-only linear algebra library in C++17, written from scratch with no math libraries.

## Features

| Vectors | Matrices |
|---|---|
| add, subtract, scale | add, subtract, scale |
| linear combination | matrix × vector, matrix × matrix |
| linear interpolation (lerp) | trace, transpose |
| dot product | row echelon form |
| norms (L1, L2, L∞) | determinant, inverse |
| cosine of angle | rank |
| cross product | perspective projection matrix |

All types are generic over the scalar type `K` (`Vector<K>`, `Matrix<K>`).

## Build

```bash
make              # build all exercises
make clean
```

Requires a C++17 compiler (g++ or clang++).


## Project structure

```
include/   Vector.hpp, Matrix.hpp
ex_00/     add, subtract, scale
...
ex_14/     projection matrix
```

## Performance notes

This library is written for clarity actually not for speed. Profiling it against reference implementations showed where the time goes:

- **Determinant and inverse** use cofactor expansion, which is O(n!). An 11×11 determinant takes ~10 s; Gaussian elimination (O(n³)) does it in ~0.003 ms.
- **Heap allocation in hot loops**: every `mul_vec` call allocates a new vector. Transforming 100k points is ~10× slower than reusing preallocated memory.
- **Pass-by-value**: `add(Matrix v)` copies the whole matrix on every call.
- **Nested `std::vector` storage** is cache-unfriendly; `mul_mat` is ~3× slower than a flat array.

For production code (SLAM, point clouds, edge devices), use a library like Eigen
