#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG 1

void quick_remove_at(vector<int> vector, vector<int>::iterator iterator);

#include "./libMediaAssets/MediaAssets.h"


using namespace std;
int main() {
    std::cout << "Hello, Scratch World!" << std::endl;

    std::

    vector<int> v{1,2,3,4,5,2,7,8,9,2,2,4,7,3,8,3,2};
    {
        const auto new_end(remove(begin(v),end(v),2));
        v.erase(new_end,end(v));
    }

    for (const auto i: v) {
        cout << i << ", " ;
    }
    cout << '\n';
    {
        const auto odd([](int i) {return i % 2 != 0;});
        v.erase(remove_if(begin(v),end(v),odd),end(v));
    }
    v.shrink_to_fit();

    for (const auto i : v) {
        cout << i << ", ";
    }
    cout << '\n';


    std::vector<int> v{123,456,789,100,2000};
    quick_remove_at(v, 2);

    for(int i:v) {
        std::cout << i << "\n";
    }
    quick_remove_at(v,std::find(std::begin(v),std::end(v),123));



    std::cout << "Goodbye, Scratch World!\n";
}




