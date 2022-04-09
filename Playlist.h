//
// Created by ajame on 12/6/2021.
//

#ifndef LAB8_PLAYLIST_H
#define LAB8_PLAYLIST_H

#include <vector>
#include "Song.h"


class Playlist {
public:
    Playlist();

    Playlist(string pName);

    void GetPlaylist();

    string GetPlaylistName();

    void AddSong(Song* pSong);

    void RemoveSong();

    void ForceRemoveSong(Song* pSongIndex);

    void PlayPlaylist();

private:
    string playlistName;
    vector<Song*> playlist;
};


#endif //LAB8_PLAYLIST_H
