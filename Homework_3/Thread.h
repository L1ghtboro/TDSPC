#pragma once
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include "Logger.h"

class Thread{
protected:
	Thread();
	Logger thread_logger;
	std::vector<std::thread> Threads;
	bool data_ready{ false };
	std::condition_variable cond_var;
	std::mutex mutex;
	void Await(int thread_id);
};
