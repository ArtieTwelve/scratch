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
#include "../libSong/Song.h"

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
            artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
            const std::wstring& date_,
            const std::wstring& location_,
            const std::wstring& subject_) :
            date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

int main()
{
    // The examples go here, in order:
    std::cout << "SongMain start" << std::endl;
    // Example 1
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
