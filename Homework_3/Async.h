#pragma once
#include "Thread.h"
#include <future>

class Async {
protected:
	std::vector<std::future<int>> Asyncs;
};