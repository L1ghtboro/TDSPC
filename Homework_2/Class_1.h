#pragma once

class Class_1 {
	private: 
		float some_data_1;
	public: 
		Class_1();
		Class_1(float some_data_1);
		Class_1(const Class_1& class_1);
		double get_some_data();
		void set_some_data(float newData_1);
};