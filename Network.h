//
//  Network.h
//  FinalProject2270
//
//  Created by Martin M. Fejka on 4/25/15.
//  Copyright (c) 2015 Martin M. Fejka. All rights reserved.
//


#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <string>

using namespace std;

struct node{
    
    string name;
    string message; //intended to hold one word,
    // how can we make this hold a longer message(goal for a contributor?)
    node *next;
    node *previous;
    
};

class Network
{
public:
    Network(int);
    virtual ~Network();
    void buildNetwork();
    void printPath();
    void addCity(string,string);
    void deleteCity(string);
    void transmitMsg(string);
    void storeMsg(string, string);
    void checkMsg(string);
    void targetedTransmit(string, string);
    
    
protected:
private:
    node *head;
    node *tail;
};

#endif // NETWORK_H
