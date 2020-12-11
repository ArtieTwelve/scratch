#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "../libSong/Song.h"

int main() {
    // Part 1 - Unique pointers

    std::unique_ptr<Song> s1 = std::make_unique<Song>("Electric Light Orchestra","All Over the World");
    std::unique_ptr<Song> s2 = std::make_unique<Song>("Cars","Boogie NIghts");
    std::unique_ptr<Song> s3;

    // Nope. the copy assignment operator will not work.
    // s3 = s1; <- error: use of deleted function ‘std::unique_ptr
    // Yep. You have to move a unique pointer
    s3 = std::move(s1);


    //std::cout << std::boolalpha << (s3 == false) << std::endl;

    // build a libSong with the non-class factory method
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

}