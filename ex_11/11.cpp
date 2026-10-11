#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Matrix<float> u({
        {1., -1.},
        {-1., 1.}
    });
    std::cout << u.determinant() << std::endl; // 0.0

    u = Matrix<float>({
        {2., 0., 0.},
        {0., 2., 0.},
        {0., 0., 2.}
    });
    std::cout << u.determinant() << std::endl; // 8.0

    u = Matrix<float>({
        {8., 5., -2.},
        {4., 7, 20.},
        {7., 6., 1.}
    });
    std::cout << u.determinant() << std::endl; // -174.0

    u = Matrix<float>({
        {8., 5., -2., 4.},
        {4., 2.5, 20., 4.},
        {8., 5., 1., 4.},
        {28., -4., 17., 1.}
    });
    std::cout << u.determinant() << std::endl; // 1032.0

    return 0;
}
