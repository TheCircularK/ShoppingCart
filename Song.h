//
// Created by ajame on 12/6/2021.
//

#ifndef LAB8_SONG_H
#define LAB8_SONG_H
#include <string>
using namespace std;

class Song {
private:
    string songName;
    string firstLine;
    unsigned int timesPlayed;

public:
    //Constructors
    Song();
    Song(string pTitle, string pFirstLine);

    //Song name
    string GetSongName();
    void SetSongName(string pNewName);

    //First line
    string GetFirstLine();
    void SetFirstLine(string pNewFLine);

    //Times played
    int GetTimesPlayed();
    void AddPlay();

};


#endif //LAB8_SONG_H
