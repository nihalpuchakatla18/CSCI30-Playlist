#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include <string>
#include <iostream>
#include "AudioBuffer.h"

using namespace std;

class AudioStream{
    protected:
        string title, artist;
        int duration;
    private:
        AudioBuffer audioBuffer;

    public:
        AudioStream(string t, string a, int d) : title(t), artist(a), duration(d), audioBuffer(d, t){}

        virtual ~AudioStream(){
            cout << "   Destroying the AudioStream : " << title << endl;
        }

        void print() {
            cout << "The stream \"" << title << "\" is " << duration << " seconds, performed by " << artist << "." << endl;
        }
        virtual void play() const = 0;

    protected:
        void playBuffer() const{
            audioBuffer.play();
        }
};

#endif