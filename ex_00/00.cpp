#include <iostream>
#include <stdexcept>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <cassert>

// addition of 2 vectors
Vector add(const Vector &u, const Vector &v)
{
	if (u.size() != v.size())
		throw std::invalid_argument("size mismatch");

	std::vector<float> result;
	for (size_t i = 0; i < u.size(); i++)
		result.push_back(u.data[i] + v.data[i]);
	return Vector(result);
}

// subtraction of a vector by another vector
Vector sub(const Vector &u, const Vector &v)
{
	if (u.size() != v.size())
		throw std::invalid_argument("size mismatch");

	std::vector<float> result;
	for (size_t i = 0; i < u.size(); i++)
		result.push_back(u.data[i] - v.data[i]);
	return Vector(result);
}

// scaling of a vector by a scalar
Vector scl(const Vector &u, float a)
{
	std::vector<float> result;
	for (size_t i = 0; i < u.size(); i++)
		result.push_back(u.data[i] * a);
	return Vector(result);
}

// addition of 2 matrices
Matrix add(const Matrix &u, const Matrix &v)
{
	if (u.rows != v.rows || u.cols != v.cols)
		throw std::invalid_argument("shape mismatch");

	std::vector<float> result;
	for (size_t i = 0; i < u.data.size(); i++)
		result.push_back(u.data[i] + v.data[i]);
	return Matrix(u.rows, u.cols, result);
}

// subtraction of a matrix by another matrix
Matrix sub(const Matrix &u, const Matrix &v)
{
	if (u.rows != v.rows || u.cols != v.cols)
		throw std::invalid_argument("shape mismatch");

	std::vector<float> result;
	for (size_t i = 0; i < u.data.size(); i++)
		result.push_back(u.data[i] - v.data[i]);
	return Matrix(u.rows, u.cols, result);
}

// scaling of a matrix by a scalar
Matrix scl(const Matrix &u, float a)
{
	std::vector<float> result;
	for (size_t i = 0; i < u.data.size(); i++)
		result.push_back(u.data[i] * a);
	return Matrix(u.rows, u.cols, result);
}

int main()
{
	Vector u({2, 3});
	Vector v({5, 7});

	add(u, v).print(); // [7] [10]
	sub(u, v).print(); // [-3] [-4]
	scl(u, 2).print(); // [4] [6]
	
	assert(add(u, v).data == std::vector<float>({7, 10}));
	assert(sub(u, v).data == std::vector<float>({-3, -4}));
	assert(scl(u, 2).data == std::vector<float>({4, 6}));

	Matrix a(2, 2, {1, 2, 3, 4});
	Matrix b(2, 2, {7, 4, -2, 2});

	add(a, b).print(); // [8, 6] [1, 6]
	sub(a, b).print(); // [-6, -2] [5, 2]
	scl(a, 2).print(); // [2, 4] [6, 8]

	assert(add(a, b).data == std::vector<float>({8, 6, 1, 6}));
	assert(sub(a, b).data == std::vector<float>({-6, -2, 5, 2}));
	assert(scl(a, 2).data == std::vector<float>({2, 4, 6, 8}));

	return (0);
}
