#include <cassert>
#include <iostream>
#include "playlist.h"

//SONG TESTS
void testDefaultGetArtist() {
    Song newsong = Song();
    assert(newsong.getArtist() == "");
}

void testGetArtist() {
    Song newsong = Song("Taylor Swift", "Blank Space", "Pop", 0.8, 0.75, 0.81, 0.2, 0.5, 95.997, 100, 1);
    assert(newsong.getArtist() == "Taylor Swift");
}

void testBlankGetArtist() {
    Song newsong = Song("", "Blank Space", "Pop", 0.8, 0.75, 0.81, 0.2, 0.5, 95.997, 100, 1);
    assert(newsong.getArtist() == "");
}

void testoString(){
    Song newsong = Song("Taylor Swift", "Blank Space", "Pop", 0.8, 0.75, 0.81, 0.2, 0.5, 95.997, 100, 1);
    assert(newsong.toString() == "\"Blank Space\" by Taylor Swift");

}

void testClassify(){
    Song newsong = Song("Taylor Swift", "Blank Space", "Pop", 0.8, 0.75, 0.81, 0.2, 0.5, 95.997, 100, 1);
    assert(newsong.classify() == 7);
}

void testClassifynull(){
    Song newsong = Song("Taylor Swift", "Blank Space", "Pop", 0,0, 0,0, 0, 0, 0, 0);
    assert(newsong.classify() == 2);
}

void testClassifyMax(){
    Song newsong = Song("Taylor Swift", "Blank Space", "Pop", 1,1, 49,0, 1, 243, 100, 1);
    assert(newsong.classify() == 9);
}

//PLAYLIST TESTS
void testExtractSong(){
    Playlist play = Playlist(); 
    string input = "81137,1u8c2t2Cy7UBoG4ArRcF5g,Taylor Swift,1989 (Deluxe),Blank Space,85,231826,False,0.76,0.703,5,-5.412,1,0.054,0.103,0.0,0.0913,0.57,95.997,4,pop"; 
    string actualOutput = play.extractSongtest(input); 

    ostringstream oss;
    oss << "Blank Space" << " " << "Taylor Swift" << " " << "pop" <<  " " << 0.76 << " " << 0.703 << " " << -5.412 << " "<< 0.103 << " " << 0.57 << " " << 95.997 << " " << 85 << " " << 1;
    string expectedOutput = oss.str();

    assert(actualOutput.compare(expectedOutput) == 0); 
}


int runTestsMain() {
    //song tests 
    std::cout << "Song tests: \n"; 
    testDefaultGetArtist();
    std::cout << "Default Get Artist Test Passed!\n";
    testGetArtist();
    std::cout << "Get Artist Test Passed!\n";
    testBlankGetArtist(); 
    std::cout << "Get Artist Blank Test Passed!\n";
    testoString();
    std::cout << "toString Test Passed!\n";
    testClassify(); 
    std::cout << "Classify Test Passed!\n";
    testClassifynull(); 
    std::cout << "Classify null Test Passed!\n";
    testClassifyMax();
    std::cout << "Classify max Test Passed!\n";
    std::cout << "All song tests passed!\n"; 
    //playlist tests
    std::cout << "\nPlaylist tests: \n";
    testExtractSong(); 
    std::cout << "Extract song test passed! \n"; 
    std::cout << "All playlist tests passed!\n"; 

    std::cout << "\nAll tests passed!" << std::endl;
    return 0;

}

