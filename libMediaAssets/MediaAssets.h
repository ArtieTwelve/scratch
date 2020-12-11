//
// Created by smithla on 12/11/20.
//
#include <iostream>
#include <memory>

#ifndef SCRATCH_MEDIAASSETS_H
#define SCRATCH_MEDIAASSETS_H


struct MediaAsset {
    virtual ~MediaAsset() = default;
};

struct Photo : public MediaAsset {
    std::wstring _date;
    std::wstring _location;
    std::wstring _subject;

    Photo();
    Photo(const std::wstring& date,
          const std::wstring& location,
          const std::wstring subject) :
            _date(date),_location(location),_subject(subject) {}

    virtual ~Photo();
    Photo(const Photo&);
    Photo(Photo&&);
    Photo& operator=(const Photo&);
    Photo& operator=(Photo&&);


};

class Song : public MediaAsset {
public:
    Song();
    Song(std::wstring artist,std::wstring title);
    virtual ~Song();
    Song(const Song&);
    Song(Song&&);
    Song& operator=(const Song&);
    Song& operator=(Song&&);


    std::wstring getTitle();
    std::wstring  getArtist();

private:
    std::wstring _title, _artist;

};

std::unique_ptr<Song> SongFactory(std::wstring artist, std::wstring title);


#endif //SCRATCH_MEDIAASSETS_H
