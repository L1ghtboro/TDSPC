#pragma once

class Thread {
	private:
		std::vector<std::thread> Threads;

		const int num_producers = 3;
		const int num_consumers = 1;
		const int producer_delay_to_produce = 10;
		const int consumer_delay_to_consume = 30;

		const int consumer_max_wait_time = 200;

		const int max_production = 1;
		const int max_products = 1;

		std::atomic<int> num_producers_working;
		std::stack<int> products; //stack our products
		std::mutex xmutex;
		std::mutex mut_rand;

		std::condition_variable is_not_full;
		std::condition_variable is_not_empty;

	protected:
		bool Consume(int consumer_id);
		bool Produce(int producer_id);
		void Consumer(int id);
		void Producer(int id);

		int GenerateNumber();
	public:
		Thread();
		template <typename T> void Thread_Create(T param, int place);
		void Thread_Sync();
};

template <typename T> void Thread::Thread_Create(T param, int place) {
	Threads.push_back(std::thread(param, place));
	Threads.back().join();
}