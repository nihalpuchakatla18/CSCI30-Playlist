#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "AudioStream.h"
#include <stdexcept>

class Playlist {
    private:
        AudioStream* m_list[100];
        int m_count;

    public:
        Playlist() : m_count(0){
            for(int i = 0; i < 100; i++){
                m_list[i] = nullptr;
            }
        }
        ~Playlist(){
            for(int i = 0; i < 100; i++){
                delete m_list[i];
            }
        }

        void addStream(AudioStream *s){
            if(m_count < 100){
                m_list[m_count] = s;
                m_count++;
            }
        }
        void playAll(){
            cout << "--- Playing Your Playlist ---" << endl;
            for(int i = 0; i < m_count; i++){
                m_list[i]->play();
            }
        }
        void showPlaylist(){
            cout << "---  Listing Your Playlist ---" << endl;
            for(int i = 0; i < m_count; i++){
                cout << i << ":";
                m_list[i]->print();
            }
        }
        void swapSongs(int i1, int i2){
            if(m_count < 2){
                cout << m_count;
                throw logic_error("LOGIC ERROR: Playlist must contain at least 2 items");
            }
            if((i1 >= m_count)||(i2 >= m_count)){
                throw out_of_range("RANGE ERROR: Invalid swap values ");
            }
            AudioStream *temp = m_list[i1];
            m_list[i1] = m_list[i2];
            m_list[i2] = temp;
        }
};

#endif