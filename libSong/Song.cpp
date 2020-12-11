//

#include "Song.h"

std::unique_ptr<Song> SongFactory(std::string artist, std::string title) {
    return std::make_unique<Song>(artist,title);
}


Song::Song() {
 std::cout << "  Default Constructor" << std::endl;
}

Song::~Song() {
    std::cout << "  Destructor: ";
    if(this->_artist == "")
        std::cout << " Object: Default\n";
    else
        std::cout << " Object: " << this->_artist << std::endl;
}
Song::Song(std::string artist, std::string title) :_artist(artist),_title(title){
    std::cout << "  Artist, Title Constructor" << std::endl;
}

Song::Song(const Song &) {
    std::cout << "  Copy Constructor" << std::endl;
}

Song::Song(Song &&) {
    std::cout << "  Move Copy Constructor" << std::endl;
}

Song &Song::operator=(const Song & other) {
    std::cout << "  Copy Assigment Operator" << std::endl;
    _title = other._title;
    _artist = other._artist;
    return *this;
}

//
// Created by smithla on 12/10/20.
Song &Song::operator=(Song && other) {
    std::cout << "Move Assignment Operator" << std::endl;
    _title = std::move(other._title);
    _artist = std::move(other._artist);
    //other = nullptr;
    return *this;
}

std::string Song::getTitle() {
    return _title;
}

std::string  Song::getArtist() {
    return _artist;
}


