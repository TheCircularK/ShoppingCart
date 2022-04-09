//
// Created by ajame on 12/6/2021.
//

#include "Song.h"
using namespace std;

//Constructor
Song::Song() {
    songName = "You're dumb";
    firstLine = "Add a freaking title you lazy bum";
    timesPlayed = 0;
}

Song::Song(string pTitle, string pFirstLine) {
    songName = pTitle;
    firstLine = pFirstLine;
    timesPlayed = 0;
}

//Song name
string Song::GetSongName() {
    return songName;
}
void Song::SetSongName(string pNewName) {
    songName = pNewName;
}

//First line
string Song::GetFirstLine() {
    return firstLine;
}
void Song::SetFirstLine(string pNewFLine) {
    firstLine = pNewFLine;
}

//Times played
int Song::GetTimesPlayed() {
    return timesPlayed;
}
void Song::AddPlay() {
    timesPlayed += 1;
}