#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        string name;
        int energy;
        string location;
        int gold;
        int numBundCollected;
        vector<string> inventory;
        vector<string> seeds;
        vector<string> planted;
        vector<int> daysPlanted;
    public:
        Player(string n, int e, string l, int g, int b) {
            name = n;
            energy = e;
            location = l;
            gold = g;
            numBundCollected = b;
        }

    //setters
    void setName(string n) {name = n;}
    void setEnergy(int e) {energy = e;}
    void setLocation(string l) {location = l;}
    void setGold(int g) {gold = g;}
    void setBundle(int b) {numBundCollected = b;}
    void setInv(vector<string> i) {inventory = i;}

    //getters
    string getName() {return name;}
    int getEnergy() {return energy;}
    string getLocation() {return location;}
    int getGold() {return gold;}
    int getBundle() {return numBundCollected;}

    //functions
    void lowerEnergy(int e);
    void raiseEnergy(int e);
    void spendGold(int g);
    void paidGold(int g);
    void raiseBundle();
    void printInventory();
    void addItemInv(vector<string> item);
    void addSeeds(vector<string> item);
    void sell();
    void plant();
    void printPlanted();
    void addDayPlanted();
    void harvest();

};
#endif