#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include "Album.h"

using namespace std;

list<album> listOfAlbuns;
list<album>::iterator it;

album Dark_Horse(1, "Nickelback", "Dark Horse", 2008);
album Reload (5, "Metallica", "Reload", 2003);
album Californication (11, "Red Hot Chili Peppers", "Californication", 1999);
album FashionNugget (8, "Cake", "Fashion Nugget", 1996);
album MinutesToMidnight (85, "Linkin Park", "Minutes To Midnight", 2007);

bool insertIntoList(album a){
    listOfAlbuns.push_back(a);
}
void printElements(list<album> l){
    for (it = l.begin(); it != l.end(); it++){
        it->printAlbum();
    }
}
void initializeMusicShop(){
    insertIntoList(Dark_Horse);
    insertIntoList(Reload);
    insertIntoList(Californication);
    insertIntoList(FashionNugget);
    insertIntoList(MinutesToMidnight);
}
list<album>::iterator searchAlbumTitle(list<album> &l, const string s){
    for (it = l.begin(); it != l.end(); it++){
        if (it->getAlbumTitle() == s){
            return it;
        }
    }
    return l.end();
}
list<album>::iterator searchId(list<album> &l, const int i){
    for (it = l.begin(); it != l.end(); it++){
        if (it->getIdNumber() == i){
            return it;
        }
    }
    return l.end();
}

int main()
{
    initializeMusicShop();

    while (true){
        cout << endl;
        cout << "Enter 1 to insert new album" << endl;
        cout << "Enter 2 to remove a album" << endl;
        cout << "Enter 3 to display the existing albuns sorted by band name" << endl;
        cout << "Enter 4 to diplay the existing albuns sorted by year of release" << endl;
        cout << "Enter 5 to display information about the album" << endl;
        cout << "Press ESC to close application" << endl;

        char option;
        char searchOption;
        int id;
        string bandName;
        string albumTitle;
        int yearRelease;

        cin >> option;

        if (option == 49){
            cout << "ALBUM INSERTION" << endl;
            cout << "Enter the Id number: ";
            cin >> id;
            cout << "Enter the band name: ";
            cin >> bandName;
            cout << "Enter the album title: ";
            cin >> albumTitle;
            cout << "Enter the year of release: ";
            cin >> yearRelease;
            album a(id, bandName, albumTitle, yearRelease);
            insertIntoList(a);
            cout << "Album sucessfully inserted!" << endl;
        }
        else if (option == 50){
            cout << "ALBUM DELETION" << endl;
            cout << "Enter the album title: ";
            cin >> albumTitle;
            it = searchAlbumTitle(listOfAlbuns, albumTitle);
            if (it != listOfAlbuns.end()){
                it = listOfAlbuns.erase(it);
                cout << "Album " << albumTitle << " deleted!" << endl;
            }
            else {
                cout << "That album does not exist!" << endl;
            }
        }
        else if (option == 51){
            cout << "SHOWING EXISTING ALBUNS SORTED BY BAND NAME" << endl;
            listOfAlbuns.sort([](const album &a1, const album &a2) { return a1.getBandName() < a2.getBandName();});
            printElements(listOfAlbuns);
        }
        else if (option == 52){
            cout << "SHOWING EXISTING ALBUNS SORTED BY YEAR OF RELEASE" << endl;
            listOfAlbuns.sort([](const album &a1, const album &a2) { return a1.getYearRelease() > a2.getYearRelease();});
            printElements(listOfAlbuns);
        }
        else if (option == 53){
            cout << "INFORMATION ABOUT ALBUM" << endl;
            cout << "Enter 1 to search by id number: " << endl;
            cout << "Enter 2 to search by album title: " << endl;

            cin >> searchOption;
            if (searchOption == 49){
                cout << "Enter the id number of album: ";
                cin >> id;
                it = searchId(listOfAlbuns, id);
                if (it != listOfAlbuns.end()){
                    it->printAlbum();
                }
                else {
                    cout << "Sorry, album not found!" << endl;
                }
            }
            else if (searchOption == 50){
                cout << "Enter the album title: ";
                cin >> albumTitle;
                it = searchAlbumTitle(listOfAlbuns, albumTitle);
                if (it != listOfAlbuns.end()){
                    it->printAlbum();
                }
                else{
                    cout << "Sorry, album not found!" << endl;
                }
            }
        }
        else if (option == 27){
            break;
        }
        else {
            cout << "Not a valid option, sorry!" << endl;
        }
    }
    return 0;
}
