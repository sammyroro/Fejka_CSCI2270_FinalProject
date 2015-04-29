//
//  Network.cpp
//  FinalProject2270
//
//  Created by Martin M. Fejka on 4/25/15.
//  Copyright (c) 2015 Martin M. Fejka. All rights reserved.
//

#include "Network.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Network::Network(){  //sets up all of the initial conditions that are needed
    //ctor
    head = NULL;
    tail = NULL;
    networkBuilt = false;
}

Network::~Network(){
    //dtor
    node *pDel = head;

    while (pDel != NULL) {
        head = head->next;
        delete pDel;
        pDel = head;
    }
    tail = head = NULL;
}

void Network::buildNetwork(){
    string cityNames[15] = {"Los Angeles", "Las Vegas", "Phoenix", "Salt Lake City", "Denver", "Dallas", "Minneapolis",
                                "St. Louis", "Columbus", "Nashville", "Chicago", "Atlanta", "Washington, D.C.", "New York",
                                "Boston"};
    node *xCity = new node;
    head = xCity;
    xCity->name = cityNames[0];
    xCity->next = NULL;
    xCity->previous = NULL;
    int i = 1;
    while (i < 15){    // creates new nodes for each city and attaches it to the linked list
        node *newCity = new node;
        newCity->name = cityNames[i];
        newCity->next = NULL;
        xCity->next = newCity;
        newCity->previous = xCity;
        xCity = xCity->next;
        tail = xCity;
        i++;
    }
    networkBuilt = true;
    printPath();
}

void Network::printPath(){    //this functions goes through the linked list and prints the path
    if (networkBuilt == false){
        cout << "No network in place!" << endl;
    }
    else {
        cout << "===CURRENT PATH===" << endl;
        node *tempCity = new node;
        tempCity = head;
        while (tempCity != NULL){
            cout << tempCity->name << " -> ";
            if (tempCity->next == NULL){
                cout << "NULL" << endl;
                cout << "==================" << endl;
            }
            tempCity = tempCity->next;
        }
        delete []tempCity;
    }
}

void Network::transmitMsg(string message){  // transmits the message through the network
    node *temp = new node;
    temp = head;
    while (temp->next != NULL){
        cout << temp->name << " received " << message << endl;
        temp = temp->next;
    }
    while (temp != NULL){
        cout << temp->name << " received " << message << endl;
        temp = temp->previous;
    }
}

void Network::storeMsg(string city, string message){
    node *temp = new node();
    temp = head;
    while (temp != NULL){
        if (temp->name == city){
            temp->message = message;
            break;
        }
        temp = temp->next;
    }
}

void Network::checkMsg(string city){
    node *temp = new node();
    temp = head;
    while (temp != NULL){
        if (temp->name == city){
            cout << temp->message << endl;
        }
        temp = temp->next;
    }
}
void Network::addCity(string city, string predecessor){
    node *temp = new node();
    node *newCity = new node();
    temp = head;
    if(head == NULL){
        newCity->name = city;
        newCity->previous=NULL;
        newCity->next=NULL;
        head = newCity;
    }
    else{
        while(temp != NULL && temp->name != predecessor){
            temp=temp->next;
        }
        if(temp == NULL){
            cout << predecessor << (" is not present in the network") <<endl;
        }
        else{
            newCity->name = city;
            newCity->next = temp->next;
            if (temp->next != NULL){
                temp->next->previous = newCity;
                tail = newCity;
            }
            temp->next = newCity;
            newCity->previous = temp;
        }
    }
}
void Network::addCityHead(string city){
    node *temp = new node();
    node *newCity = new node();
    temp = head;
    if(head == NULL){
        newCity->name = city;
        newCity->previous=NULL;
        newCity->next=NULL;
        head = newCity;
        return;
    }
    else{

            newCity->name = city;
            newCity->next = temp;
            newCity->previous = NULL;
            head = newCity;
            temp->previous = newCity;



    }
}
void Network::deleteCity(string city){
    struct node *temp,*var, *temp1;
    temp = head;
    var = temp->previous;
    temp1 = temp->next;
    while(temp!=NULL)
    {
        if(temp->name == city){
            if(temp->previous==NULL && temp->next == NULL){
                free(temp);
                head = NULL;
                tail = NULL;
                return;
            }
            else if(temp->previous==NULL && temp->next != NULL)
            {
                head = temp->next;
                temp->next->previous = NULL;
                free(temp);
                return;
            }
            else if(temp->previous!=NULL && temp->next == NULL)
            {
                tail = temp->previous;
                temp->previous->next = NULL;
                free(temp);
                return;


            }
            else{
                var->next=temp1;
                temp1->previous=var;
                free(temp);
                return;
            }
        }
        else{
                var = temp;
                temp = temp->next;
                if(temp != NULL)
                {
                    temp1 = temp->next;
                }
                else
                {
                    temp1 = NULL;


                }
        }
    }
}
void Network::targetedTransmit(string cityName, string message){
    node *temp = new node();
    temp = head;
    while (temp != NULL){
        cout << temp->name << " received " << message << endl;
        if (temp->name == cityName){
            break;
        }
        temp = temp->next;
    }
    temp = temp->previous;
    while (temp != NULL){
        cout << temp->name << " received " << message << endl;
        temp = temp->previous;
    }
}

void Network::transmitAndStore(string cityName, string message){
    node *temp = new node();
    temp = head;
    while (temp != NULL){
        cout << temp->name << " received " << message << endl;
        if (temp->name == cityName){
            break;
        }
        temp = temp->next;
    }
    temp->message = message;
}
