
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <fstream>
#include "threads.h"



// Functor class with an arg passed in
// Call with: std::thread t1((F()),s);
class F {
public:
    void operator()(std::string message) {
        std::cout << " Thread ID: "<< std::this_thread::get_id() << " with message: " << message << "\n";
    }
};

// Deadlocks test. Make sure both locks are set in the same order. Otherwise, deadlock
class LogFile {
public:
    LogFile() {
        f.open("log.txt");
    }
    void shared_print(std::string id, int value) {
        std::lock(m,m2);
        std::lock_guard<std::mutex> locker(m,std::adopt_lock);
        std::lock_guard<std::mutex> locker2(m2,std::adopt_lock);
        std::cout << "From sp1: " << id << " : " << value <<  "\n";
    }

    void shared_print2(std::string id, int value) {
        // swap locker and locker2 to create a deadlock
        // swap no longer deadlocks, due to using lock/adopt_lock
        std::lock(m,m2);
        std::lock_guard<std::mutex> locker(m,std::adopt_lock);
        std::lock_guard<std::mutex> locker2(m2,std::adopt_lock);


        std::cout << "From sp2: " << id << " : " << value <<  "\n";
    }
private:
    std::mutex m;
    std::mutex m2;
    std::ofstream f;

};


void sharedPrintCaller(LogFile& log) {
    for (int i = 0; i > -10; i--) {
        log.shared_print("t1: ",i);
    }
}

int main() {
    std::cout << " Begin Threads Main" << std::endl;

    // Example 1: Functor with argument passed in
    std::string message = "Hi!";
    std::thread t1((F()),message);
    // Example 2: Functor with alternate syntax
    message = "Next!";
    std::thread t2{F(),message};

    // Example 4 Deadlock test
    LogFile log;
    std::thread t3(sharedPrintCaller,std::ref(log));
    for (int i = 0; i < 10; ++i) {
        log.shared_print2(std::string("Called From Main: "),i);
    }



    t1.join();
    t2.join();
    t3.join();

    std::cout << " End Threads Main" << std::endl;
}


// Lesson 1, part 6

/*int main() {
    std::cout << "Hello, Scratch World!" << std::endl;
    std::thread t(threadFunction);

    //t.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << " Finished work in main\n";
    std::vector<std::thread> threads;
    t.join();

    return 0;
}*/
