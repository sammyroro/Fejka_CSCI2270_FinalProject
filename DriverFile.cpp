//Samuel Taylor
//Martin Fejka
//CSCI 2270

#include <iostream>
#include <fstream>
#include "Network.h"
#include <string>


using namespace std;

int main(){
    bool running = true;
    int choice;
    Network *CN = new Network(10);
    while (running != false){                     // keeps the user in the loop until the choose quit
        cout << "======Main Menu=====" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Add City" << endl;
        cout << "4. Delete City" << endl;
        cout << "5. Store Message" << endl;
        cout << "6. Check Message" << endl;
        cout << "7. Quit" << endl;
        cin >> choice;
        if (choice == 1){
            CN->buildNetwork();  // builds the network
        }
        else if (choice == 2){
            CN->printPath();     //prints the path of the network
        }
        else if (choice == 3){      //adds a word to the queue

        }
        else if (choice == 4){    // removes a word from the queue and sends it to all the cities

        }
        else if (choice == 5){   // prints the items that are in the queue
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
        else if (choice == 6){   // sends the entire message
            string cityName;
            cout << "What city would you like to check?" << endl;
            cin >> ws;
            getline(cin, cityName);
            CN->checkMsg(cityName);
        }
        else if (choice == 7){    // exits the program
            cout << "Goodbye!" << endl;
            running = false;
        }
        else {
            cout << "Invalid input" << endl;
        }

    }

    return 0;
}
