#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "./song/Song.h"
#define DEBUG 1



int main() {
    std::cout << "Hello, Scratch World!" << std::endl;

    // Part 1 - Unique pointers

    std::unique_ptr<Song> s1 = std::make_unique<Song>("Electric Light Orchestra","All Over the World");
    std::unique_ptr<Song> s2 = std::make_unique<Song>("Cars","Boogie NIghts");
    std::unique_ptr<Song> s3;

    // Nope. the copy assignment operator will not work.
    // s3 = s1; <- error: use of deleted function ‘std::unique_ptr
    // Yep. You have to move a unique pointer
    s3 = std::move(s1);


    //std::cout << std::boolalpha << (s3 == false) << std::endl;

    // build a song with the non-class factory method
    auto s7 = SongFactory("The Tramps","Disco Inferno");
    // use the pointer
    std::vector<std::string> titles = {s7->getTitle()};
    // move it
    auto s8 = std::move(s7);

    // vector of pointers
    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(SongFactory("B'z", "Juice"));
    songs.push_back(SongFactory("Namie Amuro", "Funky Town"));
    songs.push_back(SongFactory("Kome Kome Club", "Kimi ga Iru Dake de"));
    songs.push_back(SongFactory("Ayumi Hamasaki", "Poker Face"));

    // before, s3 is valid
   std::cout << " Title: " << s3->getTitle() << std::endl;
    songs.push_back(std::move(s3));  // move, s3 becomes null
   // songs now has 5 songs

    for (const auto &song : songs) {
        std::cout << " The Artist: " << song->getArtist() << "  The Title: " << song->getTitle() << std::endl;
    }

    // Nope, you have to pass by reference, below will try to copy
    //songs.push_back(s2); // use of deleted function

    // Par2 Shared Pointers

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

    std::cout << "Goodbye, Scratch World!" << std::endl;
}



