#pragma once
#include <vector>

class Array {
	std::vector<int> vec_Array;
	public:
		Array(int genSize);
		Array(std::vector<int> vec_Array);
		virtual void append(int to_append) final;
		virtual void erase(int pos_to_erase) final;
		std::vector<int> get_Array();
		void set_Array(std::vector<int> vec_Array);
};