#include <iostream>
#include <string>
#include <vector>

#include "characters.h"

//member function definitions
//broken, no idea what. fails to compile then says no errors detected in the workspace
void Character::lowerRelationship() {
    setRelationship(getRelationship() - 1);
}
void Character::raiseRelationship() {
    setRelationship(getRelationship() + 1);
}

int main() {

    return 0;
}