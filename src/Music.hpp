//
//  Music.hpp
//  Assignment7
//
//  Created by Danilo Mendes on 4/1/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef Music_hpp
#define Music_hpp

#include <iostream>

class Music{
    
    std::string _artist;
    std::string _song;
    std::string _genre;
    int _date;
    int _duration;
    
public:
    //Constructors
    Music();
    Music(std::string artist, std::string song, std::string genre, int date, int duration)
    : _artist(artist), _song(song), _genre(genre), _date(date), _duration(duration) {}
    
    //Getters
    std::string getArtist() const {return _artist;};
    std::string getSong() const {return _song;};
    std::string getGenre() const {return _genre;};
    int getDate() const {return _date;};
    int getDuration() const {return _duration;};
    
    //Setters
    void setArtist(const std::string &artist) {_artist=artist;}
    void setSong(const std::string &song) {_song=song;}
    void setGenre(const std::string &genre) {_genre=genre;}
    void setDate(const int &date) {_date=date;}
    void setDate(const int &d, const int &m, const int &y);
    void setDuration(const int &duration) {_duration=duration;}
    void setDuration(const int &m, const int &s);

    //Methods
    std::string getDateString();
    std::string getDurationString();
    std::string toString();
    bool isEmpty();
    template<typename T> bool hasValue(T& value);
    bool hasValue(char*);
    
    //Override Operator
    inline bool operator==(Music& m1){
        return !_artist.compare(m1._artist) && !_song.compare(m1._song) && !_genre.compare(m1._genre) && _date == m1._date && _duration == m1._duration;
    };
    inline bool operator>(Music& m1){
        return _artist.compare(m1._artist)>0;
    }
    inline bool operator>=(Music& m1){
        return _artist.compare(m1._artist)<0 || !_artist.compare(m1._artist);
    }
    inline bool operator<(Music& m1){
        return _artist.compare(m1._artist)<0;
    }
    inline bool operator<=(Music& m1){
        return _artist.compare(m1._artist)<0 || !_artist.compare(m1._artist);
    }
    
};

#endif /* Music_hpp */
