//
//  Network.cpp
//  FinalProject2270
//
//  Created by Martin M. Fejka on 4/25/15.
//  Copyright (c) 2015 Martin M. Fejka. All rights reserved.
//

#include "Network.h"
#include "Network.h"
#include <iostream>

using namespace std;

Network::Network(int qs){  //sets up all of the initial conditions that are needed
    //ctor
    head = NULL;
    tail = NULL;
}

Network::~Network(){
    //dtor
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
    
    xCity = head;
    cout << "===CURRENT PATH===" << endl;   // prints out the path after it has been created
    while (xCity != NULL){
        cout << xCity->name << " -> ";
        if (xCity->next == NULL){
            cout << "NULL" << endl;
            cout << "==================" << endl;
        }
        xCity = xCity->next;
    }
    delete []xCity;
}

void Network::printPath(){    //this functions goes through the linked list and prints the path
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

void Network::transmitMsg(string word){  // transmits the message through the network
    node *temp = new node;
    temp = head;
    while (temp->next != NULL){
        cout << temp->name << " received " << word << endl;
        temp = temp->next;
    }
    while (temp->previous != NULL){
        cout << temp->name << " received " << word << endl;
        temp = temp->previous;
    }
    cout << temp->name << " received " << word << endl;
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
    node *head, *temp, *temp1;
    //node *newNode = new node;
    //node *temp = new node;
    node *var = new node;
    
    temp = head;
    var->name=city;
    if(head==NULL)
    {
        head=var;
        head->previous=NULL;
        head->next=NULL;
    }
    else
    {
        temp = head;
        while(temp!=NULL && temp->name!=predecessor)
        {
            temp=temp->next;
        }
        
        if(temp==NULL)
        {
            cout<< predecessor << ("\n is not present in list ") <<endl;
        }
         
        else{
            temp1=temp->next;
            temp->next=var;
            var->previous=temp;
            var->next=temp1;
            temp1->previous=var;
        }
    }
    /*
    tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
     */
}
    /*
    while(temp != NULL){
     
        if(temp->name == predecessor){
            newNode->name = city;
            newNode->name = temp->name;
            temp->next = newNode;
            (newNode->previous)->next = temp;
            temp->previous = newNode->previous;
            newNode->previous = newNode;
            
        }
        temp = temp->next;
    }
     */


void Network::deleteCity(string city){
    
}