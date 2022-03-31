//
//  Mdatabase.hpp
//  MusicDatabase
//
//  Created by Mary Tamry on 19.03.22.
//

#ifndef Mdatabase_hpp
#define Mdatabase_hpp

#include <stdio.h>
#include "artist.hpp"
#include <vector>

class database: public artist{
private:
    vector<artist*> artists;
    vector<string*> genres;
    int songID, albumID;
public:
    database();
    void addArtist();
    void addAlbum(artist*);
    void addSong(album*);
    void removeArtist();
    void removeAlbum();
    void removeSong();
    void getAllArtists() const;
    void getAllAlbums() const;
    void getAllSongs() const;
    void searchArtists() const;
    void searchAlbums() const;
    void searchSongs() const;
    void addGenre();
    void findByIDArtist();
    void findByIDAlbum();
    void findByIDSong();
    void exportFun();
    void importFun();
    artist* chooseArtist();
    album* chooseAlbum();
    song* chooseSong();
    string* chooseGenre();
};

#endif /* Mdatabase_hpp */
