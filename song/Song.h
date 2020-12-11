//
// Created by smithla on 12/10/20.
//
#include <iostream>
#include <memory>
#ifndef SCRATCH_SONG_H
#define SCRATCH_SONG_H


class Song {
public:
    Song();
    Song(std::string artist,std::string title);
    virtual ~Song();
    Song(const Song&);
    Song(Song&&);
    Song& operator=(const Song&);
    Song& operator=(Song&&);

    std::string getTitle();
    std::string  getArtist();

private:
    std::string _title, _artist;

};

std::unique_ptr<Song> SongFactory(std::string artist, std::string title);

#endif //SCRATCH_SONG_H
