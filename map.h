#include <iostream>
#include <string>

using namespace std;

//Im just putting all the big decoritive cout things in here so its easier to read eberything else

void titleScreen() {
    string start;
    //Im not making my own thing anymore so im gonna change that to say Stardew Vally or something
    //cout << " _______           _        _______  _______ _________ _______  _        _______ " << endl;
    // cout << "(  ____ )|\\     /|( (    /|(  ____ \\(  ____ \\\\__   __/(  ___  )( (    /|(  ____ \\" << endl;
    // cout << "| (    )|| )   ( ||  \\  ( || (    \\/| (    \\/   ) (   | (   ) ||  \\  ( || (    \\/" << endl;
    // cout << "| (____)|| |   | ||   \\ | || (__    | (_____    | |   | |   | ||   \\ | || (__    " << endl;
    // cout << "|     __)| |   | || (\\ \\) ||  __)   (_____  )   | |   | |   | || (\\ \\) ||  __)   " << endl;
    // cout << "| (\\ (   | |   | || | \\   || (            ) |   | |   | |   | || | \\   || (      " << endl;
    // cout << "| ) \\ \\__| (___) || )  \\  || (____/\\/\\____) |   | |   | (___) || )  \\  || (____/\\" << endl;
    // cout << "|/   \\__/(_______)|/    )_)(_______/\\_______)   )_(   (_______)|/    )_)(_______/" << endl;
    cout << "        ///\\\\\\                /\\                             v   v               " << endl;
    cout << "       ////\\\\\\\\      /\\      //\\\\        /\\          /\\    v  v    v             " << endl;
    cout << "      /////\\\\\\\\\\    //\\\\    ///\\\\\\  /\\  //\\\\        //\\\\         v               " << endl;
    cout << "     / ^       ^\\  / ^  \\  /^ ^   \\/ ^\\/  ^ \\  /\\  /^   \\          |             " << endl;
    cout << "    /    ^    ^  \\/    ^ \\/  ^ ^^ ^\\^ /  ^ ^ \\/  \\/  ^ ^ \\        /|\\            " << endl;
    cout << "   /  ^      ^  ^ \\^  ^  /^ ^____ ^ \\/ ^  ^  /  ^ \\^ ^  ^ \\      /*||\\           " << endl;
    cout << "  /    ^   ^     ^ \\^  ^/____|  |____________ ^  ^ \\ ^ ^  ^\\    /|||*|\\          " << endl;
    cout << " / ^   ^  ^  ^   ^  \\^ //____________________\\ ^ ^  \\  ^ ^^ \\  /|*|||||\\       oo" << endl;
    cout << "/ ^^  ^ ^  ^ ^ ^ ^ ^ \\//______________________\\  ^ ^ \\^ ^^ ^ \\    | | *   ooooooo" << endl;
    cout << "oooooooooooo^  ^  ^ ^/^^||__||__||  ||__||__|| ^ ^ oooooooooooooooooooooooooooooo" << endl;
    cout << "oooooooooooooooooo ^/ ^ |||||||||| *||||||||||ooooooooooooooooooooooooooooooooooo" << endl;
    cout << "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo" << endl;

    cout << "press enter to start!";
    getline(cin, start);
}

void printMap() {
    string exit;
    cout << " /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\" << endl;
    cout << "|                                                                     |" << endl;
    cout << "|                                    Mines                            |" << endl;
    cout << "|                               ------/                               |" << endl;
    cout << "|         Farm                 /                                      |" << endl;
    cout << "|              \\---------Pelican Town----------Joja Mart™             |" << endl;
    cout << "|             /                                                       |" << endl;
    cout << "|       Forest                                                        |" << endl;
    cout << "|                                                                     |" << endl;
    cout << " \\____________________________________________________________________/" << endl;

    cout << "Press enter to return to menu: ";
    cin.ignore(1000, '\n');
    getline(cin, exit);

}

void clearTerm() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}