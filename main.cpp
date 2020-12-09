#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include "./entity/Entity.h"


int main() {
    std::cout << "Hello, Scratch World!" << std::endl;
    int i = 11;
    int r = 22;
    int* pi2 = &r;
    int* pi = &i;
    std::unique_ptr<Entity> e1 = std::make_unique<Entity>(99);
    std::shared_ptr<Entity> e2 = std::make_shared<Entity>(88);

    e1.get()->setString("Today is the day");
    e1.get()->setPi(pi);
    e1.get()->setInt(100);

    Entity e3,e4,e5;

    e3.setInt(44);
    e3.setPi(pi);
    e3.setString("This is the string");

    e4 = e3;


    //delete e3;
    std::cout << "Goodbye, Scratch World!" << std::endl;
}



