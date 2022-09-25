#include "Dependencies.h"
#include "Thread.h"

std::stack<int> products; //stack our products

Thread::Thread() {
	num_producers_working = 0; // stop programm when no producers left
}

int Thread::GenerateNumber() { // Generate Mutex number for Produce method
    std::lock_guard<std::mutex> lock(mut_rand);
    return rand() % 3;
}

bool Thread::Consume(int consumer_id) { // will consume produced product for consumer_id
    for (;;) {
        std::unique_lock<std::mutex> lock(xmutex);
        int product;

        if (is_not_empty.wait_for(lock, std::chrono::milliseconds(consumer_max_wait_time), []{ return products.size() > 0; })){
            product = products.top();
            products.pop();

            std::cout << "Consumer " << consumer_id << " consumed " << product << std::endl;
            is_not_full.notify_all();
        }
    }
}

bool Thread::Produce(int producer_id) { // will produce new product for produce_id
    for(;;){
        std::unique_lock<std::mutex> lock(xmutex);
        int product;

        is_not_full.wait(lock, []{ return products.size() != 1; });
        product = GenerateNumber();
        products.push(product);

        std::cout << "Producer " << producer_id << " produced " << product << std::endl;
        is_not_empty.notify_all();
    }
}

void Thread::Consumer(int id) {
    while (num_producers_working == 0) std::this_thread::yield();

    while (num_producers_working != 0 || products.size() > 0){
        this->Consume(id);
        std::this_thread::sleep_for(std::chrono::milliseconds(consumer_delay_to_consume));
    }

    std::cout << "Consumer " << id << " has exited\n";
}

void Thread::Producer(int id) {
    ++num_producers_working;
    for (int i = 0; i < max_production; ++i){
        this->Produce(id);
        std::this_thread::sleep_for(std::chrono::milliseconds(producer_delay_to_produce));
    }

    std::cout << "Producer " << id << " has exited\n";
    --num_producers_working;
}

void Thread::Thread_Sync() {
    Thread* temp = new Thread();

    for (int i = 0; i < num_producers; ++i)
        Threads.push_back(std::thread(&Thread::Producer, temp, i));

    for (int i = 0; i < num_consumers; ++i)
        Threads.push_back(std::thread(&Thread::Consumer, temp, i));

    for (auto& threads : Threads)
        threads.join();
}