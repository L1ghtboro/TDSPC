#pragma once
#include "Class_1.h"
#include "Class_2.h"
#include "Thread.h"

class Interface : Thread { //breach to access 
	private:

		bool data_ready{ false };

		Class_1 class_1obj;
		Class_2 class_2obj;
		void Viewport(float k, Class_1 obj_1, Class_2 obj_2);

		std::condition_variable cond_var;
		std::mutex mutex;

		void Await();

	public:
		void AccessPort();
};

