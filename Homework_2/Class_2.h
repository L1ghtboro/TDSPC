#pragma once

class Class_2 {
	private:
		float some_data_2;
	public:
		Class_2();
		Class_2(float some_data_2);
		Class_2(const Class_2& class_2);
		float get_some_data();
		void set_some_data(float newData_2);
};