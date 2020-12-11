//
// Created by smithla on 12/11/20.
//

#include "MediaAssets.h"


std::unique_ptr<Song> SongFactory(std::wstring artist, std::wstring title) {
    return std::make_unique<Song>(artist,title);
}


Song::Song() {
    std::cout << "  Default Constructor" << std::endl;
}

Song::~Song() {
    std::cout << "  Destructor: ";
    if(this->_artist == L"")
        std::cout << " Object: Default\n";
    else
        std::wcout << " Object: " << this->_artist << "\n";
}
Song::Song(std::wstring artist, std::wstring title) :_artist(artist),_title(title){
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

std::wstring Song::getTitle() {
    return _title;
}

std::wstring  Song::getArtist() {
    return _artist;
}


Photo::~Photo() {
    std::cout << "Destructor" << std::endl;

}

Photo::Photo(const Photo & other) {
    std::cout << "Copy Constructor" << std::endl;
    _date = other._date;
    _location = other._location;
    _subject = other._subject;
}

Photo::Photo(Photo &&other) {
    std::cout << "Move Constructor" << std::endl;
    _date = other._date;
    _location = other._location;
    _subject = other._subject;
    other._date = L"";
    other._location = L"";
    other._subject = L"";
}

Photo &Photo::operator=(const Photo &other) {
    std::cout << "Copy Assignment" << std::endl;
    _date = other._date;
    _location = other._location;
    _subject = other._subject;
    return *this;
}

Photo &Photo::operator=(Photo &&other) {
    std::cout << "Move Assignment" << std::endl;
    _date = other._date;
    _location = other._location;
    _subject = other._subject;
    other._date = L"";
    other._location = L"";
    other._subject = L"";
    return *this;
}

Photo::Photo() {
    std::cout << "Default Constructor" << std::endl;
}
