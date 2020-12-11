//
// Created by smithla on 12/10/20.
//
// C++ program to demonstrate std::back_inserter
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    std::cout << " Back Inserter Begin" << std::endl;
    // Declaring first container
    vector<int> v1 = { 1, 2, 3 };

    // Declaring second container for
    // copying values
    vector<int> v2 = { 4, 5, 6 };

    // Using std::back_inserter inside std::copy
    std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
    // v2 now contains 4 5 6 1 2 3

    // Displaying v1 and v2
    cout << "v1 = ";

    int i;
    for (i = 0; i < 3; ++i) {
        cout << v1[i] << " ";
    }

    cout << "\nv2 = ";
    for (i = 0; i < 6; ++i) {
        cout << v2[i] << " ";
    }

    std::cout << " Back Inserter End" << std::endl;
    return 0;
}

