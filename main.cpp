#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include "./entity/Entity.h"


int main() {
    std::cout << "Hello, Scratch World!" << std::endl;
    Entity e0;
    Entity e1(100);

    Entity e2 = e1;
    Entity e4(e0);

    e0.setInt(200);
    Entity e5(std::move(e0));
    Entity e6;
    e6 = std::move(e1);


    return 0;

}



