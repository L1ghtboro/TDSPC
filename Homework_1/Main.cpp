#include "Dependencies.h"

#include "Thread.h"

void test_print(int someparam) {
	std::cout << "Nothing Special" << std::endl;
}

int main() {
	Thread thread_obj;
	thread_obj.Thread_Create(test_print, 1);
	thread_obj.Thread_Create(test_print, 2);

	thread_obj.Thread_Sync();
	return 0;
}

//Summary: to sync threads we can use different realiztion patterns like we chose Produce - Consume.