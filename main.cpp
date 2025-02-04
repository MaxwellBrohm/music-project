// Maxwell Brohm and Zander Leon
// Music Playlist Project
// 2/3/2025
// Extra: Allows user to skip to next song or go back to previous song 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void showMenu();
void showSongs(vector<string> songs);
void playSongs(vector<string> playlist, int &currentSongIndex);
void playShuffle(vector<string> playlist);
void skipSong(int &currentSongIndex, vector<string> &playlist);
void previousSong(int &currentSongIndex, vector<string> &playlist);

int main() {
    vector<string> predefinedSongs = {
        "Timely",
        "C418 - Sweden - Minecraft Volume Alpha",
        "Ending Theme - Super Mario: World",
        "Animal Crossing New Horizons - Main Theme Song",
        "Night Theme 1 Hour (Adopt Me! OST)",
        "Fortnite | Festive Lobby Music (C1S7 Battle Pass)",
        "The Legend Of Zelda Ocarina Of Time 3D OST",
        "Windmill Hut - The Legend of Zelda: Ocarina Of Time",
        "Zelda Ocarina of Time Music Great Fairy Fountain"
    };
    vector<string> playlist;
    int choice;
    srand(time(0)); // Seed random number generator with current time

    printf("Welcome to the Playlist Creator!\n");

    int currentSongIndex = -1;

    do {
        showMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        if (choice == 1) {
            showSongs(predefinedSongs);
            int songChoice;
            printf("Enter song number: ");
            scanf("%d", &songChoice);
            getchar();
            if (songChoice >= 1 && songChoice <= predefinedSongs.size()) {
                playlist.push_back(predefinedSongs[songChoice - 1]);
                printf("Added %s\n", predefinedSongs[songChoice - 1].c_str());
            } else {
                printf("Invalid choice.\n");
            }
        } else if (choice == 2) {
            char newSong[100];
            printf("Enter song title: ");
            fgets(newSong, sizeof(newSong), stdin);
            playlist.push_back(string(newSong));
            printf("Added %s\n", newSong);
        } else if (choice == 3) {
            if (playlist.empty()) {
                printf("Playlist is empty!\n");
            } else {
                currentSongIndex = 0; // Start playing from the first song
                playSongs(playlist, currentSongIndex);
            }
        } else if (choice == 4) {
            if (playlist.empty()) {
                printf("Playlist is empty!\n");
            } else {
                // Shuffle the playlist manually using rand()
                playShuffle(playlist);
                currentSongIndex = 0; // Start playing shuffled songs
                playSongs(playlist, currentSongIndex);
            }
        } else if (choice == 5) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid option. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void showMenu() {
    printf("\nMenu:\n");
    printf("1. Add song from list\n");
    printf("2. Add your own song\n");
    printf("3. Play playlist\n");
    printf("4. Shuffle play\n");
    printf("5. Exit\n");
    printf("Choice: ");
}

void showSongs(vector<string> songs) {
    for (int i = 0; i < songs.size(); i++) {
        printf("%d. %s\n", i + 1, songs[i].c_str());
    }
}

void playSongs(vector<string> playlist, int &currentSongIndex) {
    while (true) {
        if (currentSongIndex >= playlist.size()) break;

        // Just print the current song
        printf("Now playing: %s\n", playlist[currentSongIndex].c_str());

        // Prompt to skip or go back
        printf("\nEnter 'n' to skip to next song, 'b' to go back, or any other key to continue.\n");
        char action = getchar();
        getchar(); // Consume newline character

        if (action == 'n' || action == 'N') {
            skipSong(currentSongIndex, playlist);
        } else if (action == 'b' || action == 'B') {
            previousSong(currentSongIndex, playlist);
        } else {
            break; // Continue with the playlist
        }
    }
}

void playShuffle(vector<string> playlist) {
    // Manually shuffle the playlist using rand()
    for (int i = playlist.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);  // Random index from 0 to i
        swap(playlist[i], playlist[j]);
    }
}

void skipSong(int &currentSongIndex, vector<string> &playlist) {
    if (currentSongIndex < playlist.size() - 1) {
        currentSongIndex++;
        printf("Skipping to next song: %s\n", playlist[currentSongIndex].c_str());
    } else {
        printf("You're already at the last song.\n");
    }
}

void previousSong(int &currentSongIndex, vector<string> &playlist) {
    if (currentSongIndex > 0) {
        currentSongIndex--;
        printf("Going back to previous song: %s\n", playlist[currentSongIndex].c_str());
    } else {
        printf("You're already at the first song.\n");
    }
}

