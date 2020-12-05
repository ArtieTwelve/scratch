#include <iostream>

void AddThree(int *pInt);

void AddFive(bool &sucess, int &val);

void AddFour(int &val) {
  val += 4;
}

int main() {
    std::cout << "Hello, Scratch World!" << std::endl;
    int val = 0;
    bool sucess = false;
    //AddThree(&val);
    //AddFour(val);
    AddFive(sucess, val);

    std::cout << "val = " << val << std::endl;
    std::cout << "sucess = " << sucess << std::endl;
    std::cout << "Goodbye , Scratch World!" << std::endl;
    return 0;
}

void AddFive(bool &sucess, int &val) {
    val += 5;
    sucess += true;

}

void AddThree(int *pInt) {
    *pInt += 3;

}

