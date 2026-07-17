#include <iostream>
#include <string>
#include <vector>

#include "player.h"

//member functions
void Player::lowerEnergy(int e) {
    setEnergy(getEnergy() - e);
}
void Player::raiseEnergy(int e) {
    setEnergy(getEnergy() + e);
}
void Player::spendGold(int g) {
    setGold(getGold() - g);
}
void Player::paidGold(int g) {
    setGold(getGold() + g);
}
void Player::raiseBundle() {
    setBundle(getBundle() + 1);
}
bool validInputIntPlayer(string input) {
    try {
        stoi(input);
        return true;
    }
    catch(...) {
        cout << "Error: wrong input type, enter an integer" << endl;
        return false;
    }
}

void Player::printInventory() {
    int playerListNum = 1;
    cout << "~~~~~~~~~~~~~~" << endl;
    cout << name << "'s items" << endl;
    if (Player::inventory.size() == 0 && Player::seeds.size() == 0) {
        cout << "Nothing in your inventory" << endl;
    } else {
        if (Player::inventory.size() > 0) {
            for (int i = 0; i < int(inventory.size()); i += 2) {
                cout << playerListNum << ". " << inventory[i] << " [" << inventory[i+1] << "g]" << endl;
                playerListNum++;
            }
        }
        if (Player::seeds.size() > 0) {
            for (int i = 0; i < int(seeds.size()); i += 2 ) {
                cout << playerListNum << ". " << seeds[i] << " [0g]" << endl;
                playerListNum++;
            }
        }
    }
}
void Player::addItemInv(vector<string> i) {
    if (i.size() >= 2) {
        inventory.push_back(i[0]);
        inventory.push_back(i[1]);
    }
}
void Player::addSeeds(vector<string> i) {
    if (i.size() >= 2) {
        seeds.push_back(i[0]);
        seeds.push_back(i[1]);
    }
}
//adds plant ot planted vector and starts the day count, removes seeds from seed inv
void Player::plant() {
    int listNumPlant = 1;
    string inputPlayer;
    if (seeds.size() == 0) {
        cout << "You dont have any seeds" << endl;
    } else {
        cout << "What do you want to plant" << endl;
        for (int i = 0; i < int(seeds.size()); i += 2) {
            cout << listNumPlant << ". " << seeds[i] << endl;
            listNumPlant++;
        }
        do {
            do {
                cout << "What would you like to plant [0 to exit, Enter 1 - " << seeds.size()/2 << " to plant]" << endl;
                cin >> inputPlayer;
            } while (!validInputIntPlayer(inputPlayer));
        } while (!(stoi(inputPlayer) >= 0 && stoi(inputPlayer) <= int(seeds.size()/2)));

        if (stoi(inputPlayer) == 0) {
            cout << "You dont plant anything" << endl;
        }  else if (stoi(inputPlayer) == 1) {
            planted.push_back(seeds[0]);
            daysPlanted.push_back(0);
            cout << "You plant " << seeds[0] << endl;

            seeds.erase(seeds.begin());
            seeds.erase(seeds.begin());
        } else {
            planted.push_back(seeds[stoi(inputPlayer)*2 - 2]);
            daysPlanted.push_back(0);
            cout << "You plant " << seeds[stoi(inputPlayer)*2 - 2] << endl;

            seeds.erase(seeds.begin() + stoi(inputPlayer)*2 - 1);
            seeds.erase(seeds.begin() + stoi(inputPlayer)*2 - 1);
        }
    }
}
void Player::printPlanted() {
    int listNumPlayer = 1;
    if (!(planted.size() == 0)) {
        cout << "~~~ Currently Planted ~~~" << endl;
        for (int i = 0; i < int(planted.size()); i++) {
            if (daysPlanted[i] < 3) { 
                cout << listNumPlayer << ". " << planted[i] << " [" << 3 - daysPlanted[i] << " days until grown]" << endl;
            } else {
                cout << listNumPlayer << ". " << planted[i] << " [Can harvest]" << endl;
            }
            listNumPlayer++;
        }
    }
}
void Player::addDayPlanted() {
    if (!(daysPlanted.size() == 0)) {
        for (int i = 0; i < int(daysPlanted.size()); i++) {
            daysPlanted[i] = daysPlanted[i] + 1;
        }
    }
}

void Player::harvest() {
    bool hadHarvest = false;
    int playerNumList = 1;
    int numHarvest = 0;
    string inputPlayer;

    cout << "~~~ Harvest Crops ~~~" << endl;
    for (int i = 0; i < int(planted.size()); i++) {
        if (daysPlanted[i] >= 3) {
            hadHarvest = true;
            cout << playerNumList << ". " << planted[i] << endl;
        }
    }
    if (!hadHarvest) {
        cout << "Nothing can be harvested yet" << endl;
        return;
    } else {
        do {
            do {
                cout << "What would you like to harvest [Enter 1 - " << numHarvest << "]" << endl;
                cin >> inputPlayer;
            } while (!validInputIntPlayer(inputPlayer));
        } while ((stoi(inputPlayer) >= 0 && stoi(inputPlayer) <= numHarvest));
    }
    if (stoi(inputPlayer) == 1) {
        inventory.push_back("Fresh Produce");
        inventory.push_back("300");
        cout << "You harvest Fresh Produce" << endl;

        planted.erase(planted.begin());
    } else {
        inventory.push_back("Fresh Produce");
        inventory.push_back("300");
        cout << "You plant Fresh Produce" << endl;

        planted.erase(planted.begin() + (stoi(inputPlayer) - 1));
    }
}

void Player::sell() {
    int playerListNum = 1;
    string inputPlayer;
    if (inventory.size() == 0) {
        cout << "Nothing to sell" << endl;
        return;
    } else {
            for (int i = 0; i < int(inventory.size()); i += 2) {
                cout << playerListNum << ". " << inventory[i] << " [" << inventory[i+1] << "g]" << endl;
                playerListNum++;
        }
    }
    do {
        cout << "What would you like to sell" << endl;
        cin >> inputPlayer;
    } while (!validInputIntPlayer(inputPlayer) && (stoi(inputPlayer) <= 0 && stoi(inputPlayer) > int(inventory.size()/2)));

    if (stoi(inputPlayer) == 1) {
        paidGold(stoi(inventory[stoi(inputPlayer)]));

        inventory.erase(inventory.begin());
        inventory.erase(inventory.begin());
    } else {
        paidGold(stoi(inventory[stoi(inputPlayer)]) * 2);

        inventory.erase(inventory.begin() + ((stoi(inputPlayer) * 2) - 1));
    }

}

int player() {
    
    return 0;
}