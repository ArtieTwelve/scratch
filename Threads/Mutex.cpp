//
// Created by smithla on 12/17/20.
//
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu;

// cout is a global resource, so just locking with a mutex or lock guard
// will not protect it

// This is not exception safe. Should not use mutex directly
void shared_print1(int i) {
    mu.lock();
    std::cout << "Thread #" << i << " Id: " << std::this_thread::get_id() << "\n";
    mu.unlock();
}

// lock_guard manages the mutex and will release it in case of an exception
void shared_print2(int i) {
    std::lock_guard<std::mutex> lock(mu);
    std::cout << "Thread #" << i << " Id: " << std::this_thread::get_id() << "\n";
}

// unique_lock provides the same as logk_guard but is more flexible. You can
// unlock it directly. You do not have to wait for it to go out of scope
// for the resource to be unlocked.
void shared_print3(int i) {
    std::unique_lock<std::mutex> lock(mu);
    std::cout << "Thread #" << i << " Id: " << std::this_thread::get_id() << "\n";
    lock.unlock();
}
// Deferred locking. Set up the lock but don't lock immediately
// Can also unlock/relock/move
void shared_print4(int i) {
    std::unique_lock<std::mutex> lock(mu,std::defer_lock);
    // Do something... then lock
    lock.lock();
    std::cout << "Thread #" << i << " Id: " << std::this_thread::get_id() << "\n";
    lock.unlock();
    // lock can be reused and moved
    lock.lock();
    std::unique_lock<std::mutex> lock2 = std::move(lock);
}



int main()   {
    std::thread threads[10];

    for (int i = 0; i < 10; ++i) {
        //threads[i] = std::thread(shared_print1,i);
        //threads[i] = std::thread(shared_print2,i);
        threads[i] = std::thread(shared_print3,i);
    }
    for(auto& th: threads) th.join();
    return 0;
}
