//
//  artist.hpp
//  MusicDatabase
//
//  Created by Mary Tamry on 18.03.22.
//

#ifndef artist_hpp
#define artist_hpp

#include <stdio.h>
#include "album.hpp"
#include <string>
#include <vector>

class artist
{
    private:
        string* name;
        string* pCountry;
        int *artistID;
        vector<album*> albums;
        friend class database;
    
    public:
        artist();
        void setArtist();
        void getArtist() const;
        int getID();
        void setID(int);
};


#endif /* artist_hpp */
