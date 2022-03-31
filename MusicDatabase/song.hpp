//
//  song.hpp
//  MusicDatabase
//
//  Created by Mary Tamry on 18.03.22.
//

#ifndef song_hpp
#define song_hpp

#include <stdio.h>
#include <string>
class album;
using namespace std;

class song
{
    private:
        string* pSongName;
        int* tNum;
        int* songID;
        int mDuration; //Minutes
        album* songAlbum;
        string* albumName;
        float editVersion;
        friend class database;

    public:
        song();
        void setSong();
        void getSong() const;
};

#endif /* song_hpp */
