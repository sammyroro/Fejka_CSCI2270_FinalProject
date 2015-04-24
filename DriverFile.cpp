#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct cityNetwork{
    string city;
    string message;
    cityNetwork *nextCity;
};

cityNetwork buildNetwork(){
    string cityNames[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta",
                            "Washington, D.C.", "New York", "Boston"};
    cityNetwork *head;
    cityNetwork *xCity = new cityNetwork;
    head = xCity;
    xCity->city = cityNames[0];
    xCity->nextCity = NULL;
    int i = 1;
    while (i < 10){
        cityNetwork *newCity = new cityNetwork;
        newCity->city = cityNames[i];
        newCity->nextCity = NULL;
        xCity->nextCity = newCity;
        xCity = xCity->nextCity;
        i++;
    }
    xCity = head;
    cout << "===CURRENT PATH===" << endl;
    while (xCity != NULL){
        cout << xCity->city << " -> ";
        if (xCity->nextCity == NULL){
            cout << " NULL" << endl;
            cout << "=================" << endl;
        }
        xCity = xCity->nextCity;
    }
    delete []xCity;
    return *head;
}

void printNetworkPath(cityNetwork *head){
    cout << "===CURRENT PATH===" << endl;
    cityNetwork *tempCity = new cityNetwork;
    tempCity = head;
    while (tempCity != NULL){
        cout << tempCity->city << " -> ";
        if (tempCity->nextCity == NULL){
            cout << " NULL" << endl;
            cout << "=================" << endl;
        }
        tempCity = tempCity->nextCity;
    }
    delete []tempCity;
}

void transmitMessage(cityNetwork *head, string word){
    cityNetwork *tempCity = new cityNetwork;
    tempCity = head;
    while (tempCity != NULL){
        cout << tempCity->city << " received " << word << endl;
        tempCity = tempCity->nextCity;
    }
    delete []tempCity;
}

void addCity(cityNetwork *head, string newCity, string prevCity){
    cityNetwork *tempCity = new cityNetwork;
    tempCity = head;
    while(tempCity != NULL){
        if(tempCity->city == prevCity){
            cityNetwork *newNode = new cityNetwork;
            newNode->city = newCity;
            newNode->nextCity = tempCity->nextCity;
            tempCity->nextCity = newNode;
        }
        tempCity = tempCity->nextCity;
    }
    delete []tempCity;
}

void deleteCity(cityNetwork *head, string cityName){
    cityNetwork *tempCity = new cityNetwork;
    cityNetwork *store = new cityNetwork;
    tempCity = head;
    tempCity = head;
    while(tempCity != NULL){
        if(tempCity->city == cityName){
            store = tempCity;
        }
        tempCity = tempCity->nextCity;
    }
    tempCity = head;
    while(tempCity != NULL){
        if(tempCity->nextCity == store){
            tempCity->nextCity = store->nextCity;
        }
        tempCity = tempCity->nextCity;
    }
    delete []tempCity;
}

void clearNetwork(cityNetwork *head){
    cityNetwork *deleteCities = new cityNetwork;
    deleteCities = head;
    while(deleteCities != NULL){
        head = head->nextCity;
        delete deleteCities;
        deleteCities = head;
    }
    delete head;
}

int main(){
    cityNetwork *listHead = new cityNetwork;
    bool running = true;
    int choice;
    while(running != false){
        cout << "======Main Menu=====" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Delete City" << endl;
        cout << "6. Clear Network" << endl;
        cout << "7. Quit" << endl;
        cin >> choice;
        if (choice == 1){
            *listHead = buildNetwork();
        }
        else if (choice == 2){
            if (listHead != NULL){
                printNetworkPath(listHead);
            }
            else {
                cout << "No network set up." << endl;
            }
        }
        else if (choice == 3){
            ifstream messageFile;
            messageFile.open("messageIn.txt");
            string word;
            while (! messageFile.eof() ){
                while (messageFile >> word){
                    transmitMessage(listHead, word);
                }
            }
        }
        else if (choice == 4){
            string newName;
            string prevName;
            cout << "Enter the name of the new city:" << endl;
            cin >> ws;
            getline(cin, newName);
            cout << "What city would you like it after:" << endl;
            cin >> ws;
            getline(cin, prevName);
            addCity(listHead, newName, prevName);
        }
        else if (choice == 5){
            string deleteName;
            cout << "Enter the name of the city you want to delete:" << endl;
            cin >> deleteName;
            deleteCity(listHead, deleteName);
        }
        else if (choice == 6){
            clearNetwork(listHead);
        }
        else if (choice == 7){
            running = false;
        }
        else {
            cout << "Invalid input. Choose again." << endl;
        }

    }
    return 0;
}
