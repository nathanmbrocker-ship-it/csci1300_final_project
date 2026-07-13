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
int player() {
    
    return 0;
}