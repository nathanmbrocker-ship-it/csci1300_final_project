#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void titleScreen() {
    string line;
    ifstream inFile("title.txt");

    if (inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << '\n';
        }
        inFile.close();
    } else {
        cerr << "Error printing title" << endl;
    }

    cout << "press enter to start!";
    getline(cin, line);
}

void printMap() {
    string line;
    ifstream inFile("map.txt");

    if (inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << '\n';
        }
        inFile.close();
    } else {
        cerr << "Error printing map" << endl;
    }

}

void clearTerm() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

void enterToContinue() {
    string input;
    getline(cin, input);
}