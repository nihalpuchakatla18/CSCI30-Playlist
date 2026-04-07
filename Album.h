#pragma once

#include "Playlist.h"
#include <memory>

class Album : public Playlist{
    private:
    string albumName;
    shared_ptr<Album> album;

    public:
    Album(string an) : Playlist(), albumName(an){}
    ~Album(){
        cout << "Destroying the Album : " << albumName << endl;
    }
    string getAlbumName(){
        return albumName;
    }
    shared_ptr<AudioStream> getTrack(int index){
        /*try{
            return m_list[index];
        } catch (const logic_error& e){
            cout << "BAD INDEX: Invalid track index " << e.what() << endl;
        }*/
        if (index < 0 || index >= m_count) {
            cout << "Album not found" << endl;
            return nullptr;
        }
        return m_list[index];
    }
    void addSong(string title, string artist, int duration, shared_ptr<Album> album){
        cout << "Adding Song " << title << " to album: " << albumName << "..." << endl;
            try {
                shared_ptr<Song> s = make_shared<Song>(title, artist, duration, albumName);
                s->setAlbum(album);
                addStream(s);
            } catch (const exception& e) {
                cout << "[Playlist]: Failed to add " << title << " -> " << e.what() << endl;
            }
        }
};