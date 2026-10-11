#include "Vector.hpp"
#include "Matrix.hpp"


int main() {
    {
        Matrix<float> u({
            {1., 0.},
            {0., 1.},
        });
        Vector<float> v({4., 2.});
        u.mul_vec(v).print(); // [4.] # [2.]
    }

    {
        Matrix<float> u({
            {2., 0.},
            {0., 2.},
        });
        Vector<float> v({4., 2.});
        u.mul_vec(v).print(); // [8.] # [4.]
    }

    {
        Matrix<float> u({
            {2., -2.},
            {-2., 2.},
        });
        Vector<float> v({4., 2.});
        u.mul_vec(v).print(); // [4.] # [-4.]
    }

    {
        Matrix<float> u({
            {1., 0.},
            {0., 1.},
        });

        Matrix<float> v({
            {1., 0.},
            {0., 1.},
        });

        u.mul_mat(v).print(); // [1., 0.], #[0., 1.]
    }

    return 0;
}
