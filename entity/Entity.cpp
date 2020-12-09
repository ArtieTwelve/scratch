//
// Created by smithla on 12/6/20.
//


#include "Entity.h"
Entity::Entity() { std::cout << " Default CTOR\n";}
Entity::Entity(int i)  : _i(i) {
    std::cout << " Int CTOR\n";
}

Entity::Entity(const Entity& e) {
    std::cout << " Copy CTOR\n";
    _i = e._i;
}

Entity::~Entity() {
    std::cout << " Destructor\n";
}

Entity &Entity::operator=(const Entity &ref) {
    std::cout << " Assignment Operator\n";
    _i = ref._i;
    return *this;
}

Entity::Entity(Entity &&ref) {
    std::cout << " Move CTOR \n";
    _i = ref._i;
}

Entity &Entity::operator=(Entity &&ref) {
    std::cout << " Move Assignment\n";
    _i = 0;
    _pi  = nullptr;
    _s = nullptr;
    _i = std::move(ref._i);
    _pi = std::move(ref._pi);
    _s = std::move(ref._s);
    ref._i = 0;
    ref._pi = nullptr;
    ref._s = nullptr;
    return *this;
}

void Entity::setInt(int i) {
    _i = i;
}

void Entity::setPi(int* pi) {
    _pi = pi;
}
void  Entity::setString(std::string s) {
    _s = s;
}

// The main class used in main.cpp
// Move this code back to main.cpp to test it

/*int main() {
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

}*/
