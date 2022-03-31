//
//  Mdatabase.cpp
//  MusicDatabase
//
//  Created by Mary Tamry on 19.03.22.
//

#include "Mdatabase.hpp"
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>

database::database(){
    vector <artist> artists;
    vector <string*> genres;
    int songID = 0;
    int albumID = 0;
};

void database::addArtist(){
    artist* artistTemp = new artist();
    artists.push_back(artistTemp);
    artistTemp->setArtist();
    artistTemp->setID(artists.size());
};

void database::addAlbum(artist* artistA){
    album* albumTemp = new album();
    artistA->albums.push_back(albumTemp);
    albumTemp->setAlbum();
    albumTemp->artistName = artistA->name;
    string* genreTemp = new string;
    genreTemp = chooseGenre();
    albumTemp->genre = genreTemp;
    albumTemp->albumID = albumID+1;
    albumID++;
}

void database::addSong(album* albumA){
    song* songTemp = new song();
    albumA->songs.push_back(songTemp);
    songTemp->setSong();
    songTemp->songAlbum = albumA;
    songTemp->albumName = &(albumA->albumName);
    int temp = songID+1;
    songTemp->songID = &temp;
    songID++;
    *songTemp->tNum = albumA->songs.size();
    albumA->nSongs = (albumA->nSongs)+1;
}

void database::getAllArtists() const{
    for(int i = 0; i < artists.size(); i++){
        artists[i]->getArtist();
        cout << endl;
    }
};

void database::getAllAlbums() const{
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
            artists[i]->albums[j]->getAlbum();
            cout << endl;
        }
    }
}

void database::getAllSongs() const{
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
            for(int k = 0; k < artists[i]->albums[j]->songs.size(); k++){
                artists[i]->albums[j]->songs[k]->getSong();
                cout << endl;
            }
        }
    }
}

void database::searchArtists() const{
    string artistName;
    cout << "Please enter the artist name you want to search for " << endl;
    cin >> artistName;
    cout << endl;
    for(int i = 0; i < artists.size(); i++){
        string temp = *artists[i]->name;
        if(strncasecmp(temp.c_str(), artistName.c_str(), 20) == 0){
            artists[i]->getArtist();
            cout << endl;
        }
    }
};

void database::searchAlbums() const{
    string albumTemp;
    cout << "Please enter the album name you want to search for " << endl;
    cin >> albumTemp;
    cout << endl;
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
            if(strncasecmp(artists[i]->albums[j]->albumName.c_str(), albumTemp.c_str(), 20) == 0){
                artists[i]->albums[j]->getAlbum();
                cout << endl;
            }
        }
    }
};

void database::searchSongs() const{
    string songTemp;
    cout << "Please enter the song name you want to search for " << endl;
    cin >> songTemp;
    cout << endl;
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
            for(int k = 0; k < artists[i]->albums[j]->songs.size(); k++){
                if(strncasecmp((*(artists[i]->albums[j]->songs[j]->pSongName)).c_str(), songTemp.c_str(), 20) == 0){
                    artists[i]->albums[j]->songs[k]->getSong();
                    cout << endl;
                }
            }
        }
    }
}

void database::addGenre(){
    string* temp = new string;
    bool found = true;
    cout << "Bellow are the existing genres, please enter a different genre: " << endl << endl;
    for(int i = 0; i < genres.size(); i++){
        cout << *genres[i] << endl;
    }
    while(found == true ){
        int j = 0;
        cout << "Please enter the name of the genre" << endl;
        cin >> *temp;
    for(int i = 0; i < genres.size(); i++){
        if(*genres[i] == *temp){
            found = true;
            j++;
        }
        }
        if(j == 0){
            found = false;
        }
    
    }
    genres.push_back(temp);
}

void database::findByIDArtist(){
    int enteredID;
    cout << "Please enter the artist ID you want to find" << endl;
    cin >> enteredID;
    cout << endl;
    for(int i = 0; i < artists.size(); i++){
        if(enteredID == *(artists[i]->artistID)){
            artists[i]->getArtist();
            cout << endl;
        }
    }
}

