 //
// Created by smithla on 12/10/20.
//
// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "../libMediaAssets/MediaAssets.h"

// test passing a pointer by value
void doSomething1(Photo *ptr) {
    ptr->_location = L"Hell Town";
}

// test passing a reference by value
void doSomething2(Photo &ref) {
    ref._location = L"Bad Town";
}

// test passing with move semantics
void doSomething3(Photo&& mov) {
    mov._location = L"Moved Location";
}

int main()
{
    // The examples go here, in order:
    std::cout << "SongMain start" << std::endl;
    // Testing

    {
        std::string namedString("Alex");

        std::string otherString{"Vlad"};

        // Creates a photo object using a non-default constructor on the heap that can be referenced in this
        // (unnamed) namespace by the pointe variable "photo"
        Photo *photo = new Photo(L"09-22-20", L"Va Beach", L"Paula");

        // pass a pointer by value and change a variable via that pointer
        doSomething1(photo);


        // Create two photo object using the default constructor  on the stack that are local to this namespace.
        Photo p1, p2;

        // Copy the contents of photo to p1 using  dereference operator
        p1 = *photo;

        // pass a reference and change the value again
        doSomething2(*photo);

        // Create a new pointer to a photo object and assign it the address of p1
        Photo *p3 = &p1;

        // pass via a move
        doSomething3(std::move(p2));

        // Move the object pointed to by p4 into p2
        p2 = std::move(*p3);

        // delete photo which is still on the heap
        delete photo;
    }
    std::cout << "SongMain testing" << std::endl;



    // Example 1
    // Use make_shared function when possible.
    auto sp1 = std::make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

    // Ok, but slightly less efficient.
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    std::shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

    // When initialization must be separate from declaration, e.g. class members,
    // initialize with nullptr to make your programming intent explicit.
    std::shared_ptr<Song> sp5(nullptr);
    //Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = std::make_shared<Song>(L"Elton John", L"I'm Still Standing");

    // Example 2
    // Example 3
    // Example 4
    // Example 6
}


// Early days Part2 Shared Pointers
/*

std::shared_ptr<Song> s9,s10,s11,s12;
std::shared_ptr<Song> s5(nullptr); // better to intialize with nullptr
std::shared_ptr<Song> s6 = std::make_shared<Song>("Elton John","Goodbye Yellowbrick Road");

// Yep
s5 = s6; // Initialize via assignment
auto s13(s6); // Init via copy constructor

std::vector<std::shared_ptr<Song>> v {
        std::make_shared<Song>("Bob Dylan","The Times They Are A Changing"),
        std::make_shared<Song>("Aretha Franklin","Bridge Over Troubled Water"),
        std::make_shared<Song>("Tha`lía", "Entre El Mar y Una Estrella")
};

std::vector<std::shared_ptr<Song>> v2;
std::remove_copy_if(v.begin(),v.end(),back_inserter(v2),[] (std::shared_ptr<Song> s) {
return s->getArtist().compare("Bob Dylan") == 0;
});

for (const auto &s : v2) {
std::cout << s->getArtist() << ":" << s->getTitle()<< std::endl;
}

*/
