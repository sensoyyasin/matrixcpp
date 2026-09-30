#pragma once

#include <iostream>
#include <vector>

class Vector
{
public:
	std::vector<float> data;

	Vector(std::vector<float> d) : data(d) {}

	size_t size() const {
		return data.size();
	}

	void print() const {
		for (size_t i = 0; i < data.size(); i++) {
			std::cout << "[" << data[i] << "]" << std::endl;
		}
	}

};