void database::findByIDAlbum(){
    int enteredID;
    cout << "Please enter the Album ID " << endl;
    cin >> enteredID;
    cout << endl;
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
            if(enteredID == artists[i]->albums[j]->albumID){
                artists[i]->albums[j]->getAlbum();
                cout<< endl;
            }
        }
    }
}

void database::findByIDSong(){
    int enteredID;
    cout << "Please enter the Song ID" << endl;
    cin >> enteredID;
    cout << endl;
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
            for(int k = 0; k < artists[i]->albums[j]->songs.size(); k++){
                if(enteredID == *artists[i]->albums[j]->songs[k]->songID){
                    artists[i]->albums[j]->songs[k]->getSong();
                    cout << endl;
                }
            }
        }
    }
}

string* database::chooseGenre(){
    int j = 0;
    while(j == 0){
    cout << "Genres: " << endl;
    for(int i = 0; i < genres.size(); i++){
        cout << i+1 << ". " << *genres[i] << endl;
    }
    cout << "Please type the number of the genre " << endl;
    cout << "If the genre is not there please type 0 to add a genre" << endl;
    cin >> j;
    if(j == 0){
        addGenre();
    }
    }
    return genres[j-1];
}

void database::removeArtist(){
    artist* temp = chooseArtist();
    for(int i = 0; i < temp->albums.size(); i++){
        temp->albums[i]->songs.clear();
        }
    temp->albums.clear();
    for(int k = 0; k < artists.size(); k++){
        if(artists[k] == temp){
            cout << "Artist number " << *artists[k]->artistID<< " is removed." << endl;
            artists.erase(artists.begin()+k);
        }
    }
}

void database::removeAlbum(){
    album* temp = chooseAlbum();
    temp->songs.clear();
    for(int k = 0; k < artists.size(); k++){
        for(int i = 0; i < artists[k]->albums.size(); i++){
            if(artists[k]->albums[i] == temp){
                cout << "Album number " << artists[k]->albums[i]->albumID<< " is removed." << endl;
                artists[k]->albums.erase(artists[k]->albums.begin()+k);
            }
        }
    }
}

void database::removeSong(){
    song* temp = chooseSong();
    for(int i = 0; i < artists.size(); i++){
        for(int k = 0; k < artists[i]->albums.size(); k++){
            for(int j = 0; j < artists[i]->albums[k]->songs.size(); j++){
                if(temp == artists[i]->albums[k]->songs[j]){
                    cout << "Song number " << *artists[i]->albums[k]->songs[j]->songID << " is removed." << endl;
                    artists[i]->albums[k]->songs.erase(albums[k]->songs.begin()+j);
                    artists[i]->albums[k]->nSongs = (artists[i]->albums[k]->nSongs)-1;
                }
            }
        }
    }
}

artist* database::chooseArtist(){
    int temp;
    artist* artistTemp = NULL;
    getAllArtists();
    cout << "Please enter the ID of the artist you want to choose" << endl;
    cin >> temp;
    for(int i = 0; i < artists.size(); i++){
        if(temp == *artists[i]->artistID){
            artistTemp = artists[i];
        }
    }
    return artistTemp;
}

album* database::chooseAlbum(){
    int temp;
    album* albumTemp = NULL;
    getAllAlbums();
    cout << "Please enter the ID of the album you want to choose" << endl;
    cin >> temp;
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
        if(temp == artists[i]->albums[j]->albumID){
            albumTemp = artists[i]->albums[j];
            }
        }
    }
    return albumTemp;
}

song* database::chooseSong(){
    int temp;
    song* songTemp = NULL;
    getAllSongs();
    cout << "Please enter the ID of the album you want to choose" << endl;
    cin >> temp;
    for(int i = 0; i < artists.size(); i++){
        for(int j = 0; j < artists[i]->albums.size(); j++){
            for(int k = 0; k < artists[i]->albums[j]->songs.size(); k++){
                if(temp == *artists[i]->albums[j]->songs[k]->songID){
                    songTemp = artists[i]->albums[j]->songs[k];
                    }
            }
        }
    }
    return songTemp;
}

