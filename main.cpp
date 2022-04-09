//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>

#include "Song.h"
#include "Playlist.h"

using namespace std;

//Andrew James and Dean Van Woerkom

string GetUserString(const string& prompt);
int GetUserInt(const string& prompt);

int main() {
    //Variables

    //Vectors
    vector<Song*> songLibrary;
    vector<Playlist*> myPlaylists;

    cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

    string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            const string DONE_KEYWORD = "DONE";
            cout << "Enter songs' names and first lines"
                      << " (type \"" << DONE_KEYWORD << "\" when done):" << endl;

            string songName = "none";
            string firstLine = "none";

            songName = GetUserString("Song Name: ");
            while (songName != DONE_KEYWORD) {
                firstLine = GetUserString("Song's first line: ");
                Song *newSong = new Song(songName, firstLine);
                songLibrary.push_back(newSong);
                songName = GetUserString("Song Name: ");
            }
        }

        else if (userMenuChoice == "list") {
            for (size_t i = 0; i < songLibrary.size(); i++) {
                cout << songLibrary.at(i)->GetSongName() << ": \"" << songLibrary.at(i)->GetFirstLine() << "\", " <<
                     songLibrary.at(i)->GetTimesPlayed() << " play(s)." << endl;
            }
        }

        else if (userMenuChoice == "addp") {
            string tempName;
            tempName = GetUserString("Playlist name: ");
            Playlist* newList = new Playlist(tempName);
            myPlaylists.push_back(newList);
        }
        else if (userMenuChoice == "addsp") {
            int listIndexNum;
            int songIndexNum;
            for (size_t i = 0; i < myPlaylists.size(); i++){
                cout << i << ": " << myPlaylists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number: ";
            cin >> listIndexNum;
            cout << endl;


            for (size_t i = 0; i < songLibrary.size(); i++){
                cout << i << ": " << songLibrary.at(i)->GetSongName() << endl;
            }

            cout << "Pick a song index number: ";
            cin >> songIndexNum;

            myPlaylists.at(listIndexNum)->AddSong(songLibrary.at(songIndexNum));

        }
        else if (userMenuChoice == "listp") {
            for (size_t i = 0; i < myPlaylists.size(); i++){
                cout << i << ": " << myPlaylists.at(i)->GetPlaylistName() << endl;
            }
        }

        else if (userMenuChoice == "play") {
            int listIndexNum;
            for (size_t i = 0; i < myPlaylists.size(); i++){
                cout << i << ": " << myPlaylists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number: ";
            cin >> listIndexNum;
            cout << endl;
            myPlaylists.at(listIndexNum)->PlayPlaylist();
            cout << endl;
        }

        else if (userMenuChoice == "remp") {
            int listIndexNum;
            for (size_t i = 0; i < myPlaylists.size(); i++){
                cout << i << ": " << myPlaylists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number to remove: ";
            cin >> listIndexNum;
            cout << endl;
            cin.ignore();

            delete myPlaylists.at(listIndexNum);
            myPlaylists.erase(myPlaylists.begin() + listIndexNum);
        }
        else if (userMenuChoice == "remsp") {
            int listIndexNum;
            int songIndexNum;
            for (size_t i = 0; i < myPlaylists.size(); i++){
                cout << i << ": " << myPlaylists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number: ";
            cin >> listIndexNum;
            cout << endl;

            myPlaylists.at(listIndexNum)->RemoveSong();
        }

        else if (userMenuChoice == "remsl") {
            int remIndex;
            Song* songIndex;

            //Print all songs
            for (size_t i = 0; i < songLibrary.size(); i++) {
                cout << i << ": " << songLibrary.at(i)->GetSongName() << endl;
            }
            cout << "Pick a song index number to remove: ";
            cin >> remIndex;
            cout << endl;

            //Get pointer to song
            songIndex = songLibrary.at(remIndex);

            for (size_t i = 0; i < myPlaylists.size(); i++) {
                myPlaylists.at(i)->ForceRemoveSong(songIndex);
            }
            delete songLibrary.at(remIndex);
            songLibrary.erase(songLibrary.begin() + remIndex);
        }

        else if (userMenuChoice == "options") {
            cout  << "add      Adds a list of songs to the library" << endl
                  << "list     Lists all the songs in the library" << endl
                  << "addp     Adds a new playlist" << endl
                  << "addsp    Adds a song to a playlist" << endl
                  << "listp    Lists all the playlists" << endl
                  << "play     Plays a playlist" << endl
                  << "remp     Removes a playlist" << endl
                  << "remsp    Removes a song from a playlist" << endl
                  << "remsl    Removes a song from the library (and all playlists)" << endl
                  << "options  Prints this options menu" << endl
                  << "quit     Quits the program" << endl << endl;
        }
        else if (userMenuChoice == "quit") {
            cout << "Goodbye!" << endl;
            //Delete everything
            for (size_t i = 0; i < myPlaylists.size(); i++) {
                delete myPlaylists.at(i);
            }
            for (size_t i = 0; i < songLibrary.size(); i++) {
                delete songLibrary.at(i);
            }

            continueMenuLoop = false;
        }
        else {
            std::cout << "add      Adds a list of songs to the library" << std::endl
                      << "list     Lists all the songs in the library" << std::endl
                      << "addp     Adds a new playlist" << std::endl
                      << "addsp    Adds a song to a playlist" << std::endl
                      << "listp    Lists all the playlists" << std::endl
                      << "play     Plays a playlist" << std::endl
                      << "remp     Removes a playlist" << std::endl
                      << "remsp    Removes a song from a playlist" << std::endl
                      << "remsl    Removes a song from the library (and all playlists)" << std::endl
                      << "options  Prints this options menu" << std::endl
                      << "quit     Quits the program" << std::endl << std::endl;
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    if (userAnswer == ""){
        std::getline(std::cin, userAnswer);
    }
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

