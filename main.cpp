#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG 1



#include "./libMediaAssets/MediaAssets.h"


using namespace std;
int main() {
    std::cout << "Hello, Scratch World!" << std::endl;

   struct type
   {
       int i;
       type(): i(3) {}

       void f(int v) const {
          // this->i = v;
          const_cast<type*>(this)->i = v;
       }

   };




    std::cout << "Goodbye, Scratch World!\n";
}




