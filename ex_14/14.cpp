#include "Matrix.hpp"


int main() {
    float fov = 1.5707963267948966f; // 90 degree
    float ratio = 1.0f;
    float near = 1.0f;
    float far = 10.0f;

    Matrix<float> P = projection(fov, ratio, near, far);
    P.print();

    project_point(P, Vector<float>({0., 0., -5.})).print();
    project_point(P, Vector<float>({5., 5., -5.})).print();
    project_point(P, Vector<float>({1., 1., -5.})).print();
    std::cout << project_point(P, Vector<float>({0., 0., 5.})).size() << std::endl;

    return 0;
}
