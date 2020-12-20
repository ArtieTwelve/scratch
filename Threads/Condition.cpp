//
// Created by smithla on 12/17/20.
//

#include <iostream>
#include <deque>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <algorithm>

std::deque<int> queue;
std::mutex m;
std::condition_variable cond;

std::ostream& operator<<(std::ostream& os, const std::deque<int>& dq) {
    os << std::for_each(queue.begin(),queue.end(),[](int const &i){ std::cout << i << ", ";}) << std::endl;
    return os;
}

void pushData() {
    int k = 10;
    while(k > 0)
    {
        std::unique_lock<std::mutex> locker(m);
        queue.push_front(k);
        locker.unlock();
        cond.notify_one(); // notify one waiting thread if it exists
        std::this_thread::sleep_for(std::chrono::seconds(1));
        k--;
    }
}

void pullDate() {
    int data = 0;
    while(data != 1) {
        std::unique_lock<std::mutex> locker(m); // puts thread in sleep mode until notified
            cond.wait(locker,[](){return !queue.empty();});
            data = queue.back();
            queue.pop_back();

            std::cout << " t2 got a value from t1: " << data << "\n";
           // std::cout << " left in t1: " << data;
        locker.unlock();

    }
}


int main()  {
    std::cout << "Start Condition Test" << "\n";
    std::thread t1(pushData);
    std::thread t2(pullDate);

    t1.join();
    t2.join();
    queue.at(6 ) = 99;
    std::for_each(queue.begin(),queue.end(),[](int const &i){
        std::cout << i << ", ";
    });

    std::cout << "End Condition Test" << "\n";
}

