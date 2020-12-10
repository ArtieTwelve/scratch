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

    // raw pointer
    Entity *raw = new Entity();

    // dereference and assign
    Entity &ref = *raw;

    // Copy constructor
    Entity copy = Entity(ref);

    raw->setInt(1111);

    // Experiments with unique pointers. These two are show Entity classes encapsulated.
    std::unique_ptr<Entity> e1 = std::make_unique<Entity>("e1",111);
    std::shared_ptr<Entity> e2 = std::make_shared<Entity>("e2",222);

    // Call to .get not needed, used -> operator instead
    e1.get()->setString("E1.E1.E1.E1.E1.E1.E1.E1.");
    e1.get()->setPi(111);
    e1.get()->setInt(100);

    //  this is the way
    e1->setString("Mmmmmm... chicken.");
    e1->getPi();
    e1->setInt(99);


    // Entity has a unique pointer, pi  inside. It is a pointer
    // to a simple int.  The getter and setters take/return ints
    //
    Entity e3("e3",33);
    Entity e4("e4",44);
    Entity e5("e5",55);
    Entity e6("e6",66);

    e6.setInt(666);
    e6.setPi(666);
    e6.setString("E6.E6.E6.E6.E6.E6.E6.E6.E6.E6.");

    e3.setInt(333);
    e3.setPi(333);
    e3.setString("E3.E3.E3.E3.E3.E3.E3.E3.E3.E3.");

    e4.setString("E4.E4.E4.E4.E4.E4.E4.E4.E4.E4.");
    e5.setString("E5.E5.E5.E5.E5.E5.E5.E5.E5.E5.");

    // Exercising the move assigment operator
    e4 = e3;
    e5 = std::move(e3);
    e6 = std::move(e5);

    // getPi is nother more than *(e6.get())
    // since it is just a pointer to int, get()
    // returns that. A unique pointer to a class
    // will give access to it's methods.
    int c = e6.getPi();

    // cannot call delete unless paired with "new"
    //delete e3;
    // I can del this one
    delete raw;
    std::cout << "Goodbye, Scratch World!" << std::endl;
}



