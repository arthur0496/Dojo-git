//
//  Music.cpp
//  Assignment7
//
//  Created by Danilo Mendes on 4/1/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include "Music.hpp"
#ifndef Music_cpp
#define Music_cpp
#include <sstream>
#endif

//Empty Constructos
Music::Music(){
    this->_artist = "";
    this->_song = "";
    this->_genre = "";
    this->_date = 0;
    this->_duration = 0;
}

//Convert duration from mm:ss to seconds
void Music::setDuration(const int &m, const int &s){
    
    _duration = m*60 + s;
    
}

//Convert date from dd/mm/yy to days
void Music::setDate(const int &d, const int &m, const int &y){
    
    _date = d + m*30 + y*365;
    
}

//Convert number of days to dd/mm/yy
std::string Music::getDateString(){
    
    std::ostringstream buffer;
    
    int aux = _date;
    buffer << (aux%365)%30  <<"/"<<(aux%365)/30 << "/" << aux/365;
    
    return buffer.str();
}

//Convert seconds to mm:ss
std::string Music::getDurationString(){
    
    std::ostringstream buffer;
    
    int aux = _duration;
    buffer << aux/60 << ":" << aux%60;
    
    return buffer.str();
}

//Return single string with format
// Artist Song dd/mm/yy Genre mm:ss
std::string Music::toString(){
    
    std::string str = _artist + " " + _song + " ";
    str += getDateString() + " " + _genre + " " + getDurationString();
    
    return str;

}

//Check if all variables are empty
bool Music::isEmpty(){
    
    return (_artist.empty() && _song.empty() && _genre.empty() && !_date && !_duration );
}

//Check if any variable has the searched value
//If the type is a string, use .compare(string)
//If not check if the type of value is compatible
// to compare with int, and compare if true
template <typename T>
bool Music::hasValue(T& value) {
    
    bool result = false;
    
    if (typeid(value) == typeid(std::string)) {
        //.find() return -1 if not found
        // or >= 0 if found
        if (_artist.find(value) + 1) {
            result = true;
        }else if(_song.find(value) + 1){
            result = true;
        }else if(_genre.find(value) + 1){
            result = true;
        }
        
        //Compatible types to compare with int
    }else if(typeid(value) == typeid(int) || typeid(value) == typeid(float) || typeid(value) == typeid(double) || typeid(value) == typeid(bool)){
        
        if (_date == value) {
            result = true;
        }else if (_duration == value){
            result = true;
        }
    }
    
    return result;
}

//Overload hasValue for c-string
bool Music::hasValue(char* value){
    //.find() return -1 if not found
    // or >= 0 if found
    if (_artist.find(value) + 1) {
        return true;
    }else if(_song.find(value) + 1){
        return true;
    }else if(_genre.find(value) + 1){
        return true;
    }
    
    return false;
}
