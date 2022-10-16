#include "Array.h"
#include <stdlib.h>
#include <time.h>

Array::Array(int genSize) {
	srand(time(NULL));
	for (int i = 0; i < genSize; i++)
		vec_Array.push_back(rand()%genSize + 1);
}

Array::Array(std::vector<int> vec_Array) {
	this->vec_Array = vec_Array;
}

void Array::append(int to_append) {
	vec_Array.push_back(to_append);
}

void Array::erase(int pos_to_erase) {
	vec_Array.erase(vec_Array.begin() + pos_to_erase);
}

std::vector<int> Array::get_Array() {
	return vec_Array;
}

void Array::set_Array(std::vector<int> vec_Array) {
	this->vec_Array = vec_Array;
}