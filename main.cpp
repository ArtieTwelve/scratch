#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>

class Entity {
public:
    void setInt(int i) { _i = i;}

    // Default CTOR
    Entity() { std::cout << " Default CTOR\n";}
    // CTOR
    Entity(int i) : _i(i) { std::cout << " Int CTOR \n";}
    // Copy CTOR
    Entity(const Entity& e) {
        std::cout << " Copy CTOR\n";
        _i = e._i;
    }
    ~Entity() { std::cout << " Destructor\n";}
    // Assignment Operator
    Entity& operator=(const Entity& ref)  {
        std::cout << " Assignment Operator\n";
        _i = ref._i;
        return *this;
    }
    // Move CTOR
    Entity(Entity&& ref) {
        std::cout << " Move CTOR \n";
        _i = ref._i;
    }
    // Move Assignment
    Entity& operator=(Entity&& ref) {
        std::cout << " Move Assignment\n";
        _i = ref._i;
        return *this;
    }



private:
    int _i;
};
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



