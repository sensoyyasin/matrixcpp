#pragma once

#include <iostream>
#include <stdexcept>
#include <utility>
#include "Vector.hpp"

class Matrix
{
public:
	size_t rows;
	size_t cols;
	std::vector<float> data; // M(i,j) = data[i * cols + j]
	Matrix(size_t r, size_t c, std::vector<float> d) : rows(r), cols(c), data(d) {
		if (data.size() != rows * cols)
		{
			throw std::invalid_argument("Matrix: data size error.");
		}
	}

	std::pair<size_t, size_t> shape() const {
		// return row and column length.
		return {rows, cols};
	}

	bool is_square() const {
		// check i and j
		if (rows != cols)
			return (false);
		return (true);
	}

	void print() const {
		for (size_t i = 0; i < rows; i++)
		{
			std::cout << "[";
			for (size_t j = 0; j < cols; j++)
			{
				std::cout << data[i * cols + j];
				if (j != cols - 1){
					std::cout << ", ";
				}
			}
			std::cout << "]" << std::endl;
		}
	}

	Vector to_vector() const {
		return Vector(data);
	}

	static Matrix from_vector(const Vector &v, size_t rows, size_t cols)
	{
		return Matrix(rows, cols, v.data);
	}

};
