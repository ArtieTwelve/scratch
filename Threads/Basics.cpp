//
// Created by smithla on 12/19/20.
//

#include <iostream>
#include <thread>
#include <vector>

// Passing a ref to a thread must be const - why?
void print(int n,const std::string &str) {
    std::cout << " In Print" << "\n";
    std::cout << "  Printing thread id: "<< std::this_thread::get_id() << "\n";
    std::cout << "  Printing int: "<< n << "\n";
    std::cout << "  Printing String: "<< str << "\n\n";

}

void print2(int n,std::string str) {
    std::cout << " In Print2" << "\n";
    std::cout << "  Printing thread id: "<< std::this_thread::get_id() << "\n";
    std::cout << "  Printing int: "<< n << "\n";
    std::cout << "  Printing String: "<< str << "\n";
    // Attempt to change the message in print2
    str = " Change the Message!!!";
    std::cout << "  Attempt change : "<< str << "\n\n";

}

void printString(std::string str) {
    std::cout << " String: "<< str << "\n";
    str = " Changed ";
}

struct strings {
    std::vector<std::string> s {
        "Now is the time",
        "For all good men",
        "To come to the aid",
        "of their country",
        "And I guess that",
        "Could mean me"
    };
};

int main() {
    std::cout << " Start Thread Basics" << "\n";
    std::string message{"Always pass by value"};

    // Create a thread, pass a function, join to main
    std::cout << " Section 1: Simple Thread " << "\n";
    std::thread t1(print,10,message);
    t1.join();
    //Threads are always pass by value, even if the arg is pass by reference
    // Check on this.
    std::thread t2(print2,10,message);
    t2.join();
    std::cout << " Message is: " << message << "\n";

    // Multiple threads
    std::cout << "\n\n Section 2: an array of threads " << "\n";
    strings theStrings;
    std::vector<std::thread> threads;
    for (int i = 0; i < theStrings.s.size(); ++i) {
        threads.push_back(std::thread(printString,theStrings.s[i]));
    }


    // Join - main thread waits for any joined thread to finish before continueing
    // Detach - thread will run freely.
    for(auto &th : threads)
        th.join();
        //th.detach();


   // Section 3: Detachment
   std::cout << "\n\n Section 3: Detachment" << "\n";

    std::thread t3(print,10,"Call To Print");
    // Once a thread is detached, you cannot rejoin it.
    t3.detach();
    if(t3.joinable()) {
        t3.join();
    }
    else {
        std::cout << " t3 is not joinable" << "\n";
    }

    std::cout << "\n\n Section 4: " << "\n";
    std::cout << "\n\n Section 5: " << "\n";
    std::cout << "\n\n Section 6: " << "\n";
    std::cout << "\n\n Section 7: " << "\n";
    std::cout << "\n\n Section 8: " << "\n";




    std::cout << " End Thread Basics" << "\n";
}