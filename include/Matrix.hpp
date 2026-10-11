#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
#include "Vector.hpp"

template <typename K>
class Matrix {
    public:
        std::vector<std::vector<K>> data;
        int rows;
        int cols;

        Matrix(std::vector<std::vector<K>> rows_list)
        {
            data = rows_list;

            rows = data.size();
            cols = data[0].size();
        }


        void add(Matrix v)
        {
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    data[i][j] += v.data[i][j];
        }

        void sub(Matrix v)
        {
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    data[i][j] -= v.data[i][j];
        }

        void scl(K a)
        {
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    data[i][j] *= a;
        }

        void print()
        {
            for (int i = 0; i < rows; i++) {
                std::cout << "[";
                for (int j = 0; j < cols; j++) {
                    std::cout << data[i][j];
                    if (j != cols - 1)
                        std::cout << ", ";
                }
                std::cout << "]" << std::endl;
            }
        }

        // impl<K> Matrix::<K> {
        //fn mul_vec::<K>(&mut self, vec: Vector::<K>) -> Vector::<K>;
        //fn mul_mat::<K>(&mut self, mat: Matrix::<K>) -> Matrix::<K>;
        //}
        Vector<K> mul_vec(Vector<K> v)
        {
            std::vector<K> res;
            for (int i = 0; i < rows; i++) {
                K total = 0;
                for (int j = 0; j < cols; j++)
                    total += data[i][j] * v.data[j];
                res.push_back(total);
            }

            return Vector<K>(res);
        }

        Matrix mul_mat(Matrix m)
        {
            std::vector<std::vector<K>> res;

            for (int i = 0; i < rows; i++) {
                std::vector<K> new_row;
                for (int j = 0; j < m.cols; j++) {
                    K total = 0;
                    for (int k = 0; k < cols; k++)
                        total += data[i][k] * m.data[k][j];
                    new_row.push_back(total);
                }
                res.push_back(new_row);
            }
            return Matrix(res);
        }

        K trace()
        {
            if (rows != cols)
                throw std::invalid_argument("Trace is only defined for square matrices");

            K total = 0;
            for (int i = 0; i < rows; i++)
                total += data[i][i];

            return total;
        }

        Matrix transpose()
        {
            std::vector<std::vector<K>> res;

            for (int j = 0; j < cols; j++) {
                std::vector<K> new_row;
                for (int i = 0; i < rows; i++)
                    new_row.push_back(data[i][j]);
                res.push_back(new_row);
            }

            return Matrix(res);
        }

        K _abs(K x)
        {
            if (x < 0)
                return -x;
            return x;
        }

        Vector<K> solve_2x2(Vector<K> c) {
            K a = data[0][0], b = data[0][1];
            K cc = data[1][0], d = data[1][1];

            K det = a * d - b * cc;
            if (det == 0)
                throw std::invalid_argument("Matrix is singular, no unique solution");

            Matrix inv({{d / det, -b / det},
                        {-cc / det, a / det}});

            return inv.mul_vec(c); // b = A⁻¹ . c
        }


        Matrix row_echelon()
        {
            std::vector<std::vector<K>> m;
            for (int i = 0; i < rows; i++) {
                std::vector<K> new_row;
                for (int j = 0; j < cols; j++)
                    new_row.push_back(data[i][j]);
                m.push_back(new_row);
            }

            int pivot_row = 0;
            for (int col = 0; col < cols; col++) {
                if (pivot_row >= rows)
                    break;

                int found = -1;
                for (int r = pivot_row; r < rows; r++) {
                    if (m[r][col] != 0) {
                        found = r;
                        break;
                    }
                }

                if (found == -1)
                    continue;

                std::swap(m[pivot_row], m[found]);

                K p = m[pivot_row][col];
                for (int k = 0; k < cols; k++)
                    m[pivot_row][k] = m[pivot_row][k] / p;

                for (int r = 0; r < rows; r++) {
                    if (r != pivot_row) {
                        K f = m[r][col];
                        for (int k = 0; k < cols; k++)
                            m[r][k] = m[r][k] - f * m[pivot_row][k];
                    }
                }

                pivot_row += 1;
            }

            return Matrix(m);
        }

