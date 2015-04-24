#include <iostream>
#ifndef NETWORK_H
#define NETWORK_H
#include <string>

using namespace std;

struct node{

    string name;
    string message; //intended to hold one word
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
        void addCity(string);
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
