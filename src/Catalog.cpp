//
//  Catalog.cpp
//  Assignment7
//
//  Created by Danilo Mendes on 4/2/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include "Catalog.hpp"

//Blank Constructor
Catalog::Catalog(){
    head = nullptr;
}

//Set for music data in node
//Alocate and initiate data with values passed
void Catalog::setNodeData(struct Node *n, std::string artist, std::string song, std::string genre, int date, int duration){
    
    n->data = Music::Music(artist, song, genre, date, duration);
}

//Go until last node and return it
Node* Catalog::back(){
    struct Node *aux = head;
    
    if (!empty())
        //Until node has next
        while (aux->next != nullptr) {
            aux = aux->next;
        }
    
    return aux;
}

//Runs until reach nullprt (one after last)
// counting runs
int Catalog::size(){
    Node *aux = head;
    int cont=0;
    if (!empty()) {
        do{
            aux = aux->next;
            cont++;
        }while (aux != nullptr);
    }
    
    return cont;
}

//Append node in the end of the list
void Catalog::append(Music m){
    //Get reference to the last element
    Node *aux = back();
    Node *newNode;
    //if not empty
    if (aux != nullptr) {
        //Creates node and links it to the list
        newNode = new Node(m,nullptr,aux);
        aux->next = newNode;
    }else{
        //Creates new list
        head = new Node(m);
    }
    
}
//Print every node and its values
void Catalog::display(){
    Node *aux = head;
    if (!empty()) {
        do{
            std::cout << aux->data.toString() << "\n";
            aux=aux->next;
        }while (aux!=nullptr);
    }
}

//Return node at given index
Node* Catalog::nodeAtIndex(int index){
    Node *aux = nullptr;

    //If in not in range
    if (index >= size() || index < 0){
        return aux;
    }else if(index==0){
        return head;
    }
    
    //Starts from beginning and goes until index
    aux = head;
    for (int i=0; i<index; i++) {
        if (hasNext(aux)){
            aux = aux->next;
        }
    }
    return aux;
}

//Remove given node that maches the data
void Catalog::remove(Music m){
    Node *aux = head;
    
    if (!empty() && !m.isEmpty()) {
        
        if (head->data == m) {
            aux=aux->next;
            remove(head);
        }
        //Until list is not null
        while (aux){
            //Check data if equal remove
            //if not move to next
            if (aux->data == m) {
                //aux1 = aux;
                //aux = aux->next;
                remove(aux);
                break;
            }else{
                aux = aux->next;
            }
        }
    }
    
}

//Remove node at given index
void Catalog::remove(int index){
    Node *aux = head;
    
    if (index >= size() || index < 0){
        return ;
    }else if(index==0){
        //If list > 1
        if (hasNext(head)) {
            //Remove first element and move head pointer
            aux = head->next;
            head->next->prev=nullptr;
            free(head);
            head = aux;
        }else{
            free(head);
            head = nullptr;
        }
        return ;
    }
    
    //Move until given index
    for (int i=0; i<index; i++) {
        if (aux->next!=nullptr){
            aux = aux->next;
        }
    }
    
    //Get reference to previous node
    Node *temp = aux->prev;
    //If is not the last node
    if (hasNext(aux)) {
        temp->next = aux->next;
        aux->next->prev = temp;
    }else{
        temp->next = nullptr;
    }

    free(aux);
    aux = nullptr;
}

//Remove given node
void Catalog::remove(Node *n){
    Node *aux;
    //If has next node, link it with previous
    if (hasNext(n)) {
        aux = n->next;
        aux->prev = n->prev;
    }
    
    //If has previous node, link it with next
    //If not, move head pointer
    if (hasPrev(n)) {
        aux = n->prev;
        aux->next = n->next;
    }else if(n == front()){
        head = head->next;
    }
    
    //free(n);
    n=nullptr;
    
}

