#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    {
        Vector<float> u({2., 3.});
        Vector<float> v({5., 7.});
        u.add(v);
        u.print();
        // [7.0]
        // [10.0]
    }

    {
        Vector<float> u({2., 3.});
        Vector<float> v({5., 7.});
        u.sub(v);
        u.print();
        // [-3.0]
        // [-4.0]
    }

    {
        Vector<float> u({2., 3.});
        u.scl(2.);
        u.print();
        // [4.0]
        // [6.0]
    }

    {
        Matrix<float> u({{1., 2.}, {3., 4.}});
        Matrix<float> v({{7., 4.}, {-2., 2.}});
        u.add(v);
        u.print();
        // [8.0, 6.0]
        // [1.0, 6.0]
    }

    {
        Matrix<float> u({{1., 2.}, {3., 4.}});
        Matrix<float> v({{7., 4.}, {-2., 2.}});
        u.sub(v);
        u.print();
        // [-6.0, -2.0]
        // [5.0, 2.0]
    }

    {
        Matrix<float> u({{1., 2.}, {3., 4.}});
        u.scl(2.);
        u.print();
        // [2.0, 4.0]
        // [6.0, 8.0]
    }

    return 0;
}
