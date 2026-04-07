#ifndef SONG_H
#define SONG_H

#include <memory>
#include "AudioStream.h"
class Album;

class Song : public AudioStream{

    private:
        string albumName;
        weak_ptr<Album> album;
    
    public:
        Song(string t, string a, int d, string ab) : AudioStream(t, a, d), albumName(ab){}
        ~Song(){
            cout<< " Destroying Song " << title << endl;
        }
        void setAlbum(shared_ptr<Album> a){
            album = a;
        }

        void play() const override{
            string name = "Album does not exist";
            if(!album.expired()){
                name = albumName;
            }
            cout << "Now playing Song: " << title << " by " << artist << " [Album: " << name << "]" << endl;
            playBuffer();    
        }
};

#endif