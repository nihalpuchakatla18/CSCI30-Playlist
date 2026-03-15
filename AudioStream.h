#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include <string>
#include <iostream>

using namespace std;

class AudioStream{
    protected:
        string title, artist;
        int duration;

    public:
        AudioStream(string t, string a, int d) : title(t), artist(a), duration(d){}

        virtual ~AudioStream(){}

        void print() {
            cout << "The stream \"" << title << "\" is " << duration << " seconds, performed by " << artist << "." << endl;
        }
        virtual void play() const = 0;
};

#endif