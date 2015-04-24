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
        //circular queue methods
        //void enqueue(string);
        //string dequeue(); //should send through network, call transmit msg
        //void printQueue();
        void buildNetwork();
        void printPath();
        //void sendingEntireMessage(); //send when full
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
        int queueSize;
        int queueHead;
        int queueTail;
        bool full;
        bool sending;
        string *arrayQueue;
        string dequeueWord;
};

#endif // NETWORK_H
