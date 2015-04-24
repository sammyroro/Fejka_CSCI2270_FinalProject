#include <iostream>
#ifndef NETWORK_H
#define NETWORK_H
#include <string>


struct node{

    std::string name;
    std::string message; //intended to hold one word
    node *next;
    node *previous;

};

class Network
{
    public:
        Network(int);
        virtual ~Network();
        //circular queue methods
        //void enqueue(std::string);
        //std::string dequeue(); //should send through network, call transmit msg
        //void printQueue();
        void buildNetwork();
        void printPath();
        //void sendingEntireMessage(); //send when full
        void addCity(std::string);
        void deleteCity(std::string);
        void transmitMsg(std::string);
        void storeMsg(std::string, std::string);
        void checkMsg(std::string);
        void targetedTransmit(std::string, std:string);


    protected:
    private:
        node *head;
        node *tail;
        int queueSize;
        int queueHead;
        int queueTail;
        bool full;
        bool sending;
        std::string *arrayQueue;
        std::string dequeueWord;
};

#endif // NETWORK_H