#include "Interface.h"
#include "Array.h"
#include <iostream>
#include <future>
#include <chrono>
#include <sstream>

#define SIZE_N 32768

int Interface::Viewport(int element, int id) {
	thread_logger.LogDebug("Thread in process, please stand by");
	std::unique_lock<std::mutex> lock(mutex);
	cond_var.wait(lock, [&] { return data_ready; });

	Local_Stoage[id].push_back(element);
	Local_Stoage[id].push_back(0);
	Local_Stoage[id].push_back(element);

	while (Local_Stoage[id][Local_Stoage[id].size() - 1] != 1) {
		if (Local_Stoage[id][Local_Stoage[id].size() - 1] % 2 == 0) {
			Local_Stoage[id][Local_Stoage[id].size() - 1] /= 2;
			Local_Stoage[id][Local_Stoage[id].size() - 2]++;
		}
		else {
			Local_Stoage[id][Local_Stoage[id].size() - 1] = Local_Stoage[id][Local_Stoage[id].size() - 1] * 3 + 1;
			Local_Stoage[id][Local_Stoage[id].size() - 2] ++;
		}
	}
	
	thread_logger.LogDebug("Thread done working, exiting thread and returning data");
	return Local_Stoage[id][Local_Stoage[id].size() - 2];
}

void Interface::AccessPort() {
	Array array_obj(SIZE_N);
	Local_Stoage = new std::vector<int>[SIZE_N];
	std::vector<int> Array_save = array_obj.get_Array();
	
	auto begin = std::chrono::high_resolution_clock::now();

	thread_logger.LogDebug("Start launching threads with async");

	for (int async_push = 0; async_push < Array_save.size(); async_push++) {
		Asyncs.push_back(std::async(std::launch::deferred, &Interface::Viewport, this, Array_save[async_push], async_push));
	}

	auto end = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	thread_logger.LogDebug("Interface::AccessPort finished working");

	std::stringstream log_msg_time;
	log_msg_time << elapsed.count() * 1e-9;

	thread_logger.LogDebug("Working time - " + log_msg_time.str());

	std::cout << "Working time - " + log_msg_time.str() << std::endl;
}