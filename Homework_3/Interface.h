#pragma once
#include "Async.h"
#include "Thread.h"

class Interface : public Thread, Async {
	friend class Thread;
	std::vector<int> *Local_Stoage;
public:
	void AccessPort();
	int Viewport(int element, int id);
};