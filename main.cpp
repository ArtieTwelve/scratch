#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG 1



#include "./libMediaAssets/MediaAssets.h"


using namespace std;

class Position {
    int x,y;
    std::unique_ptr<std::pair<int,int>> getPosition() {
        return std::make_unique<std::pair<int,int>>(x,y);
    }
};

struct BaseEntity {
public:
    int i;
    std::string name;

    BaseEntity(int _i, std::string _n) : i(_i), name(_n) {}
    BaseEntity(const BaseEntity& other) {
        i = other.i;
        name = other.name;
    }

    void doSomething(float z, int i, int j, std::string name);

    void doSomethingTwo(int i);

};

void BaseEntity::doSomething(float z, int i, int j, std::string name) {

}


int main() {
    std::cout << "Hello, Scratch World!" << std::endl;



    std::cout << "Goodbye, Scratch World!\n";
}





