//
//  Network.h
//  FinalProject2270
//
//  Created by Martin M. Fejka on 4/25/15.
//  Copyright (c) 2015 Martin M. Fejka. All rights reserved.
//

#include <iostream>
#ifndef NETWORK_H
#define NETWORK_H
#include <string>

using namespace std;

struct node{

    string name;
    string message;
    node *next;
    node *previous;

};

class Network
{
    public:
        Network();
        virtual ~Network();
        void buildNetwork();
        void printPath();
        void addCity(string, string);
        void deleteCity(string);
        void transmitMsg(string);
        void storeMsg(string, string);
        void checkMsg(string);
        void targetedTransmit(string, string);
        void transmitAndStore(string, string);

    protected:
    private:
        node *head;
        node *tail;
        bool networkBuilt;
};

#endif // NETWORK_H
