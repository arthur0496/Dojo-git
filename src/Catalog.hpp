//
//  Catalog.hpp
//  Assignment7
//
//  Created by Danilo Mendes on 4/2/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef Catalog_hpp
#define Catalog_hpp

#include <stdio.h>

#include "Music.hpp"

struct Node{
    Music data;
    Node *next;
    Node *prev;
public:
    Node(Music m, Node* n, Node* p) : data(m), next(n), prev(p) {}
    Node(Music m) : data(m), next(nullptr), prev(nullptr) {}
    Node(): data(Music::Music()),next(nullptr), prev(nullptr) {};
    ~Node(){free(next);free(prev);};
};

class Catalog{
    
    Node *head;
    void sort(Node **headRef);
    void splitList(Node* source, Node** frontRef, Node** backRef);
    Node* merge(Node* a, Node* b);
    void remove(Node *n);
    
public:
    
    Catalog();
    Catalog(Node *n) : head(n){}
    ~Catalog(void);
    
    //Get
    Node* getNext(){ return head->next;}
    Node* getPrev(){ return head->prev;}
    Music getData(){ return head->data;}
    
    //Set
    void setNode(Node *n){head = n;};
    void setNodeData(Node *n, std::string artist, std::string song, std::string genre, int date, int duration);

    //Methods
    Node* front(){ return head;}
    Node* back();
    bool empty(){ return head == nullptr;};
    bool hasNext(Node *n){ return n->next;}
    bool hasPrev(Node *n){ return n->prev;}
    int size();
    void append(Music m);
    void display();
    Node* nodeAtIndex(int index);
    void remove(Music m);
    void remove(int index);
    void insert(Music m);
    void insert(Music m, int index);
    void sortList();
    
    Catalog filter(char *value);
};

#endif /* Catalog_hpp */
