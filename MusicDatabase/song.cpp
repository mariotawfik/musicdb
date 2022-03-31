//
//  song.cpp
//  MusicDatabase
//
//  Created by Mary Tamry on 18.03.22.
//

#include "song.hpp"
#include <iostream>
using namespace std;

song::song(){
    pSongName = new string;
    tNum = new int;
    mDuration = 0;
    songAlbum = NULL;
    albumName = NULL;
    editVersion = 1;
    songID = NULL;
};

void song::setSong(){
    cout << "Please enter the song name" << endl;
    cin >> *pSongName;
    cout << "Please enter the duration of the song in minutes" << endl;
    cin >> mDuration;
    editVersion = editVersion+0.1;
}

void song::getSong() const{
    cout<< "Song Details: " << endl;
    cout<< "Song Name: " << *pSongName << endl;
    cout<< "Song Duration: " << mDuration << " minutes" << endl;
    cout<< "Track Number: " << *tNum << endl;
    cout<< "Version: " << editVersion << endl;
    cout << "Album Name: " << *albumName << endl;
    cout << "Song ID: " << *songID << endl;
}


