#include <vector>
#include <sstream>
#include <iostream>
#include "song.h"
#include <random> 

using namespace std; 

class Playlist{
    // data structure to hold songs 
    private:
    vector<vector<Song>> buckets; 
    int numSongs;

    //public methods: 
    //constructor
    public:
    Playlist();

    //extract song method 
        //Requires: A string line that contains a full row from the dataset.csv file. 
        //Modifies: buckets
        //Effects: Creates a new song, calls the song classify method and adds the song to buckets 
    void extractSong (const string & line);

    //sort playlist method 
    //Requires: buckets is initialized with Song objects 
    //Modifies: buckets
    //Effects: Selects songs 1 by 1 and outputs them in the correct order 

    //Rules for sorting: Songs may be at most 1 energy level different from their neighbors. Songs by the same artist cannot appear in a row
    void sort(); 

    //same as extract song but with output for testing
    string extractSongtest(const string & line);
};