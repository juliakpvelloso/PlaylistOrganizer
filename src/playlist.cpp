#include <vector>
#include <sstream>
#include <iostream>
#include "song.cpp"
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
    Playlist(){
        buckets.resize(10); 
        numSongs = 0; 
    }


    //extract song method 
        //Requires: A string line that contains a full row from the dataset.csv file. 
        //Modifies: buckets
        //Effects: Creates a new song, calls the song classify method and adds the song to buckets 
    void extractSong (const string & line){
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

        Song newSong = Song(artist, title, genre, danceability, energy, loudness, accousticness, valence, tempo, popularity, mode); 
        int rating = newSong.classify(); 

        buckets[rating].push_back(newSong); 
        numSongs ++; 
    }

    //sort playlist method 
    //Requires: buckets is initialized with Song objects 
    //Modifies: buckets
    //Effects: Selects songs 1 by 1 and outputs them in the correct order 

    //Rules for sorting: Songs may be at most 1 energy level different from their neighbors. Songs by the same artist cannot appear in a row
    void sort(){
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
            cout << buckets[level][index].toString() << "\n"; 
            count ++; 

            //decide on next level 
            //Random number generation
            random_device rd;  // Seed
            mt19937 gen(rd()); // Mersenne Twister generator
            std::discrete_distribution<> dist(probabilities.begin(), probabilities.end());

            // Generate a random number based on the probabilities
            int randomIndex = dist(gen);
            int nextLevel = levels[randomIndex];

            while (buckets[nextLevel].empty()){
                int randomIndex = dist(gen);
                int nextLevel = levels[randomIndex];
            }

            level = nextLevel; 

            //update probabilities 
            probabilities[0] *= 0.9; 
            probabilities[2] *= 1.1; 
            probabilities[1] = 1 - (probabilities[0] + probabilities[2]); 
        }
    }
};