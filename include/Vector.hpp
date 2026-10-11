#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

template <typename K>
class Vector {
    public:
        std::vector<K> data;

        Vector(std::vector<K> list) {
            data = list;
        }

        int size() {
            return data.size();
        }

        void add(Vector v)
        {
            for (int i = 0; i < size(); i++)
                data[i] += v.data[i];
        }

        void sub(Vector v) {
            for (int i = 0; i < size(); i++)
                data[i] -= v.data[i];
        }

        void scl(K a)
        {
            for (int i = 0; i < size(); i++)
                data[i] *= a;
        }

        void print()
        {
            for (int i = 0; i < size(); i++)
                std::cout << "[" << data[i] << "]" << std::endl;
        }

        K dot(Vector v)
        {
            if (size() != v.size())
                throw std::invalid_argument("dot: vectors must have the same size");

            K total = 0;
            for (int i = 0; i < size(); i++)
                total += data[i] * v.data[i];
            return total;
        }

        float norm_1()
        {
            float total = 0;
            for (int i = 0; i < size(); i++)
                total += my_abs(data[i]);
            return total;
        }

        float norm()
        {
            float total = 0;
            for (int i = 0; i < size(); i++)
                total += data[i] * data[i];
            return std::pow(total, 0.5f);
        }

        float norm_inf()
        {
            float total = 0;
            for (int i = 0; i < size(); i++)
                if (my_abs(data[i]) > total)
                    total = my_abs(data[i]);
            return total;
        }

    private:
        K my_abs(K x)
        {
            if (x < 0)
                return -x;
            return x;
        }
};

template <typename K>
Vector<K> linear_combination(std::vector<Vector<K>> vectors, std::vector<K> coefs)
{
    int size = vectors[0].size();
    std::vector<K> res(size, 0);

    for (int i = 0; i < (int)vectors.size(); i++)
        for (int j = 0; j < size; j++)
            res[j] += vectors[i].data[j] * coefs[i];

    return Vector<K>(res);
}

// u + t * (v - u)
inline float lerp(float u, float v, float t)
{
    return u + t * (v - u);
}

template <typename V>
V lerp(V u, V v, float t)
{
    V res = v;     // res = v
    res.sub(u);    // res = v - u
    res.scl(t);    // res = t * (v - u)
    res.add(u);    // res = u + t * (v - u)
    return res;
}

template <typename K>
float angle_cos(Vector<K> u, Vector<K> v)
{
    if (u.size() != v.size())
        throw std::invalid_argument("angle_cos: vectors must have the same size");

    return u.dot(v) / (u.norm() * v.norm());
}

template <typename K>
K det2(K a, K b, K c, K d)
{
    // | a  b |
    // | c  d |  =  a * d - b * c
    return a * d - b * c;
}

template <typename K>
Vector<K> cross_product(Vector<K> u, Vector<K> v)
{
    if (u.size() != 3 || v.size() != 3)
        throw std::invalid_argument("cross_product: vectors must be 3D");

    K i =  det2(u.data[1], u.data[2], v.data[1], v.data[2]);
    K j = -det2(u.data[0], u.data[2], v.data[0], v.data[2]);
    K k =  det2(u.data[0], u.data[1], v.data[0], v.data[1]);

    return Vector<K>({i, j, k});
}
