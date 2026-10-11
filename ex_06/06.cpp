#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    Vector<float> u({0., 0., 1.});
    Vector<float> v({1., 0., 0.});
    cross_product(u, v).print(); // [0.] [1.] [0.]

    u = Vector<float>({1., 2., 3.});
    v = Vector<float>({4., 5., 6.});
    cross_product(u, v).print(); // [-3.] [6.] [-3.]

    u = Vector<float>({4., 2., -3.});
    v = Vector<float>({-2., -5., 16.});
    cross_product(u, v).print(); // [17.] [-58.] [-16.]

    return 0;
}
