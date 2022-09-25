#include "Interface.h"

void Interface::Viewport(float k, Class_1 obj_1, Class_2 obj_2) {
	srand(time(NULL));
	obj_1.set_some_data(obj_1.get_some_data() + static_cast <float> (rand()) / static_cast <float> (k));
	obj_2.set_some_data(obj_2.get_some_data() + static_cast <float> (rand()) / static_cast <float> (k));

	std::unique_lock<std::mutex> lock(mutex);
	cond_var.wait(lock, [] { return data_ready; });
}

void Interface::Await() {

	std::lock_guard<std::mutex> lock(mutex);
	data_ready = true;

	cond_var.notify_one();
}

void Interface::AccessPort() {
	float rand_k1 = static_cast <float> (rand()) / static_cast <float> (20000) + 10000, 
		  rand_k2 = static_cast <float> (rand()) / static_cast <float> (20000) + 10000;

	int size_n = rand() % 11 + 10;

	for (int through_size = 0; through_size < size_n / 2; through_size++)
		Threads.push_back(std::thread(&Interface::Viewport, this, rand_k1, class_1obj, class_2obj));

	for (int through_size = size_n/2; through_size < size_n; through_size++)
		Threads.push_back(std::thread(&Interface::Viewport, this, rand_k1, class_1obj, class_2obj));

	for (int through_size = 0; through_size < size_n; through_size++)
		Threads.push_back(std::thread(&Interface::Await, this));

	for (auto& threads : Thread::Threads)
		threads.join();
}