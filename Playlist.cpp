//
// Created by ajame on 12/6/2021.
//
#include <iostream>
#include "Playlist.h"
#include <vector>

using namespace std;

Playlist::Playlist() {
    playlistName = "Get rekt n00b";
}

Playlist::Playlist(string pName) {
    playlistName = pName;
}

void Playlist::GetPlaylist() {
    for (size_t i = 0; i < playlist.size(); i++){
        cout << playlist.at(i)->GetSongName() << ": \"" << playlist.at(i)->GetFirstLine() << "\", " <<
        playlist.at(i)->GetTimesPlayed() << " play(s)" << endl;
    }
}

string Playlist::GetPlaylistName(){
    return playlistName;
}

void Playlist::AddSong(Song* pSong) {
    playlist.push_back(pSong);
    cout << endl;
    cin.ignore();
}

void Playlist::RemoveSong() {
    int indexNum;

    for (size_t i = 0; i < playlist.size(); i++) {
        cout << "   " << i << ": " << playlist.at(i)->GetSongName() << endl;
    }

    cout << "Pick a song index number to remove: ";
    cin >> indexNum;

    playlist.erase(playlist.begin() + indexNum);
}

void Playlist::ForceRemoveSong(Song* pSongPointer) {
    for (size_t i = 0; i < playlist.size(); i++){
        if (playlist.at(i) == pSongPointer){
            playlist.erase(playlist.begin() + i);
        }
    }
}

void Playlist::PlayPlaylist() {
    cout << "Playing songs from playlist: " << playlistName << endl;
    for (size_t i = 0; i < playlist.size(); i++) {
        playlist.at(i)->AddPlay();
        cout << playlist.at(i)->GetFirstLine() << endl;
    }
    cin.ignore();
}