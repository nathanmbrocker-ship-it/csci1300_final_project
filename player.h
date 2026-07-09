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
    public:
        Player(string n, int e, string l) {
            name = n;
            energy = e;
            location = l;
        }

    //setters
    void setName(string n) {name = n;}
    void setEnergy(int e) {energy = e;}
    void setLocation(string l) {location = l;}

    //getters
    string getName() {return name;}
    int getEnergy() {return energy;}
    string getLocation() {return location;}

    //functions
    //void lowerEnergy(int work);
    //void raiseEnergy(int restore);

    void lowerEnergy(int work) {
    setEnergy(getEnergy() - work);
    }
    void raiseEnergy(int restore) {
    setEnergy(getEnergy() + restore);
    }
};

#endif