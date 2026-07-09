#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef CHARACTERS_H
#define CHARACTERS_H

class Character {
    private:
        string name;
        int relationshipScore;
        string location;
    public:
        Character() {
            name = "";
            relationshipScore = 5;
            location = "";
        }

        Character(string n, int r, string l) {
            name = n;
            relationshipScore = r;
            location = l;
        }

    //setters
    void setName(string n) {name = n;}
    void setRelationship(int score) {relationshipScore = score;}

    //getters
    string getName() {return name;}
    int getRelationship() {return relationshipScore;}

    //functions
    void lowerRelationship();
    void raiseRelationship();
    void dialoge();
};

#endif