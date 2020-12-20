#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 1

#include <thread>
#include <iostream>
#include <mutex>
#include <future>
#include "libEntity/Entity.h"

 std::mutex m;




 int  processOne(int x) {
    std::unique_lock<std::mutex> lock(m);
     std::cout << " Process One thread and x is: " << x << "\n";
     std::this_thread::sleep_for(std::chrono::seconds(1));
     lock.unlock();
     return ++x;
 }

 void processTwo(int& _x) {
    std::unique_lock<std::mutex> lock(m);
    _x = 2;
    std::cout << " Process Two thread waits for x: " << _x << "\n";

}

int main() {
//    std::future<int> fu_no_thread = std::async(std::launch::deferred,factorial,4);
    std::cout << "Begin, Scratch World!" << std::endl;
    int x{0};

    int& b = x;
    std::promise<int> prom;
    //std::future<int> fut = std::async(std::launch::async,processOne,x);
   auto fut2 = std::async(std::launch::async,processOne,x);
   int ret = fut2.get();
   std::cout << "Ret is: " << ret << "\n";



    std::cout << "End, Scratch World!" << std::endl;

}
