//
// Created by smithla on 12/6/20.
//


#include "Entity.h"

Entity::Entity() { std::cout << " Default CTOR\n";}
Entity::Entity(std::string name)  : _name(name) {
    std::cout << " Int CTOR\n";
}

Entity:: Entity(std::string name,int i) : _name(name),_pi(std::make_unique<int>(i)){
    std::cout << " Name, Int CTOR\n";
}

Entity::Entity(const Entity& e) {
    std::cout << " Copy CTOR\n";
    _i = e._i;
}

Entity::~Entity() {
    std::cout << " Destructor\n";

}
// Copy Assignment and Move Assignment - use these patterns

Entity &Entity::operator=(const Entity &rhs) {
    if(this != &rhs) {
        std::cout << " Assignment Operator\n";


        _name = rhs._name;
        _i = rhs._i;
        _s = rhs._s;
        _preg = rhs._preg;

        // Cant' use swap due to const rhs
        //std::swap(_pi,rhs._pi);
    }
    return *this;
}

Entity &Entity::operator=(Entity &&rhs) noexcept {
    std::cout << " Move Assignment\n";
    _name = "";
    _preg = NULL;
    _i = 0;
    _s = "";
    _name = std::move(rhs._name);
    _i = std::move(rhs._i);
    _pi = std::move(rhs._pi);
    _s = std::move(rhs._s);
    _preg = std::move(rhs._preg);

    rhs._i = 0;
    rhs._preg = nullptr;
    rhs._s = "";
    rhs._name = "";
    rhs._pi.release();
    return *this;
}

Entity::Entity(Entity &&rhs) {
    std::cout << " Move CTOR \n";
    _i = rhs._i;
}



void Entity::setInt(int i) {
    _i = i;
}

void Entity::setPi(int i) {
    _pi = std::make_unique<int>(i);
}
void  Entity::setString(std::string s) {
    _s = s;
}

void Entity::setName(std::string n) {
    _name = n;
}

int Entity::getPi() {
    return *(_pi.get());
}


// The main class used in main.cpp
// Move this code back to main.cpp to test it

/*int main() {
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
}*/

SimpleString::SimpleString() {
    std::cout << "SimpleString Default Constructor" << "\n";
}

SimpleString::SimpleString(int len, std::string str): _len(len) , _str(str) {
    std::cout << "SimpleString Initialize Constructor" << "\n";
}

SimpleString::~SimpleString() {
    std::cout << "SimpleString Destructor" << "\n";
}

SimpleString::SimpleString(const SimpleString &other) : _len(other._len), _str(other._str){
    std::cout << "SimpleString Copy Constructor" << "\n";
}

SimpleString &SimpleString::operator=(const SimpleString &other) {
    std::cout << "SimpleString Assignment Operator" << "\n";
    _len = other._len;
    _str = other._str;
    return *this;
}

SimpleString::SimpleString(SimpleString &&other) {
    std::cout << "SimpleString Move Constructor" << "\n";
    _len = std::move(other._len);
    _str = std::move(other._str);
    other._len = 0;
    other._str = "";

}

SimpleString &SimpleString::operator=(SimpleString &&other) {
    std::cout << "SimpleString Move Assignment Operator" << "\n";
    _len = std::move(other._len);
    _str = std::move(other._str);
    other._len = 0;
    other._str = "";
    return *this;
}