void database::exportFun(){
    int artistLineNum = 1;
    int albumLineNum = 1;
    int songLineNum = 1;
    string fileName;
    cout << "Please enter the text file name " << endl;
    cin>>fileName;
    cout << endl << endl;
    ofstream file(fileName+".txt");
    if(file.is_open()){
        for(int i = 0; i < artists.size(); i++){
            file << "->Artist Details: " << endl;
            file << "A" << artistLineNum++ << " Artist Name: " << *artists[i]->name << endl;
            file << "A" << artistLineNum++ << " Country: " << *artists[i]->pCountry<< endl;
            file << "A" << artistLineNum++ << " Artist ID: " << *artists[i]->artistID<< endl;
            file << endl;
            artistLineNum = artistLineNum%3;
            for(int j = 0; j < artists[i]->albums.size(); j++){
                file << '\t' << "->Album Details: "<< endl;
                file << "B" << albumLineNum++ << '\t' << "Album Name: " << artists[i]->albums[j]->albumName<< endl;
                file << "B" << albumLineNum++ << '\t' << "Release Year: " << artists[i]->albums[j]->yRelease<< endl;
                file <<"B" << albumLineNum++ << '\t' << "Genre: " << *artists[i]->albums[j]->genre<< endl;
                file <<"B" << albumLineNum++ << '\t' << "Number of songs: " << artists[i]->albums[j]->nSongs<< endl;
                file <<"B" << albumLineNum++ << '\t' << "Album ID: " << artists[i]->albums[j]->albumID<< endl;
                file << endl;
                albumLineNum = albumLineNum%5;
                for(int k = 0; k < artists[i]->albums[j]->songs.size(); k++){
                    file<<'\t' << '\t' << "->Song Details: " << endl;;
                    file<< "C" << songLineNum++ << '\t' << '\t' <<"Song Name: " << *artists[i]->albums[j]->songs[k]->pSongName<< endl;
                    file<<"C" << songLineNum++ <<'\t' << '\t' <<"Song Duration: " << artists[i]->albums[j]->songs[k]->mDuration << " minutes"<< endl;
                    file<<"C" << songLineNum++ <<'\t' << '\t' <<"Track Number: " << *artists[i]->albums[j]->songs[k]->tNum<< endl;
                    file<<"C" << songLineNum++ <<'\t' << '\t' <<"Version: " << artists[i]->albums[j]->songs[k]->editVersion<< endl;
                    file<<"C" << songLineNum++ <<'\t' << '\t' <<"Song ID: " << *artists[i]->albums[j]->songs[k]->songID<< endl;
                    file << endl;
                    songLineNum = songLineNum%5;
                }
            }
        }
        file.close();
    }
}

void database::importFun(){
    string fileName, line;
    cout << "Please enter the text file name " << endl;
    cin>>fileName;
    cout << endl;
    ifstream file(fileName+".txt");
    if(file.is_open()){
        while (getline(file,line)) {
            int length = line.length();
            int ansLength;
            string tempStr;
            switch (line[0]) {
                case 'A':
                    artist* temp = new artist();
                    artists.push_back(temp);
                    switch (line[1]) {
                        case 1:
                            ansLength = 16;
                            tempStr = line.substr(ansLength,length-ansLength);
                            *temp->name = tempStr;
                            break;
                        case 2:
                            ansLength = 12;
                            tempStr = line.substr(ansLength,length-ansLength);
                            *temp->pCountry = tempStr;
                        case 3:
                            ansLength = 14;
                            tempStr = line.substr(ansLength,length-ansLength);
                            *temp->artistID = stoi(tempStr);
                        default:
                            break;
                    }
                break;
                case 'B':
                    {
                        
                        }
                    break;
                case 'C':
                {
                    
                }
                    break;
                default:
                    break;
            }
        }
        file.close();
    }
}


