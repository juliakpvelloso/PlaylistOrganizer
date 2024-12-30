#include <vector>
#include <sstream>
#include <iostream>
#include "playlist.h"
#include <random> 

using namespace std; 


//public methods: 
//constructor
Playlist::Playlist(){
    buckets.resize(10); 
    numSongs = 0; 
}

//extract song method 
    //Requires: A string line that contains a full row from the dataset.csv file. 
    //Modifies: buckets
    //Effects: Creates a new song, calls the song classify method and adds the song to buckets 
void Playlist::extractSong (const string & line){
    stringstream ss(line);
    string value;

    string artist = "";
    string title = "";
    string genre = "";
    double danceability = 0; 
    double energy = 0;
    double loudness = 0; 
    double accousticness = 0; 
    double valence = 0; 
    double tempo = 0;
    int popularity = 0;
    uint16_t mode = 0; 
        
    for(int i = 0; i < 21; i++){
        getline(ss, value, ','); 

        if (i == 2){
            artist = value;
        }
        else if (i == 4){
            title = value;
        }
        else if (i == 5){
            //debug
            //cout << value << endl; 
            popularity = stoi(value); 
        }
        else if (i == 8){
            danceability = stod(value);
        }
        else if (i == 9){
            energy = stod(value);
        }
        else if (i == 11){
            loudness = stod(value);
        }
        else if (i == 12){
            //cout << value << endl; 
            mode = (uint16_t)stoi(value);
        }
        else if (i == 14){
            accousticness = stod(value);
        }
        else if (i == 17){
            valence = stod(value);
        }
        else if (i == 18){
            tempo = stod(value); 
        }
        else if (i == 20){
            genre = value; 
        }
    }

        Song newSong = Song(artist, title, genre, danceability, energy, loudness, accousticness, valence, tempo, popularity, mode); 
        int rating = newSong.classify(); 

        buckets[rating].push_back(newSong); 
        numSongs ++; 

        //debug
        //cout<< artist << "\n " << title << "\n" << genre << "\n" << danceability << "\n" << energy << "\n" << loudness << "\n" << accousticness << "\n" << valence << "\n" << tempo << "\n" << popularity<< "\n" << mode << "\n" << rating << endl; 
}

//sort playlist method 
    //Requires: buckets is initialized with Song objects 
    //Modifies: buckets
    //Effects: Selects songs 1 by 1 and outputs them in the correct order 

    //Rules for sorting: Songs may be at most 1 energy level different from their neighbors. Songs by the same artist cannot appear in a row
void Playlist::sort(){
    //initialize probabilities 
    vector<double> probabilities = {0.5, 0.4, 0.1}; 
        

    // find highest energy value
    // first song is of highest energy 
    int n = buckets.size(); 
    int level = n-1; 

    while(level >= 0 && buckets[level].empty()){
        level --; 
    }
    vector<int> levels = {min(level + 1, n-1), level, max(level - 1, 0)}; 
    //songs printed so far 
    int count = 0; 

    //previous song 
    Song prev = Song(); 

    while(count < numSongs){
        //debug 
        if(buckets[level].empty()){
            break;
        }
        // pick random song from current level 
        int n = buckets[level].size(); 
        int index = 0; 


        //try to pick a song with a different artist than previous if possible
        while(index < n && prev.getArtist() == buckets[level][index].getArtist()){
            index ++; 
        }
        if(index == n){
            index --; 
        }

        //print out song  
        cout << buckets[level][index].toString() << " " << level << "\n"; 
        count ++;

        //cout << "debug 1\n"; 

        //remove song from vector 
        buckets[level][index] = buckets[level][buckets[level].size() - 1]; 
        buckets[level].pop_back(); 
        //cout << "debug 2\n";  

        //decide on next level 
        //Random number generation
        random_device rd;  // Seed
        mt19937 gen(rd()); // Mersenne Twister generator
        std::discrete_distribution<> dist(probabilities.begin(), probabilities.end());
        //cout << "debug 3\n"; 

        // Generate a random number based on the probabilities
        int randomIndex = dist(gen);
        int nextLevel = levels[randomIndex];
        int i = 0; 

        /*while (buckets[nextLevel].empty() && i < 6){
            int randomIndex = dist(gen);
            int nextLevel = levels[randomIndex]; 
            i++; 
        }*/

       // Ensure the selected level is not empty
        while (i < 6 && (nextLevel < 0 || nextLevel >= buckets.size() || buckets[nextLevel].empty())) {
            randomIndex = dist(gen); // Retry random selection
            nextLevel = levels[randomIndex];
            i++;
        }

        /*if(buckets[nextLevel].empty() && !buckets[level].empty()){
            nextLevel = level; 
        }*/
        
        //cout << "debug 4\n"; 
        //if bucket chosen is still empty, move outwards from current level until found one that is not empty unless all songs have already been printed 
        if(count < numSongs && buckets[nextLevel].empty()){
            int levelHigher = level + 1; 
            int levelLower = level - 1; 

            //cout << "debug 5\n";
            while(levelLower >= 0 || levelHigher < 10){
                if(levelHigher < 10 && !buckets[levelHigher].empty()){
                    nextLevel = levelHigher; 
                    break; 
                }
                else if (levelLower >= 0 && !buckets[levelLower].empty()){
                    nextLevel = levelLower; 
                    break;
                }
                else{
                    levelHigher++;
                    levelLower--; 
                }
            }
        }
         
        level = nextLevel;

        //update probabilities 
        probabilities[0] *= 0.9;
        probabilities[2] *= 1.1; 
        probabilities[1] = 1 - (probabilities[0] + probabilities[2]); 

        //update levels 
        levels[0] = min(level + 1, n-1); 
        levels[1] = level; 
        levels[2] = max(level - 1, 0); 
    }
}

string Playlist::extractSongtest (const string & line){
    stringstream ss(line);
    string value;

    string artist = "";
    string title = "";
    string genre = "";
    double danceability = 0; 
    double energy = 0;
    double loudness = 0; 
    double accousticness = 0; 
    double valence = 0; 
    double tempo = 0;
    int popularity = 0;
    uint16_t mode = 0; 
        
    for(int i = 0; i < 21; i++){
        getline(ss, value, ','); 

        if (i == 2){
            artist = value;
        }
        else if (i == 4){
            title = value;
        }
        else if (i == 5){
            popularity = stoi(value); 
        }
        else if (i == 8){
            danceability = stod(value);
        }
        else if (i == 9){
            energy = stod(value);
        }
        else if (i == 11){
            loudness = stod(value);
        }
        else if (i == 12){
            mode = (uint16_t)stoi(value);
        }
        else if (i == 14){
            accousticness = stod(value);
        }
        else if (i == 17){
            valence = stod(value);
        }
        else if (i == 18){
            tempo = stod(value); 
        }
        else if (i == 20){
            genre = value; 
        }
    }
    ostringstream oss;
    oss << title << " " << artist << " " << genre <<  " " << danceability << " " << energy << " " << loudness << " "<< accousticness << " " << valence << " " << tempo << " " << popularity << " " << mode;
    return oss.str();
}