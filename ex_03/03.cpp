#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    Vector<float> u({0., 0.});
    Vector<float> v({1., 1.});
    std::cout << u.dot(v) << std::endl; //0.0

    u = Vector<float>({1., 1.});
    v = Vector<float>({1., 1.});
    std::cout << u.dot(v) << std::endl; //2.0

    u = Vector<float>({-1., 6.});
    v = Vector<float>({3., 2.});
    std::cout << u.dot(v) << std::endl; //9.0

    return (0);
}
