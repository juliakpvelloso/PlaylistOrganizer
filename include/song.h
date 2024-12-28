#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std; 

class Song {
private:
    //attributes 
    private:
    string artists;
    string title; 
    string genre;  
    double danceability; 
    double energy;
    double loudness; 
    double accousticness; 
    double valence; 
    double tempo;
    int popularity;
    uint16_t mode; 

public:
    //default constructor
    Song(); 
    //constructor
    Song(const string& artist, const string& title, const string& genre, double danceability, double energy, double loudness, double accousticness, double valence, double tempo, int popularity, uint16_t mode );
    // Copy Constructor
    Song(const Song& other) = default;

    // Public methods
    u_int32_t classify();
    const string& getArtist() const;
    const string toString() const; 
};

#endif
