#include "Class_1.h"

Class_1::Class_1() {
	this->some_data_1 = 0.f;
}
Class_1::Class_1(float some_data_1) {
	this->some_data_1 = some_data_1;
}
Class_1::Class_1(const Class_1& class_1) {
	this->some_data_1 = class_1.some_data_1;
}
double Class_1::get_some_data() {
	return this->some_data_1;
}

void Class_1::set_some_data(float newData_1) {
	some_data_1 = newData_1;
}