        K determinant()
        {
            if (rows == 1 && cols == 1)
                return data[0][0];

            if (rows == 2 && cols == 2) {
                K a = data[0][0], b = data[0][1], c = data[1][0], d = data[1][1];
                return a * d - b * c;
            }

            K total = 0;
            for (int j = 0; j < cols; j++) {

                std::vector<std::vector<K>> minor;
                for (int i = 1; i < rows; i++) {
                    std::vector<K> new_row;
                    for (int k = 0; k < cols; k++)
                        if (k != j)
                            new_row.push_back(data[i][k]);
                    minor.push_back(new_row);
                }

                int sign;
                if (j % 2 == 0)
                    sign = 1;
                else
                    sign = -1;

                total += sign * data[0][j] * Matrix(minor).determinant();
            }

            return total;
        }

        // A⁻¹ = adj(A) / det(A)
        Matrix inverse()
        {
            K det = determinant();

            if (det == 0)
                throw std::invalid_argument("Matrix is singular, it has no inverse");

            int n = rows;

            if (n == 1)
                return Matrix(std::vector<std::vector<K>>{{1 / det}});

            std::vector<std::vector<K>> cof;
            for (int i = 0; i < n; i++) {
                std::vector<K> cof_row;
                for (int j = 0; j < n; j++) {

                    std::vector<std::vector<K>> minor;
                    for (int r = 0; r < n; r++) {
                        if (r != i) {
                            std::vector<K> new_row;
                            for (int c = 0; c < n; c++)
                                if (c != j)
                                    new_row.push_back(data[r][c]);

                            minor.push_back(new_row);
                        }
                    }
                    int sign;
                    if ((i + j) % 2 == 0)
                        sign = 1;
                    else
                        sign = -1;

                    cof_row.push_back(sign * Matrix(minor).determinant());
                }
                cof.push_back(cof_row);
            }


            std::vector<std::vector<K>> res;
            for (int i = 0; i < n; i++) {
                std::vector<K> new_row;
                for (int j = 0; j < n; j++)
                    new_row.push_back(cof[j][i] / det + 0.0f);
                res.push_back(new_row);
            }

            return Matrix(res);
        }

        int rank()
        {
            Matrix r = row_echelon();
            int count = 0;

            for (int i = 0; i < r.rows; i++) {
                bool all_zero = true;
                for (int j = 0; j < r.cols; j++) {
                    if (r.data[i][j] != 0) {
                        all_zero = false;
                        break;
                    }
                }

                if (!all_zero)
                    count += 1;
            }

            return count;
        }
};


inline Matrix<float> projection(float fov, float ratio, float near, float far) {
    float f = 1.0f / std::tan(fov / 2.0f);

    // Projection Matrix
    return Matrix<float>({
        {f / ratio, 0.0f, 0.0f, 0.0f},
        {0.0f, f, 0.0f, 0.0f},
        {0.0f, 0.0f, far / (near - far), -(far * near) / (far - near)},
        {0.0f, 0.0f, -1.0f, 0.0f},
    });
}

inline Vector<float> project_point(Matrix<float> P, Vector<float> point) {
    float x = point.data[0];
    float y = point.data[1];
    float z = point.data[2];

    std::vector<float> p = {x, y, z, 1.0f};
    std::vector<float> clip;

    for (int i = 0; i < 4; i++)
    {
        float value = 0.0f;
        for (int j = 0; j < 4; j++)
            value += P.data[i][j] * p[j];

        clip.push_back(value);
    }

    float w = clip[3];
    if (w <= 0)
        return Vector<float>({});

    float x_ndc = clip[0] / w;
    float y_ndc = clip[1] / w;

    return Vector<float>({x_ndc, y_ndc});
}
