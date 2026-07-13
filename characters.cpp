#include <iostream>
#include <string>
#include <vector>

#include "characters.h"

//member function definitions
//broken, no idea what. fails to compile then says no errors detected in the workspace
void Character::lowerRelationship() {
    int newScore = getRelationship() - 1;
    setRelationship(newScore);
}
void Character::raiseRelationship() {
    setRelationship(getRelationship() + 1);
}

int character() {

    return 0;
}