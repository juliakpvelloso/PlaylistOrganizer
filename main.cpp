#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "playlist.h"




using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2){
        cerr << "Usage: ./playlist DATASET.CSV" << endl;
        return 1;
    }

    //initialize playlist class
    Playlist playlist; 

    //Process csv file 
    string filename = argv[1]; // Get the filename from the command-line arguments
    ifstream file(filename);
    string line;
    string junk;

    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    // Ignore the first line (header)
    if (getline(file, junk)) {
    }

    // Read the file line by line
    while (std::getline(file, line)) {
        //cout << line << endl; 
        playlist.extractSong(line);
    }

    playlist.sort(); 

    file.close();

}