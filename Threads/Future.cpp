//
// Created by smithla on 12/18/20.
//

#include <iostream>
#include <deque>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <algorithm>
#include <future>



int factorial(int N) {
    int k = 1;
    for (int i = N; i > 1; i--) {
        k *= i;
    }
    return k;
}
int factorial2(std::future<int>& f) {
    int k = 1;
    int N = f.get();
    for (int i = N; i > 1; i--) {
        k *= i;
    }
    return k;
}
int factorial3(std::shared_future<int> f) {
    int k = 1;
    int N = f.get();
    for (int i = N; i > 1; i--) {
        k *= i;
    }
    return k;
}

int main() {

    int x = 0;
    int doubleX = 0;
    int tripleX = 0;
    // new thread not created, execution is deferred until .get() is called
    std::future<int> fu_no_thread = std::async(std::launch::deferred,factorial,3);
    x = fu_no_thread.get();
    std::cout << "The factorial is = "<< x << "\n";
    // new thread is created, execution is deferred until .get() is called
    std::future<int> fu_thread = std::async(std::launch::async,factorial,4);
    x = fu_thread.get();
    std::cout << "The factorial is = "<< x << "\n";

    // create a future and a promise that will set a value in the future. If the promise
    // is not kept, and exception is thrown
    // thread will not start until value is set and not return until call to get
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu_forward = std::async(std::launch::async,factorial2,std::ref(f));
    // Comment out for broken promise AND to see exception
    p.set_value(5);
    // Uncomment to see exception
    //p.set_exception(std::make_exception_ptr(std::runtime_error("ERROR IS HUMAN")));
    doubleX = fu_forward.get();
    std::cout << "The factorial2 is = "<< doubleX << "\n";


    // shared future with one promise - this is a broadcast scenario
    // One promise to many futures. All threads will block until value set

    std::promise<int> p_shared;
    std::future<int> f3 = p_shared.get_future();
    std::shared_future<int> sf = f3.share();

    // using a shared future on multiple threads
    std::future<int> fu_1 = std::async(std::launch::async,factorial3,sf);
    std::future<int> fu_2 = std::async(std::launch::async,factorial3,sf);
    std::future<int> fu_3 = std::async(std::launch::async,factorial3,sf);

    p_shared.set_value(6);

    tripleX = fu_3.get();

    std::cout << "The factorial3 is = "<< tripleX << "\n";



}
