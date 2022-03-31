//
//  album.hpp
//  MusicDatabase
//
//  Created by Mary Tamry on 18.03.22.
//

#ifndef album_hpp
#define album_hpp
#include <stdio.h>
#include <string>
#include "song.hpp"
#include <vector>
using namespace std;

class album{
private:
        string albumName;
        string *artistName;
        int yRelease;
        string *genre;
        int nSongs;
        int albumID;
        vector<song*> songs;
        friend class database;

public:
       album();
       void setAlbum();
       void getAlbum() const;
};

#endif /* album_hpp */
