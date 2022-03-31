//
//  main.cpp
//  MusicDatabase
//
//  Created by Mary Tamry on 18.03.22.
//

#include <iostream>
#include "Mdatabase.hpp"
class database;
int main(){

    database* a = new database;
    int choice;
    bool continueProg = true, firstAdd = false, firstArtist = false, firstAlbum = false, firstSong = false;

while(continueProg == true){
    cout << "Please choose from the bellow menu of choices: " << endl;
    cout << "1. Add" << endl;
    cout << "2. Search" << endl;
    cout << "3. Remove" << endl;
    cout << "4. Print All" << endl;
    cout << "5. Export" << endl;
    cout << "6. Import" << endl;
    cout << "7. Exit" << endl;
    cin >> choice;
    while(firstAdd == false && choice != 1){
        if(choice == 7){
            break;
        }
        cout << "You must add an artist first or exit, Please enter 1 or 7 to add or exit" << endl;
        cin >> choice;
        }
    firstAdd = true;
    switch (choice) {
        case 1:{
            int addChoice;
            cout << "Please choose what you want to add " << endl;
            cout << "1. Artist" << endl;
            cout << "2. Album" << endl;
            cout << "3. Song" << endl;
            cout << "4. Exit" << endl;
            cin >> addChoice;
            while(firstArtist == false && addChoice == 2){
                cout << "You must add an artist first or exit, Please enter 1 or 4 to add an artist or exit" << endl;
                cin >> addChoice;
            }
            while(firstAlbum == false && addChoice == 3){
                cout << "You must add an album first or exit, Please enter 2 or 4 to add an album or exit" << endl;
                cin >> addChoice;
            }
            switch (addChoice) {
                case 1:
                    a->addArtist();
                    firstArtist = true;
                    break;
                case 2:{
                    artist* temp = a->chooseArtist();
                    a->addAlbum(temp);
                    firstAlbum = true;
                    break;
                }
                case 3:{
                    album* temp = a->chooseAlbum();
                    a->addSong(temp);
                    firstSong = true;
                    break;
                }
                case 4:
                    continueProg = false;
                    break;
               
                default:
                    continueProg = false;
                    break;
            }
            break;
        }
        case 2:{
            int typeChoice;
            cout << "Please choose the type of search " << endl;
            cout << "1. By Name" << endl;
            cout << "2. By ID" << endl;
            cout << "3. Exit" << endl;
            cin >> typeChoice;
            switch (typeChoice) {
                case 1:
                {
                    int searchChoice;
                    cout << "Please choose what you want to search for " << endl;
                    cout << "1. Artist" << endl;
                    cout << "2. Album" << endl;
                    cout << "3. Song" << endl;
                    cout << "4. Exit" << endl;
                    cin >> searchChoice;
                    while(firstAlbum == false && (searchChoice == 2 ||searchChoice == 3)){
                        cout << "There are no albums. You must add an album first, Please search for an aritst or exit the program by typing 1 or 4" << endl;
                        cin >> searchChoice;
                    }
                    while(firstSong == false && searchChoice == 3){
                        cout << "There are no songs. You must add a song first, Please search for an aritst/album or exit the program by typing 1, 2, or 4" << endl;
                        cin >> searchChoice;
                    }
                    
                    switch (searchChoice) {
                        case 1:{
                            a->searchArtists();
                            break;
                        }
                        case 2:{
                            a->searchAlbums();
                            break;
                        }
                        case 3:{
                            a->searchSongs();
                            break;
                        }
                        case 4:
                            continueProg = false;
                            break;
                        default:
                            continueProg = false;
                            cout << "Not a valid option, program will exit." << endl;
                            break;
                        }
                        break;
                    }
                case 2:
                {
                    int searchChoice;
                    cout << "Please choose what you want to search for " << endl;
                    cout << "1. Artist" << endl;
                    cout << "2. Album" << endl;
                    cout << "3. Song" << endl;
                    cout << "4. Exit" << endl;
                    cin >> searchChoice;
                    while(firstAlbum == false && (searchChoice == 2 ||searchChoice == 3)){
                        cout << "There are no albums. You must add an album first, Please search for an aritst or exit the program by typing 1 or 4" << endl;
                        cin >> searchChoice;
                    }
                    while(firstSong == false && searchChoice == 3){
                        cout << "There are no songs. You must add a song first, Please search for an aritst/album or exit the program by typing 1, 2, or 4" << endl;
                        cin >> searchChoice;
                    }
                    switch (searchChoice) {
                        case 1:{
                            a->findByIDArtist();
                            break;
                        }
                        case 2:{
                            a->findByIDAlbum();
                            break;
                        }
                        case 3:{
                            a->findByIDSong();
                            break;
                        }
                        case 4:
                            continueProg = false;
                            break;
                        default:
                            continueProg = false;
                            cout << "Not a valid option, program will exit." << endl;
                            break;
                        }
                        break;
                    }
                case 3:
                    cout << "Program is exited" << endl;
                    break;
                default:
                    continueProg = false;
                    cout << "Not a valid option, program will exit." << endl;
                    break;
            }
            break;
        }
        case 3:{
            int removeChoice;
            cout << "Please choose what you want to remove " << endl;
            cout << "1. Artist" << endl;
            cout << "2. Album" << endl;
            cout << "3. Song" << endl;
            cout << "4. Exit" << endl;
            cin >> removeChoice;
            while(firstAlbum == false && (removeChoice == 2 ||removeChoice == 3)){
                cout << "There are no albums. Exit the program by typing 1 or 4" << endl;
                cin >> removeChoice;
            }
            while(firstSong == false && removeChoice == 3){
                cout << "There are no songs. You must add a song first, Please search for an aritst/album or exit the program by typing 1, 2, or 4" << endl;
                cin >> removeChoice;
            }
            switch (removeChoice) {
                case 1:{
                    a->removeArtist();
                    break;
                }
                case 2:{
                    a->removeAlbum();
                    break;
                }
                case 3:{
                    a->removeSong();
                    break;
                }
                case 4:
                    cout << "Program will exit" << endl;
                    continueProg = false;
                    break;
                default:
                    continueProg = false;
                    cout << "Not a valid option, program will exit." << endl;
                    break;
                }
                break;
        }
            break;
            case 4:{
                int getChoice;
                cout << "Please choose what you want to get all information for " << endl;
                cout << "1. Artists" << endl;
                cout << "2. Albums" << endl;
                cout << "3. Songs" << endl;
                cout << "4. Exit" << endl;
                cin >> getChoice;
                    while(firstAlbum == false && (getChoice == 2 ||getChoice == 3)){
                        cout << "There are no albums. You must add an album first, Please print all aritsts or exit the program by typing 1 or 4" << endl;
                        cin >> getChoice;
                    }
                    while(firstSong == false && getChoice == 3){
                        cout << "There are no songs. You must add a song first, Please print all aritst/album or exit the program by typing 1, 2, or 4" << endl;
                        cin >> getChoice;
                    }
                switch (getChoice) {
                    case 1:
                        a->getAllArtists();
                        break;
                    case 2:
                        a->getAllAlbums();
                        break;
                    case 3:
                        a->getAllSongs();
                        break;
                    case 4:
                        continueProg = false;
                        cout << "Program is exited" << endl;
                        break;
                    default:
                        continueProg = false;
                        cout << "Not a valid option, program will exit." << endl;
                        break;
                }
        }
            break;
        case 5:
            a->exportFun();
            break;

        case 6:
            a->importFun();
            break;

        case 7:
            continueProg = false;
            cout << "Program is exited" << endl;
            break;
        default:
            continueProg = false;
            cout << "Not a valid option, program will exit." << endl;
            break;

}
}
}
