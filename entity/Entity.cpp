//
// Created by smithla on 12/6/20.
//


#include "Entity.h"
Entity::Entity() { std::cout << " Default CTOR\n";}
Entity::Entity(int i)  : _i(i) {
    std::cout << " Int CTOR\n";
}

Entity::Entity(Entity& e) {
    std::cout << " Copy CTOR\n";
    _i = e._i;
}

Entity::~Entity() {
    std::cout << " Destructor\n";
}

Entity &Entity::operator=(Entity &ref) {
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
    _i = ref._i;
    return *this;
}

void Entity::setInt(int i) {
    _i = i;
}