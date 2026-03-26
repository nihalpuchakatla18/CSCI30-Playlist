#ifndef PODCAST_H
#define PODCAST_H

#include "AudioStream.h"

class Podcast : public AudioStream {
    private:
        int episodeNumber;
        string guest;

    public:
        Podcast(string t, string a, int d, int en, string g) : AudioStream(t, a, d), episodeNumber(en), guest(g){}

    void play() const override {
        cout << "Now playing Podcast: " << title << " Ep #" << episodeNumber << "(Host: " << artist << ", Guest: " << guest << ")\n";
        playBuffer();
    }    
};

#endif