#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Matrix<float> u({
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}
    });
    u.row_echelon().print();
    // [1.0, 0.0, 0.0]
    // [0.0, 1.0, 0.0]
    // [0.0, 0.0, 1.0]

    u = Matrix<float>({
        {1., 2.},
        {3., 4.}
    });
    u.row_echelon().print();
    //[1.0, 2.0]
    //[0.0, 0.0]

    u = Matrix<float>({
        {8., 5., -2., 4., 28.},
        {4., 2.5, 20., 4., -4.},
        {8., 5., 1., 4., 17.}
    });
    u.row_echelon().print();

    return 0;
}
