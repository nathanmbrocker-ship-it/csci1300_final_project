#include <iostream>
#include <string>
#include <vector>
#include "characters.h"

using namespace std;

#ifndef SHOPKEEPERs_H
#define SHOPKEEPERS_H

class Shopkeeper : public Character {
    private:
        string name;
        int relationshipScore;
        string location;
        vector<string> inventory;

    public: 
        Shopkeeper(string n, int r, string l, vector<string> i) {
            name = n;
            relationshipScore = r;
            location = l;
            inventory = i;
        }
    //setters
    void setInventory(vector<string> i) {inventory = i;}

    //getters
    void openShop();
};

#endif