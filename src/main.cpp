//
//  main.cpp
//  Assignment7
//  Danilo Mendes
//  dbarrosmende2015@my.fit.edu
//  Created by Danilo Mendes on 3/31/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 Drive testing Catalog.hpp
 Testing functionalities:
 Insert
 Remove
 Display
 Size
 Sort
 Filter
 Front
 Back
 */

#include <iostream>
#include "Catalog.hpp"

using namespace std;


int main(int argc, const char * argv[]) {

    Catalog c = Catalog();
    Music m;
    
    cout << "Appending Artist and Brtist..." <<endl;
    c.append(Music("Artist", "Song", "Metal", 734944, 152));
    c.append(Music("Brtist", "Song", "Pop", 734944, 152));
    cout << "Inserting Crtist, Zrtist, Drtist..." <<endl;
    c.insert(Music("Crtist", "Song", "Rock", 734944, 152));
    c.insert(Music("Zrtist", "Song", "Blues", 734944, 152),0);
    c.insert(Music("Drtist", "Song", "Funk", 734944, 152));
    
    c.display();cout << "\n\n";
    cout << "Removing index 0, Crtist..." <<endl;
    c.remove(0);
    c.remove(Music("Crtist", "Song", "Rock", 734944, 152));
    
    c.display();cout << "\n\n";

    cout << "Appending G,C,E,R,Irtists..." <<endl;
    c.append(Music("Grtist", "Song", "Rock", 734944, 152));
    c.append(Music("Crtist_Rock_Star", "Song", "Indie", 734944, 152));
    c.append(Music("Ertist", "Song", "Rock", 734944, 152));
    c.append(Music("Rrtist", "Song", "Jazz", 734944, 152));
    c.append(Music("Irtist", "Song", "Folk", 734944, 152));
    
    c.display();cout << "Size: " << c.size() << "\n\n";

    cout << "Sorting..." <<endl;
    c.sortList();
    c.display();cout << "\n\n";
    
    cout << "Filtering Elements with \"Rock\"..." <<endl;
    
    char rock[] = "Rock";
    Catalog c2 = c.filter(rock);
    c2.display();cout << "\n\n";

    cout << "Front of list: "<< c.front()->data.toString() << "\n";
    cout <<  "Back of list: " << c.back()->data.toString() << "\n";
    
    return 0;
}
