#ifndef AUDIOBUFFER_H
#define AUDIOBUFFER_H

#include <string>
#include <iostream>
#include "supportFunctions.h"

using namespace std;

class AudioBuffer{
    private:
          void* data;
    public:
        AudioBuffer(int d, string t){
            data = loadAudioResource(d, t);
        }
        ~AudioBuffer(){
            if(data != nullptr){
                cout << "   Destroying the AudioBuffer\n";
                freeAudioResource(data);
            }
        }
        void play() const{
            playAudioResource(data);
        }
};

#endif