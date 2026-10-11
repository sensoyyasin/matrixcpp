// compute cos(u,v), the cosine of the angle between the two vectors uand v.

#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Vector<float> u({1., 0.});
    Vector<float> v({1., 0.});
    std::cout << angle_cos(u, v) << std::endl; // 1.0

    u = Vector<float>({1., 0.});
    v = Vector<float>({0., 1.});
    std::cout << angle_cos(u, v) << std::endl; // 0.0

    u = Vector<float>({-1., 1.});
    v = Vector<float>({1., -1.});
    std::cout << angle_cos(u, v) << std::endl; // -1.0

    u = Vector<float>({2., 1.});
    v = Vector<float>({4., 2.});
    std::cout << angle_cos(u, v) << std::endl; // 1.0

    u = Vector<float>({1., 2., 3.});
    v = Vector<float>({4., 5., 6.});
    std::cout << angle_cos(u, v) << std::endl; // 0.974631846

    return 0;
}
