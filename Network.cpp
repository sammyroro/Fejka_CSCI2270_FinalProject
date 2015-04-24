#include "Network.h"
#include <iostream>

Network::Network(int qs){  //sets up all of the initial conditions that are needed
    //ctor
    queueSize = 0;
    arrayQueue = new std::string[qs];
    queueHead = 0;
    queueTail = 0;
    head = NULL;
    tail = NULL;
    full = false;
    sending = false;
}

Network::~Network(){
    //dtor
    delete []arrayQueue;
}
void Network::buildNetwork(){
    std::string cityNames[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta",
                            "Washington, D.C.", "New York", "Boston"};
    node *xCity = new node;
    head = xCity;
    xCity->name = cityNames[0];
    xCity->next = NULL;
    xCity->previous = NULL;
    int i = 1;
    while (i < 10){    // creates new nodes for each city and attaches it to the linked list
        node *newCity = new node;
        newCity->name = cityNames[i];
        newCity->next = NULL;
        xCity->next = newCity;
        newCity->previous = xCity;
        xCity = xCity->next;
        tail = xCity;
        i++;
    }

    xCity = head;
    std::cout << "===CURRENT PATH===" << std::endl;   // prints out the path after it has been created
    while (xCity != NULL){
        std::cout << xCity->name << " -> ";
        if (xCity->next == NULL){
            std::cout << "NULL" << std::endl;
            std::cout << "==================" << std::endl;
        }
        xCity = xCity->next;
    }
    delete []xCity;
}

void Network::printPath(){    //this functions goes through the linked list and prints the path
    std::cout << "===CURRENT PATH===" << std::endl;
    node *tempCity = new node;
    tempCity = head;
    while (tempCity != NULL){
        std::cout << tempCity->name << " -> ";
        if (tempCity->next == NULL){
            std::cout << "NULL" << std::endl;
            std::cout << "==================" << std::endl;
        }
        tempCity = tempCity->next;
    }
    delete []tempCity;
}
void Network::printQueue(){  //prints the words that are stored in the queue
    if (queueTail <= queueHead){
        for(int i = queueHead; i < 10; i++){
            std::cout << i << ": " << arrayQueue[i] << std::endl;
        }
        for(int i = 0; i < queueTail; i++){
            std::cout << i << ": " << arrayQueue[i] << std::endl;
        }
    }
    else {
        for(int i = queueHead; i < queueTail; i++){
            std::cout << i << ": " << arrayQueue[i] << std::endl;
        }
    }
}
void Network::transmitMsg(std::string word){  // transmits the message through the network
    node *temp = new node;
    temp = head;
    while (temp->next != NULL){
        std::cout << temp->name << " received " << word << std::endl;
        temp = temp->next;
    }
    while (temp->previous != NULL){
        std::cout << temp->name << " received " << word << std::endl;
        temp = temp->previous;
    }
    std::cout << temp->name << " received " << word << std::endl;
}
/*
void Network::enqueue(std::string word){
    arrayQueue[queueTail] = word;  //add a word to the tail
    queueTail++;
    queueSize++;
    if (queueTail == 10){  //sets the tail back to the start once the array fills up
        queueTail = 0;
    }
    if (queueSize == 10){  //tells the program that the queue is full
        full = true;
    }
    std::cout << "E: " << word << std::endl;
    std::cout << "H: " << queueHead << std::endl;
    std::cout << "T: " << queueTail << std::endl;
}
*/

/*
std::string Network::dequeue(){
    dequeueWord = arrayQueue[queueHead];  //stores the work that is being taken out of the array
    queueHead++;
    queueSize--;
    if (queueHead == 10){  //sets the head back to the start if it reaches the end
        queueHead = 0;
    }
    if (full == true){  // if the array was full this will tell the program it is no longer full
        full = false;
    }
    std::cout << "H: " << queueHead << std::endl;
    std::cout << "T: " << queueTail << std::endl;
    return dequeueWord;
}
*/

/*
void Network::sendingEntireMessage(){
    if(sending == false){
        sending = true;
    }
    else {
        sending = false;
    }
}
*/