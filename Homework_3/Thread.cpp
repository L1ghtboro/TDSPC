#include "Thread.h"
#include <iostream>

Thread::Thread() {
	thread_logger.InitLogger("thread.log");
}

void Thread::Await(int thread_id) {
	std::lock_guard<std::mutex> lock(mutex);
	data_ready = true;

	cond_var.notify_one();

	thread_logger.LogDebug("Thread has been released");
}