//
//  main.cpp
//  FinalProject2270
//
//  Created by Martin M. Fejka on 4/25/15.
//  Copyright (c) 2015 Martin M. Fejka. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Network.h"
#include <string>


using namespace std;

int main(){
    bool running = true;
    int choice;
    Network *CN = new Network();
    while (running != false){                     // keeps the user in the loop until the choose quit
        cout << "======Main Menu=====" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Add City" << endl;
        cout << "4. Delete City" << endl;
        cout << "5. Store Message" << endl;
        cout << "6. Check Message" << endl;
        cout << "7. Transmit Message" << endl;
        cout << "8. Targeted Transmit" << endl;
        cout << "9. Transmit and Store" << endl;
        cout << "10. Quit" << endl;
        cin >> choice;
        if (choice == 1){
            CN->buildNetwork();  // builds the initial network of 15 cities
        }
        else if (choice == 2){
            CN->printPath();     //prints the path of the network
        }
        else if (choice == 3){       //adds a city in the network path
            string cityName;
            string prevCity;
            cout<< "Enter the name of the city you would like to add: "<<endl; //name of city to add
            cin >> ws;
            getline(cin, cityName);
            cout<< "Enter the name this city should be added after: " <<endl; //name of city to add to
            cin >> ws;
            getline(cin, prevCity);
            CN->addCity(cityName, prevCity);
        }
        else if (choice == 4){

        }
        else if (choice == 5){   // stores message to a specified city
            string cityName;
            string inMessage;
            cout << "Enter the name of the city:" << endl;
            cin >> ws;
            getline(cin, cityName);
            cout << "What message would you like to store:" << endl;
            cin >> ws;
            getline(cin, inMessage);
            CN->storeMsg(cityName, inMessage);
        }
        else if (choice == 6){   // checks the message that a city is holding
            string cityName;
            cout << "What city would you like to check?" << endl;
            cin >> ws;
            getline(cin, cityName);
            CN->checkMsg(cityName);
        }
        else if (choice == 7){
            string inMessage;
            cout << "What message would you like to send through the network?" << endl;
            cin >> ws;
            getline(cin, inMessage);
            CN->transmitMsg(inMessage);
        }
        else if (choice == 8){
            string destinationCity;
            string inMessage;
            cout << "Where do you want to send a message?" << endl;
            cin >> ws;
            getline (cin, destinationCity);
            cout << "What message do you want to send?" << endl;
            cin >> ws;
            getline(cin, inMessage);
            CN->targetedTransmit(destinationCity, inMessage);
        }
        else if (choice == 9){
            string destinationCity;
            string inMessage;
            cout << "Where do you want to send the message?" << endl;
            cin >> ws;
            getline (cin, destinationCity);
            cout << "What message do you want to send and store?" << endl;
            cin >> ws;
            getline(cin, inMessage);
            CN->transmitAndStore(destinationCity, inMessage);
        }
        else if (choice == 10){    // exits the program
            cout << "Network path has been deleted, goodbye!" << endl;
            CN->~Network();
            running = false;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}
