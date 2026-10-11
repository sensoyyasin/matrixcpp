#include "Vector.hpp"
#include "Matrix.hpp"

int main() {
    // lerp(u, v, t) = u + t * (v - u)
    std::cout << lerp(0.f, 1.f, 0.f) << std::endl;    // 0.0
    std::cout << lerp(0.f, 1.f, 1.f) << std::endl;    // 1.0
    std::cout << lerp(0.f, 1.f, 0.5f) << std::endl;   // 0.5
    std::cout << lerp(21.f, 42.f, 0.3f) << std::endl; // 27.3

    lerp(Vector<float>({2., 1.}), Vector<float>({4., 2.}), 0.3f).print();
    // [2.6]
    // [1.3]

    lerp(Matrix<float>({{2., 1.}, {3., 4.}}), Matrix<float>({{20., 10.}, {30., 40.}}), 0.5f).print();
    // [11.0, 5.5]
    // [16.5, 22.0]

    return 0;
}
