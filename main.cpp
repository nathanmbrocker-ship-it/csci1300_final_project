#include <iostream>
#include <string>
#include <vector>
#include "map.h"
#include "characters.h"
#include "player.h"
#include "shopkeeper.h"

using namespace std;

bool validInputInt(string input) {
    try {
        stoi(input);
        return true;
    }
    catch(...) {
        cout << "Try again, invalid input" << endl;
        return false;
    }

}

int main() {
    bool endGame = false;
    string playerName;

    //player declaration
    Player p("", 100, "Farm");

    //character declaration
    Character lewis("lewis", 7, "Community Center");
    Shopkeeper pierre("Pierre", 5, "Pelican Town", {"Corn Seed", "Carrot Seed", "Lettuce Seed"});
    Shopkeeper gus("Gus", 5, "Pelican Town", {"Bread", "Soup", "Stew", "White Monster Energy Drink"});
    Character morris("Morris", 2, "Joja Mart");

    titleScreen();

    //Name selection
    cout << "Name your character: ";
    cin >> playerName;
    p.setName(playerName);

    clearTerm();

    //game loop
    while (!endGame) {
        string input;
        
        do {
            cout << "What do you want to do? (Enter 1-5)                    " << p.getName() << endl;
            cout << "1. Travel                                              " << p.getLocation() << endl;
            cout << "2. Check inventory                                     Energy: " << p.getEnergy() << endl;
            cout << "3. Look at map                                         " << endl;
            cout << "4. Talk to someone                                     " << endl;
            cout << "5. Save and exit                                       " << endl;
            cin >> input;
        } while (!validInputInt(input) && !(stoi(input) >= 1 && stoi(input) <= 5));

        switch (stoi(input)){
            case 1:
                do {
                    cout << "Where would you like to travel: " << endl;
                    cout << "1. Pelican Town"  << endl;
                    cout << "2. Farm"  << endl;
                    cout << "3. Community Center" << endl;
                    cout << "4. Joja Mart"  << endl;
                    cout << "5. The Mines"  << endl;
                    cout << "6. The Forest"  << endl;
                    cin >> input;
                } while(!validInputInt(input) && !(stoi(input) >= 1 && stoi(input) <= 5));
                
                p.lowerEnergy(5);
                
                if (input == "1") {
                    p.setLocation("Pelican Town");
                } else if (input == "2") {
                    p.setLocation("Farm");
                }  else if (input == "3") {
                    p.setLocation("Community Center");
                } else if (input == "4") {
                    p.setLocation("Joja Mart");
                } else if (input == "5") {
                    p.setLocation("The Mines");
                } else if (input == "6") {
                    p.setLocation("The Forest");
                }
                break;

            case 2:
                cout << "Print inventory vector" << endl;
                break;

            //Move this to just be in the HUD above the menu
            case 3:
                clearTerm();
                printMap();
                clearTerm();
                break;

            case 4:
                if (p.getLocation() == "Pelican Town") {
                    do {
                        cout << "Who would  you like to talk to: (enter 1-2)" << endl;
                        cout << "1. Pierre" << endl;
                        cout << "2. Gus" << endl;
                        
                        cin >> input;
                    } while (!validInputInt(input) && !(stoi(input) >= 1 && stoi(input) <= 2));
                    if (input == "1") {
                        
                    }
                } else if (p.getLocation() == "Joja Mart") {
                    cout << "Morris [relationship: " << morris.getRelationship() << "]" << endl;
                    //relationship change test
                    cout << "1. Be nice" << endl;
                    cout << "2. Be rude" << endl;
                    cin >> input;
                        if (stoi(input) == 1) {
                            morris.setRelationship(morris.getRelationship() + 5);
                        } else if (stoi(input) == 2) {
                            morris.setRelationship(morris.getRelationship() - 5);
                        }
                } else if (p.getLocation() == "Community Center") {
                    cout << "Lewis [relationship: " << lewis.getRelationship() << "]"<< endl;
                    //relationship change test
                    cout << "1. Be nice" << endl;
                    cout << "2. Be rude" << endl;
                    cin >> input;
                        if (stoi(input) == 1) {
                            //lewis.raiseRelationship();
                        } else if (stoi(input) == 2) {
                            //lewis.lowerRelationship();
                        }
                } else {
                    cout << "There's no one to talk to :(" << endl;
                }
                break;

            case 5:
                endGame = true;
                break;

            default:
                cout << "Invalid input, enter 1-5" << endl;
                break;

        }
    }

    cout << "\nGAME OVER" << endl;

    return 0;
}