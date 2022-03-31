//
//  album.cpp
//  MusicDatabase
//
//  Created by Mary Tamry on 18.03.22.
//

#include "album.hpp"
#include <iostream>

album::album(){
    albumName = ' ';
    artistName = NULL;
    yRelease = 0000;
    genre = NULL;
    nSongs = 0;
    albumID = 0;
    vector <song*> songs;
};

void album::setAlbum(){
    cout << "Please enter the name of the album " << endl;
    cin >> albumName;
    cout << "Please enter the year of release " << endl;
    cin >> yRelease;
}

void album::getAlbum() const{
    cout << "Album Details: " <<endl << endl;
    cout << "Album Name: " << albumName <<endl;
    cout << "Artist Name: " << *artistName <<endl;
    cout << "Release Year: " << yRelease <<endl;
    cout << "Genre: " << *genre <<endl;
    cout << "Number of songs: " << nSongs <<endl;
    cout << "Album ID: " << albumID <<endl;
}
