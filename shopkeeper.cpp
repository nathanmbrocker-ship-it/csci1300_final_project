#include <iostream>
#include <string>
#include <vector>

#include "shopkeeper.h"
#include "player.h"

using namespace std;

//validate input for shop item
bool validInputIntShop(string input) {
    try {
        stoi(input);
        return true;
    }
    catch(...) {
        cout << "Error: wrong input type, enter an integer" << endl;
        return false;
    }
}

//prints numbered list of the shops inv
vector<string> Shopkeeper::openShop(int g) {
    string itemInput;
    int shopListNum = 1;
    vector<string> boughtItem;
    if (name == "Pierre") {
        cout << "     ~~~ Pierre\'s ~~~" << endl;
    } else if (name == "Gus") {
        cout << "     === Gus\' Shop ====" << endl;
    }
    for (int i = 0; i < int(inventory.size()); i += 2) {
        cout << shopListNum << ". " << inventory[i] << " [" << inventory[i+1] << " gold]" << endl;
        shopListNum++;
    }
    
    //loops check for valid inputs
    do {
        do {
            cout << "What would you like to buy [enter 0 to exit, 1-" << inventory.size()/2 << " to buy an item]" << endl;
            cin >> itemInput;
        } while (!validInputIntShop(itemInput));
    } while (stoi(itemInput) > int(inventory.size()/2) || stoi(itemInput) < 0);

    //allows backing out of shop
    if (stoi(itemInput) == 0) {
        cout << "You leave without buying anything" << endl;
        boughtItem.push_back("");
        return boughtItem;
    //adds the item name and value into a vector to return, math is different for index 0 so theres 2 versions
    } else if (stoi(itemInput) == 1) {
        boughtItem.push_back(inventory[0]);
        boughtItem.push_back(inventory[1]);
        if (stoi(boughtItem[1]) > g) {
            cout << "Not enough money" << endl;
            boughtItem.clear();
            return boughtItem;
        }
        cout << "You buy " << inventory[0] << endl;
    } else {
        boughtItem.push_back(inventory[stoi(itemInput)*2 - 2]);
        boughtItem.push_back(inventory[stoi(itemInput)*2 - 1]);
        if (stoi(boughtItem[1]) > g) {
            cout << "Not enough money" << endl;
            boughtItem.clear();
            return boughtItem;
        }
        cout << "You buy " << inventory[stoi(itemInput)*2 - 2] << endl;
    }
    //sets all seeds value to 0 before adding to player inv
    // if (name == "Pierre") {
    //     boughtItem[1] = "0";
    // }
    return boughtItem;
}

int shopkeeper() {


    return 0;
}