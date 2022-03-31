//
//  artist.cpp
//  MusicDatabase
//
//  Created by Mary Tamry on 18.03.22.
//

#include "artist.hpp"
#include <iostream>
using namespace std;

artist::artist(){
    name = new string;
    pCountry = new string;
    artistID = new int;
    vector<album*> albums;
    vector<int> albumIDIndex;
}

void artist::setArtist(){
cout << "Please enter the artist's name: " << endl;
cin >> *name;
cout << "Please enter the artist's country: " << endl;
cin >> *pCountry;
};

int artist::getID(){
    return *artistID;
}

void artist::setID(int num){
    *artistID = num;
}

void artist::getArtist() const{
    cout << "Artist Details: " <<endl;
    cout << "Artist Name: " << *name <<endl;
    cout << "Country: " << *pCountry <<endl;
    cout << "Artist ID: " << *artistID <<endl;
}
