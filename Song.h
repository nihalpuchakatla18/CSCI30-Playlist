#ifndef SONG_H
#define SONG_H

#include "AudioStream.h"


class Song : public AudioStream{

    private:
        string albumName;
    
    public:
    Song(string t, string a, int d, string ab) : AudioStream(t, a, d), albumName(ab){}

    void play() const override{
        cout << "Now playing Song: " << title << " by " << artist << " [Album: " << albumName << "]" << endl;
        playBuffer();    
    }
};

#endif