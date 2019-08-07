#ifndef ALBUM_H
#define ALBUM_H
#include <string>

using namespace std;

class album {
public:
    album(int idNumber, string bandName, string albumTitle, int yearRelease);
    ~album();
    int getIdNumber() const;
    void setIdNumber(int idNumber);
    string getBandName() const;
    void setBandName(string bandName);
    string getAlbumTitle() const;
    void setAlbumTitle(string albumTitle);
    int getYearRelease() const;
    void setYearRelease(int yearRelease);
    void printAlbum() const;
private:
    int idNumber;
    string bandName;
    string albumTitle;
    int yearRelease;
};

#endif //ALBUM_H
