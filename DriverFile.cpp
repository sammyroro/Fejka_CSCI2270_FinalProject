#Samuel Taylor
#CSCI 2270

#include <iostream>
#include <fstream>
#include "Network.h"
#include <string>


using namespace std;

int main(){
    bool running = true;
    int choice;
    int readWords = 0;
    int now = 0;
    int notw = 0;
    string word;
    string wordArray1[100];
    //ifstream messageIn;
    /*
    messageIn.open("messageIn.txt");
    while (! messageIn.eof() ){      //read in and store the data of the file
        while (messageIn >> word){
            wordArray1[notw] = word;
            notw++;
        }
    }
    string wordArray2[notw];
    for (int i = 0; i < notw; i++){
        wordArray2[i] = wordArray1[i];
    }
    */
    Network *CN = new Network(10);
    while (running != false){                     // keeps the user in the loop until the choose quit
        cout << "======Main Menu=====" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Enqueue" << endl;
        cout << "4. Dequeue" << endl;
        cout << "5. Print Queue" << endl;
        cout << "6. Send Entire Message" << endl;
        cout << "7. Quit" << endl;
        cin >> choice;
        if (choice == 1){
            CN->buildNetwork();  // builds the network
        }
        else if (choice == 2){
            CN->printPath();     //prints the path of the network
        }
        else if (choice == 3){      //adds a word to the queue
            CN->enqueue(wordArray2[readWords]);
            readWords++;
            now++;
        }
        else if (choice == 4){    // removes a word from the queue and sends it to all the cities
            if (now > 0){
                word = CN->dequeue();
                CN->transmitMsg(word);
                now--;
            }
            else {
                cout << "Queue is empty." << endl;
            }
        }
        else if (choice == 5){   // prints the items that are in the queue
            CN->printQueue();
        }
        else if (choice == 6){   // sends the entire message
            CN->sendingEntireMessage();
            int s = 0;
            bool stop = false;
            while (stop == false){
                for (int i = now; i < 10; i++){
                    if (s < notw){
                        CN->enqueue(wordArray2[s]);
                        s++;
                        now++;
                    }
                }
                for (int i = 0; i < now; i++){
                    word = CN->dequeue();
                    CN->transmitMsg(word);
                }
                now = 0;
                if (s == notw){
                    stop = true;
                }
            }
            CN->sendingEntireMessage();
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
