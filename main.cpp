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
    Player p("", 100, "Farm", 0, 0);

    //character declaration
    Character lewis("Lewis", 7, "Community Center");
    Shopkeeper pierre("Pierre", 5, "Pelican Town", {"Corn Seed", "5", "Carrot Seed", "5", "Lettuce Seed", "5"});
    Shopkeeper gus("Gus", 5, "Pelican Town", {"Bread", "10", "Soup", "10", "Stew", "15", "White Monster Energy Drink", "30", "Cool Looking Rock [bundle item]", "1200"});
    Character morris("Morris", 2, "Joja Mart");

    titleScreen();

    //Name selection
    cout << "Name your character: ";
    getline(cin, playerName);
    //cin >> playerName;
    p.setName(playerName);

    //game loop
    while (!endGame) {
        string input;

        //keeps the terminal neat and keeps the map visable
        //clearTerm();
        printMap();
        do {
            cout << "What do you want to do? (Enter 1-5)                    " << p.getName() << endl;
            cout << "1. Travel                                              " << p.getLocation() << endl;
            cout << "2. Check inventory                                     Energy: " << p.getEnergy() << endl;
            cout << "3. Explore                                             Gold: " << p.getGold() << endl;
            cout << "4. Talk to someone                                     Bundle Items" << p.getBundle() << "/5" << endl;
            cout << "5. Save and exit                                       " << endl;
            cin >> input;
        } while (!validInputInt(input) && !(stoi(input) >= 1 && stoi(input) <= 5)); //check for a valid int and that its in the right range

        switch (stoi(input)){
            case 1:
                do {
                    //clears the main menu for easier reading
                    clearTerm();
                    printMap();

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
                //copy over the shopkeeper inv, remember to i++
                cout << "Print inventory vector" << endl;
                break;

            case 3:
                cout << "You look around for a while" << endl;
                if (p.getLocation() == "The Forest") {
                    p.raiseBundle();
                    p.lowerEnergy(20);
                    cout << "You find a piece of Fossilized Wood [bundle item]!" << endl;
                } else if (p.getLocation() == "The Mines") {
                    p.raiseBundle();
                    p.lowerEnergy(20);
                    cout << "You find a piece of Amber [bundle item]!" << endl;
                } else if (p.getLocation() == "Community Center") {
                    p.lowerEnergy(5);
                    lewis.raiseRelationship();
                    cout << "You admire the center"  << endl;
                } else {
                    cout << "You wander around and find a dropped coin [+5 gold]" << endl;
                    p.paidGold(5);
                }
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
                        //still have to validate all these inputs
                        cout << "You talk to Pierre [relationship: " << pierre.getRelationship() << "]" << endl;
                        cout << "1. Be nice" << endl;
                        cout << "2. Be rude" << endl;
                        cout << "3. Open shop" << endl;
                        cin >> input;
                        if (stoi(input) == 1) {
                            pierre.raiseRelationship();
                        } else if (stoi(input) == 2) {
                            pierre.lowerRelationship();
                        } else if (stoi(input) == 3) {
                            pierre.openShop();
                        }

                    } else {
                        cout << "You talk to Gus [relationship: " << gus.getRelationship() << "]" << endl;
                        cout << "1. Be nice" << endl;
                        cout << "2. Be rude" << endl;
                        cout << "3. Open shop" << endl;
                        cin >> input;
                        if (stoi(input) == 1) {
                            gus.raiseRelationship();
                        } else if (stoi(input) == 2) {
                            gus.lowerRelationship();
                        } else if (stoi(input) == 3) {
                            gus.openShop();
                        }
                    }
                } else if (p.getLocation() == "Joja Mart") {
                    cout << "Morris [relationship: " << morris.getRelationship() << "]" << endl;
                    //relationship change test
                    cout << "1. Be nice" << endl;
                    cout << "2. Be rude" << endl;
                    cin >> input;
                        if (stoi(input) == 1) {
                            morris.raiseRelationship();
                        } else if (stoi(input) == 2) {
                            morris.lowerRelationship();
                        }
                } else if (p.getLocation() == "Community Center") {
                    cout << "Lewis [relationship: " << lewis.getRelationship() << "]"<< endl;
                    cout << "1. Be nice" << endl;
                    cout << "2. Be rude" << endl;
                    cin >> input;
                        if (stoi(input) == 1) {
                            lewis.raiseRelationship();
                        } else if (stoi(input) == 2) {
                            lewis.lowerRelationship();
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