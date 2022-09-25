#pragma once
#include "Dependencies.h"

class Thread {
	protected:
		std::vector<std::thread> Threads;
		template <typename Function, typename Argument> void Thread_Create(Function param_func, Argument param_arg);
};

template <typename Function, typename Argument> void Thread::Thread_Create(Function param_func, Argument param_arg) {
	Threads.push_back(std::thread(param_func, param_arg));
	Threads.back().join();
}