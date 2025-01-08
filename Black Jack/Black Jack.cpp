#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

#include "Card.h"
#include "Deck.h"
#include "registration.h"
#include "lobby.h"
#include "Gaming.h"

int main() {
    bool closeProg = true; 
    srand((time(NULL)));

    
    REGplusLOGIN reg;
    lobby lob;
    Gaming game;

    
    reg.reg(closeProg);
    if (!closeProg) {
        cout << "Exiting program...\n";
        return 0;
    }

    while (closeProg) {
        int lobbyResult = lob.MainLobby(); 

        if (lobbyResult == 0) { 
            closeProg = false;
            break;
        }

        game.StartGame();
    }

    cout << "Thank you for playing! Exiting program...\n";
    return 0;
}
