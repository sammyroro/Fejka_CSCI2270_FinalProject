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
        cout << "9. Quit" << endl;
        cin >> choice;
        if (choice == 1){
            CN->buildNetwork();  // builds the initial network of 15 cities
        }
        else if (choice == 2){
            CN->printPath();     //prints the path of the network
        }
        else if (choice == 3){

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
        else if (choice == 6){

        }
        else if (choice == 7){

        }
        else if (choice == 8){

        }
        else if (choice == 9){    // exits the program
            cout << "Goodbye!" << endl;
            running = false;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}
