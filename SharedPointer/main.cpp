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

using namespace std;

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


// used in example 5
 struct type {
     int i;
     type(int _i) : i(_i) {}
     int getItem() { return i;}
 };
 void useTypeByRawPointer(type* t) {
     std::cout << "Type t: " << t->getItem() << std::endl;
 }

 void useTypeByValue(type t) {
     std::cout << "Type t: " << std::endl;
 }

 void useTypeByRef(type t) {
     std::cout << "Type t: " << std::endl;
 }

 void useTypeBySharedPointer(type t) {
     std::cout << "Type t: " << std::endl;
 }

// void useTypeByValue(type t) {
//     std::cout << "Type t: " << std::endl;
// }

int main()
{
    // The examples go here, in order:
    std::cout << "SharedPointer testing start" << std::endl;
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
    std::cout << "End SharedPointer testing" << std::endl;



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

    auto sp3(sp2);

    auto sp4 = sp2;


    std::shared_ptr<Song> sp7(nullptr);

    sp1.swap(sp2);
    // Example 3
    // Copy SPs into a vector.
    vector<shared_ptr<Song>> v {
            make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
            make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
            make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")
    };

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s)
    {
        return s->getArtist().compare(L"Bob Dylan") == 0;
    });

    wcout << L" Original Vector\n";
    for (const auto& s : v)
    {
        wcout << s->getArtist() << L":" << s->getTitle() << endl;
    }

    wcout << L" Filtered Vector\n";
    for (const auto& s : v2)
    {
        wcout << s->getArtist() << L":" << s->getTitle() << endl;
    }
    // Example 4
    vector<shared_ptr<MediaAsset>> assets {
            make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
            make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
            make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
    };

    vector<shared_ptr<MediaAsset>> photos;

    copy_if(assets.begin(), assets.end(), back_inserter(photos), [] (shared_ptr<MediaAsset> p) -> bool
    {
        // Use dynamic_pointer_cast to test whether
        // element is a shared_ptr<Photo>.
        shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
        return temp.get() != nullptr;
    });

    for (const auto&  p : photos)
    {
        // We know that the photos vector contains only
        // shared_ptr<Photo> objects, so use static_cast.
        wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->_location << endl;
    }
    // Example 5

    // A contrived example, but it will do

    // Make a shared pointer of type "type"
    std::shared_ptr<type> t = std::make_shared<type>(1);

    // 1) pass the raw pointer or reference into a function. useTypeByRawPointer does not share ownership of the object
    //    Use this when the contract clearly specifies that the caller retains ownership of the shared_ptr lifetime.
    //    You could also pass the shared pointer by reference or const
    type* tp = t.get();
    type& tr = &t.get();
    useTypeByRawPointer(tp);
    useTypeByRef(tr);

    // 2



    // Example 6
    // Initialize two separate raw pointers.
// Note that they contain the same values.
    auto song1 = new Song(L"Village People", L"YMCA");
    auto song2 = new Song(L"Village People", L"YMCA");

// Create two unrelated shared_ptrs.
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);

// Unrelated shared_ptrs are never equal.
    wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    wcout << "p1 == p2 = " << std::boolalpha <<(p1 == p2) << endl;

// Related shared_ptr instances are always equal.
    shared_ptr<Song> p3(p2);
    wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
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