//Insert data in ascending order (Artist field)
void Catalog::insert(Music m){
    Node *aux = head;
    
    if (!empty()) {
        //Find position in ascending order
        while (aux->data < m && hasNext(aux)) {
            aux = aux->next;
        }
        
        //If it is a middle node
        if (hasNext(aux) && hasPrev(aux)) {
            //Insert node before pointer
            Node *temp = aux->prev;
            Node *n = new Node(m,aux,temp);
            temp->next = n;
            aux->prev = n;
        //If last, append
        }else if (!hasNext(aux)){
            append(m);
        //If first, insert at beginning
        }else if (!hasPrev(aux)){
            insert(m, 0);
        }
        
    }else{
        head = new Node(m);
    }
}

//Insert Node at given index
void Catalog::insert(Music m, int index){
    //Receives node at the index
    Node *aux = nodeAtIndex(index);
    
    if (aux!=nullptr) {
        //If index==0
        if (aux==head) {
            //Create new first node, link to head
            //and move head to new first
            Node *temp = new Node(m,head,nullptr);
            head->prev = temp;
            head = temp;
        }else{
            //Insert node before old node at index
            Node *temp = new Node(m,aux,aux->prev);
            aux->prev->next = temp;
            aux->prev = temp;
            
        }
    }
}

//Did this function so the call would be simpler
void Catalog::sortList(){
    sort(&head);
}

//Sort list
//Uses recurrency to sort, using Mergesort algorithm
void Catalog::sort(Node **headRef){
    //Create references to head, and two sublists
    Node *root = *headRef;
    Node *front, *back;
    
    //If singular or empty
    if ((root == nullptr) || !hasNext(root)){
        return ;
    }
    
    //Split list in 2 sublists
    splitList(root, &front, &back);
    
    //recurrency
    sort(&front);
    sort(&back);
    
    //Merge two sublists
    *headRef = merge(front, back);
}

//Merge two sublists in one
//Comparing firsts elements and lining
//in ascending form
Node* Catalog::merge(Node *a, Node *b){
    Node *result = nullptr;
    
    //If empty, return
    if (a == nullptr)
        return(b);
    else if (b==nullptr)
        return(a);
    
    //If first element of first list is smaller,
    // line first element and move to next element
    // passing the remaining of the first list and the second
    if (a->data <= b->data){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(a, b->next);
    }
    return(result);
}


void Catalog::splitList(Node *source, Node **frontRef, Node **backRef){
    Node *rabbit;
    Node *turtle;
    
    //If empty of singular, return first list
    if (source==nullptr || !hasNext(source)){
        *frontRef = source;
        *backRef = nullptr;
    }
    else{
        //Rabbit moves twice as fast as Turtle
        turtle = source;
        rabbit = source->next;
        
        //Until Rabbit does not reach the finish line, move
        while (rabbit != nullptr){
            rabbit = rabbit->next;
            if (rabbit != nullptr){
                turtle = turtle->next;
                rabbit = rabbit->next;
            }
        }
        //Point to the beginning and the
        //Beginning of the end (midpoint)
        //Slow is before the list midpoint
        *frontRef = source;
        *backRef = turtle->next;
        turtle->next = nullptr;
    }
}

#pragma mark TODO - Load from file

void Catalog::loadFile(){
    string artist, song, genre;
    int duration,date;
    FILE *musicdata;
    musicdata = fopen("Music.txt","r");
    fscanf(musicdata,"%s %s %s %d %d",artist,song,genre,&duration,&date);
    while (fscanf(musicdata,"%s %s %s %d %d",artist,song,genre,&duration,&date) != -1) {
        artist+='a';
    }
    
}

Catalog Catalog::filter(char *value){
    Node *aux = head;
    Catalog c = NULL;
    if (!empty()) {
        c = Catalog();
        do{
            if (aux->data.hasValue(value)) {
                c.append(aux->data);
            }
            aux = aux->next;
        }while (hasNext(aux));
    }
    
    return c;
}

//Destructor
Catalog:: ~Catalog(void){
    //Free memory from the end of the line first
    // and move up
    Node *aux = back(), *aux1=nullptr;
    if (!empty()) {
        
        while (aux->prev!=nullptr) {
            aux1 = aux;
            aux = aux->prev;
            free(aux1);
            aux1=nullptr;
        }
    }
    free(aux);
    aux = nullptr;
    free(aux1);
    aux1 = nullptr;
    head = nullptr;
}
