//
// Created by smithla on 12/18/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 1

#include <thread>
#include <iostream>
#include "Entity.h"




int main() {

    std::cout << "Begin, Scratch World!" << std::endl;
    std::cout << "Begin SimpleString with non default constructor" << std::endl;
    SimpleString s1 = SimpleString(5,"Hello");
    std::cout << "End SimpleString with non default Constructor" << "\n";

    std::cout << "Begin SimpleString Default Constructor" << "\n";
    SimpleString s3,s5;
    std::cout << "End SimpleString Default Constructor" << "\n";
    std::cout << "Begin SimpleString Copy Assignment Operator" << "\n";
    SimpleString s2(s1);
    std::cout << "End SimpleString Copy Assignment Operator" << "\n";
    s3 = s1;
    std::cout << "Begin SimpleString Move Constructor Operator" << "\n";
    SimpleString s4(std::move(s3));
    std::cout << "End SimpleString Move Constructor Operator" << "\n";
    std::cout << "Begin SimpleString Move Assignment Operator" << "\n";
    s5 = std::move(s2);
    std::cout << "Begin SimpleString Move Assignment Operator" << "\n";

    std::cout << "End, Scratch World!" << std::endl;

}