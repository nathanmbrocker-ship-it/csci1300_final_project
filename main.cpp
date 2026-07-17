#include <iostream>
#include <string>
#include <vector>
#include "map.h"
#include "characters.h"
#include "player.h"
#include "shopkeeper.h"

using namespace std;

//checks if number is an number and convert to an int
bool validInputInt(string input) {
    try {
        stoi(input);
        return true;
    }
    catch(...) {
        cout << "Error: wrong input type, enter an integer" << endl;
        return false;
    }
}

int main() {
    //end game contitons, can end the main game loop
    bool endGame = false;
    bool quitGame = false;
    int dayCount = 0;

    //ending flags
    bool corpEnding = false;
    bool goodEnding = false;

    //keeping track of forage amounts
    int forageForest = 0;
    int forageMine = 0;

    //weather event
    //bool rainy = false;

    string playerName;

    //player declaration
    Player p("", 100, "Farm", 0, 0);

    //character declaration
    Character lewis("Lewis", 7, "Community Center");
    Shopkeeper pierre("Pierre", 5, "Pelican Town", {"Corn Seed", "5", "Carrot Seed", "5", "Lettuce Seed", "5"});
    Shopkeeper gus("Gus", 5, "Pelican Town", {"Cool Looking Rock [bundle item]", "1200"});
    Character morris("Morris", 2, "Joja Mart");

    //prints the title screen
    titleScreen();
    //Clears the terminal to keep it cleaner looking
    clearTerm();

    //Name selection
    cout << "Name your character: ";
    getline(cin, playerName);
    p.setName(playerName);
    clearTerm();

    cout << "Lewis: Good morning, " << p.getName() << endl;
    cout << "Lewis: I have a job for you" << endl;
    cout << "Lewis: I need you to find 3 items to finish the last bundle for the Community Center" << endl;
    cout << "Lewis: Ill need some Petrified Wood, found by foraging in the nearby forest" << endl;
    cout << "Lewis: I'll aslo have you get some Amber from foraging in the mine" << endl;
    cout << "Lewis: And last, Ill need that cool rock Gus keeps on his bar to weight down the recipts" << endl;
    cout << "Lewis: Go get all three and I can bring in visiters from all across Stardew Valley" << endl;

    //game loop
    while (!endGame && !quitGame && dayCount < 10) {
        string input;
        vector<string> item;

        //prints ui
        cout << "==================================================" << endl;
        cout << "                    Last Bundle                   " << endl;
        cout << "==================================================" << endl;
        cout << "Name: " << p.getName() << endl;
        cout << "Location: " << p.getLocation() << endl;
        cout << "Day: " << dayCount << " / 10" << "       Energy: " << p.getEnergy() << " / 100" << endl;
        cout << "Bundle Progress: " << p.getBundle() << " / 3    Money: " << p.getGold() << "g" << endl;
        //keeps the map visable
        printMap();
        do {
            cout << "What do you want to do? (Enter 1-5)" << endl;
            cout << "1. Travel" << endl;
            cout << "2. Check inventory" << endl;
            cout << "3. Forage" << endl;
            cout << "4. Talk to someone" << endl;
            cout << "5. Plant and harvest" << endl;
            cout << "6. Head home and sleep" << endl;
            cout << "7. Exit" << endl;
            cin >> input;
        } while (!validInputInt(input)); //check for a valid int and that its in the right range

        switch (stoi(input)){
            case 1:
                //travel branch
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
                
                p.lowerEnergy(30);
                
                //selecting location from input
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

                clearTerm();
                break;

            case 2:
                //player inv
                p.printInventory();
                break;

            case 3:
                //explore branch, find items and gold
                cout << "You look around for a while" << endl;
                if (p.getLocation() == "The Forest") {
                    p.lowerEnergy(20);
                    if (forageForest == 3) {
                        p.raiseBundle();
                        cout << "You find a piece of Fossilized Wood [bundle item]!" << endl;
                    } else {
                        cout << "You find some Acorns [40g]" << endl;
                        item.push_back("Acorns");
                        item.push_back("40");
                        p.addItemInv(item);
                    }
                    forageForest++;
                } else if (p.getLocation() == "The Mines") {
                    p.lowerEnergy(20);
                    if (forageMine == 3) {
                        p.raiseBundle();
                        cout << "You find a piece of Amber [bundle item]!" << endl;
                    } else {
                        cout << "You find some Coal [40g]" << endl;
                        item.push_back("Coal");
                        item.push_back("40");
                        p.addItemInv(item);
                    }
                    forageMine++;
                } else if (p.getLocation() == "Community Center") {
                    p.lowerEnergy(10);
                    lewis.raiseRelationship();
                    cout << "You admire the Community Center"  << endl;
                } else {
                    p.lowerEnergy(20);
                    cout << "You wander around and find a dropped coin [+5 gold]" << endl;
                    p.paidGold(5);
                }
                break;

            case 4:
                //speaking branch, options dependant on location
                if (p.getLocation() == "Pelican Town") {
                    do {
                        cout << "Who would  you like to talk to: (enter 1-2)" << endl;
                        cout << "1. Pierre" << endl;
                        cout << "2. Gus" << endl;
                        
                        cin >> input;
                    } while (!validInputInt(input) && !(stoi(input) >= 1 && stoi(input) <= 2));
                    if (stoi(input) == 1) {
                        do {
                            cout << "You talk to Pierre [relationship: " << pierre.getRelationship() << "]" << endl;
                            cout << "1. Talk about the farm" << endl;
                            cout << "2. Explain that seeds are cheeper at JojaMart so you should get a discount" << endl;
                            cout << "3. Sell items" << endl;
                            cout << "4. Buy items"  << endl;
                            cin >> input;
                        } while (!validInputInt(input) && !(stoi(input) >= 1 && stoi(input) <= 4));
                        if (stoi(input) == 1) {
                            pierre.raiseRelationship();
                            cout << "Pierre: Glad to hear the farm\'s doing well, " << p.getName() << endl;
                            cout << "*He looks happy to talk*" << endl;
                        } else if (stoi(input) == 2) {
                            pierre.lowerRelationship();
                            morris.raiseRelationship();
                            cout << "Pierre: ..." << endl;
                            cout << "*He look upset that you said that*" << endl;
                        } else if (stoi(input) == 3) {
                            p.sell();
                        } else if (stoi(input) == 4) {
                            item = pierre.openShop(p.getGold());
                            p.spendGold(stoi(item[1]));
                            p.addSeeds(item);
                            item.clear();
                        }

                    } else {
                        cout << "You talk to Gus [relationship: " << gus.getRelationship() << "]" << endl;
                        do {
                            cout << "1. Compliment the smell of the food" << endl;
                            cout << "2. Say that JojaMart canned food is cheaper" << endl;
                            cout << "3. Buy items" << endl;
                            cin >> input;
                        } while (!validInputInt(input) && !(stoi(input) >= 1 && stoi(input) <= 3));

                        if (stoi(input) == 1) {
                            gus.raiseRelationship();
                            cout << "Gus: Thanks, " << p.getName() << ". Its good to hear you like it!" << endl;
                            cout << "*He smiles and continues cooking*" << endl;
                        } else if (stoi(input) == 2) {
                            gus.lowerRelationship();
                            morris.raiseRelationship();
                            cout << "Gus: Then go to JojaMart" << endl;
                            cout << "*He ignores you until you leave*" << endl;
                        } else if (stoi(input) == 3) {
                            item = gus.openShop(p.getGold());
                            p.spendGold(stoi(item[1]));
                            if (item[0] == "Cool Looking Rock [bundle item]") {
                                p.raiseBundle();
                                item.pop_back();
                            }
                            p.addItemInv(item);
                            item.clear();
                        }
                    }
                } else if (p.getLocation() == "Joja Mart") {
                    cout << "Morris [relationship: " << morris.getRelationship() << "]" << endl;
                    //condition for evil quest
                    if (morris.getRelationship() >= 10) {
                        cout << "Hey, " << p.getName() << ". I heard about what items Lewis wanted you go get for the Community Center" << endl;
                        cout << "Their the perfect set of stones for the JojaMart Wonders of Nature Collection™" << endl;
                        cout << "The collection will be the fourth best set of upper reasonably priced jewlery sold by JojaMart" << endl;
                        cout << "Once you collect all the items, bring them back here and I\'ll send them to corperate" << endl;
                        cout << "I can give you a $25 giftcard and the thanks of the JojaMart family for your effort" << endl;
                        do{
                            cout << "1. Say yes" << endl;
                            cout << "2. Say no" << endl;
                            cin >> input;
                        } while (!validInputInt(input));

                        if (stoi(input) == 1) {
                            morris.raiseRelationship();
                            cout << "Glad to hear it, " <<  p.getName() << endl;
                            cout << "You will be a great addition to the family" << endl;
                        } else if (stoi(input) == 2) {
                            cout << "If you change you mind, just bring the items to me" << endl;
                            morris.lowerRelationship();
                        } else {
                            cout << "Invalid input, enter 1 or 2" << endl;
                        }
                    }
                    if (p.getBundle() == 3) {
                        endGame = true;
                        corpEnding = true;
                        break;
                    }
                    cout << "1. Ask about JojaMart's great deals" << endl;
                    cout << "2. Ask about what JojaMart is doing to protect Stardew Valley's unique and special ecosystem" << endl;
                    cin >> input;
                        if (stoi(input) == 1) {
                            morris.raiseRelationship();
                            cout << "Morris: We have plenty of great deals, no reason to shop anywhere else" << endl;
                            cout << "*He talks about JojaMart for a while*" << endl;
                        } else if (stoi(input) == 2) {
                            morris.lowerRelationship();
                            cout << "Morris: A JojaMart sponsored study shows there no negitive effect on the enviroment by any of our operations, some even say we're benifical" << endl;
                            cout << "*He looks upset you would doubt JojaMart*" << endl;
                        }
                } else if (p.getLocation() == "Community Center") {
                    if (p.getBundle() == 3) {
                        endGame = true;
                        goodEnding = true;
                        break;
                    }
                    cout << "Lewis [relationship: " << lewis.getRelationship() << "]"<< endl;
                    cout << "1. Ask about the history of the town" << endl;
                    cout << "2. Mention the economic boost JojaMart can being to the town" << endl;
                    cin >> input;
                        if (stoi(input) == 1) {
                            lewis.raiseRelationship();
                            cout << "lewis: Well, of course. I can talk about the Pelican Town for hours" << endl;
                            cout << "*He manages to talk for 30 minutes before you decide to say you have to go*" << endl;
                        } else if (stoi(input) == 2) {
                            lewis.lowerRelationship();
                            morris.raiseRelationship();
                            cout << "Lewis: I don\'t think you have a economics degree, " << p.getName() << endl;
                            cout << "*There\'s a awkard feeling in the air as you both stop talking*" << endl;
                        }
                } else {
                    //if not in location that contains a character
                    cout << "There's no one to talk to :(" << endl;
                }
                p.lowerEnergy(5);
                break;
            
            case 5:
                if (p.getLocation() != "Farm") {
                    cout << "Must be at the farm to plant or harvest" << endl;
                } else {
                    p.printPlanted();
                    cout << "Would you like to plant or harvest your plants" << endl;
                    do {
                        do{
                                cout << "1. Plant" << endl;
                                cout << "2. Harvest" << endl;
                                cin >> input;
                            } while (!validInputInt(input));
                    } while (!validInputInt(input) && ((stoi(input) == 1) || stoi(input) == 2));

                    if (stoi(input) == 1) {
                        p.plant();
                    } else if (stoi(input) == 2) {
                        p.harvest();
                    }

                }

                break;

            case 6:
                //resets energy and increases day cout
                p.setLocation("Farm");
                p.setEnergy(100);
                p.addDayPlanted();
                dayCount++;
                cout << "You get a well deserved full nights rest" << endl;
                cout << "You feel full of energy for the new day"  << endl;
                break;

            case 7:
                //quit game option
                quitGame = true;
                break;

            default:
                cout << "Invalid input, enter 1-5" << endl;
                break;

        }
        if (p.getEnergy() <= 0) {
            p.setLocation("Farm");
            p.setEnergy(50);
            p.addDayPlanted();
            dayCount++;

            cout << "You nearly collapse from exaustion, somehow you make it home to sleep" << endl;
            cout << "You worked too hard yesterday, you didn\'t sleep very well" << endl;
        }

    }
    if (quitGame) {
        cout << "\nQUIT GAME" << endl;
    } else if (endGame) {
        if (corpEnding) {
            cout << "You give all the Bundle Items to Morris, he gives you the promised $25 gift card" << endl;
            cout << "The whole town dislikes you now but youre $25 richer" << endl;
        } else if (goodEnding) {
            cout << "The bundle of beutiful items get put on display, the visiters to see them reviltizes the town" << endl;
            cout << "The whole town considers you a hero, except Morris" << endl;
        } else {
            cout << "You fail to collect all the bundle items by the deadline, life goes on" << endl;
            cout << "Lewis is disapointed but your still on good relations with everyone" << endl;
        }
    }

    return 0;
}