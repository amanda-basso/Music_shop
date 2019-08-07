#include <iostream>
#include "Album.h"

album::album(int idNumber, string bandName, string albumTitle, int yearRelease){
    setIdNumber(idNumber);
    setBandName(bandName);
    setAlbumTitle(albumTitle);
    setYearRelease(yearRelease);
}
album::~album(){
    //destructor
}
void album::setIdNumber(int idNumber){
    this->idNumber = idNumber;
}
int album::getIdNumber() const{
    return idNumber;
}
void album::setBandName(string bandName){
    this->bandName = bandName;
}
string album::getBandName() const{
    return bandName;
}
void album::setAlbumTitle(string albumTitle){
    this->albumTitle = albumTitle;
}
string album::getAlbumTitle() const{
    return albumTitle;
}
void album::setYearRelease(int yearRelease){
    this->yearRelease = yearRelease;
}
int album::getYearRelease() const{
    return yearRelease;
}
void album::printAlbum() const{
    printf("ID Number: ");
    cout << getIdNumber() << endl;

    printf("Band Name: ");
    cout << getBandName() << endl;

    printf("Album Title: ");
    cout << getAlbumTitle() << endl;

    printf("Year of release: ");
    cout << getYearRelease() << endl;

    cout << endl;
}
