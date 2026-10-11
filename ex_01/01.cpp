#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Vector<float> e1({1., 0., 0.});
    Vector<float> e2({0., 1., 0.});
    Vector<float> e3({0., 0., 1.});

    Vector<float> v1({1., 2., 3.});
    Vector<float> v2({0., 10., -100.});

    linear_combination<float>({e1, e2, e3}, {10., -2., 0.5}).print();
    // [10.0]
    // [-2.0]
    // [0.5]

    linear_combination<float>({v1, v2}, {10., -2.}).print();
    // [10.0]
    // [0.0]
    // [230.0]

    return 0;
}
