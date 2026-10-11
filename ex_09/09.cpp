#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Matrix<float> u({
        {1., 0.},
        {0., 1.},
    });
    u.transpose().print();
    // [1.0, 0.0]
    // [0.0, 1.0]

    u = Matrix<float>({
        {2., -5., 0.},
        {4., 3., 7.},
        {-2., 3., 4.}
    });
    u.transpose().print();
    //[2.0, 4.0, -2.0]
    //[-5.0, 3.0, 3.0]
    //[0.0, 7.0, 4.0]

    u = Matrix<float>({
        {-2., -8., 4.},
        {1., -23., 4.},
        {0., 6., 4.}
    });
    u.transpose().print();
    // [-2.0, 1.0, 0.0]
    // [-8.0, -23.0, 6.0]
    // [4.0, 4.0, 4.0]

    return 0;
}
