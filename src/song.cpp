#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "song.h"

using namespace std; 

//constructor
  Song::Song(const string& artist, const string& title, const string& genre, double danceability, double energy, double loudness, double accousticness, double valence, double tempo, int popularity, uint16_t mode )
  : artists(artist), title(title), genre(genre), 
    danceability(danceability), energy(energy), loudness(loudness),
    accousticness(accousticness), valence(valence), tempo(tempo),
    popularity(popularity), mode(mode)
    {}

//default constructor
  Song::Song(){
    artists = ""; 
    string title = ""; 
    string genre = "";  
  }

//classify method 
  //Requires: the song must have all attributes initialized
  //Modifies: nothing
  //Effects: returns the classification of the song from 0 - 10

  uint32_t Song::classify(){
        //the following doubles weigh each attribute equally, these weights can be modified to give preference to certain attributes 
        //normalize the attributes so that their values are between 1 and 100
        double normPopularity = popularity; 
        double normDanceability = danceability * 100;  
        double normEnergy = energy * 100; 
        double normAccousticness = 100 - (accousticness * 100);
        double normValence = valence * 100; 
        double normLoudness = (loudness + 50) * (100.0/55.0);
        double normTempo = tempo/2.43; 
        double normMode = mode * 100; 

        double average = (normPopularity + normDanceability + normEnergy + normAccousticness + normValence + normLoudness + normTempo + normMode)/8;
    return (uint32_t)min((average / 10), 9.0); 
    }
    
//get artist method 
  const string& Song::getArtist() const{
    return artists; 
  }
//toString method 
  const string Song::toString() const{
    ostringstream oss;
    oss << "\"" << title << "\" by " << artists;
    return oss.str();
  }