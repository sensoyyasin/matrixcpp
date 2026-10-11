#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Matrix<float> u({
        {1., 0.},
        {0., 1.},
    });
    std::cout << u.trace() << std::endl; // 2.0

    u = Matrix<float>({
        {2., -5., 0.},
        {4., 3., 7.},
        {-2., 3., 4.}
    });
    std::cout << u.trace() << std::endl; // 9.0

    u = Matrix<float>({
        {-2., -8., 4.},
        {1., -23., 4.},
        {0., 6., 4.}
    });
    std::cout << u.trace() << std::endl; // -21

    return 0;
}
