#include "Class_2.h"

Class_2::Class_2() {
	this->some_data_2 = 0.f;
}

Class_2::Class_2(float some_data_2) {
	this->some_data_2 = some_data_2;
}

Class_2::Class_2(const Class_2& class_2) {
	this->some_data_2 = class_2.some_data_2;
}

float Class_2::get_some_data() {
	return this->some_data_2;
}

void Class_2::set_some_data(float newData_2) {
	some_data_2 = newData_2;
}