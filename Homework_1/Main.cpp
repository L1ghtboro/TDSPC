#include "Dependencies.h"

#include "Thread.h"

void test_print(int someparam) {
	std::cout << "Nothing Special "<< someparam << std::endl;
}

int test_print1(int someparam) {
	std::cout << "Nothing Special! " << someparam << std::endl;
	return 0;
}

int main() {
	Thread thread_obj;

	thread_obj.Thread_Sync();
	return 0;
}

//Summary: to sync threads we can use different realiztion patterns like we chose Produce - Consume.