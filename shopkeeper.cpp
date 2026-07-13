#include <iostream>
#include <string>
#include <vector>

#include "shopkeeper.h"

using namespace std;

void Shopkeeper::openShop() {
    cout << "~~~ Pierre's ~~~" << endl;
    for (int i = 0; i < int(inventory.size()); i += 2) {
        cout << i+1 << ". " << inventory[i] << " [" << inventory[i+1] << " gold]" << endl;
    }

}

int shopkeeper() {


    return 0;
}