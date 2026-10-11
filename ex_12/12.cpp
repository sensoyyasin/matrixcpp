#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Matrix<float> u({
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}
    });
    u.inverse().print();

    u = Matrix<float>({
        {2., 0., 0.},
        {0., 2., 0.},
        {0., 0., 2.}
    });
    u.inverse().print();

    u = Matrix<float>({
        {8., 5., -2.},
        {4., 7, 20.},
        {7., 6., 1.}
    });
    u.inverse().print();

    return 0;
}
