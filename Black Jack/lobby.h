#pragma once
class lobby {
	int getKey;
	int countOfPlayers;	
	bool TexasPokerMode;
public:
	lobby() {
		getKey = 27;
		TexasPokerMode = false;
		countOfPlayers = 1;
	}

	const bool   getMode() {
		return TexasPokerMode;
	}

	const int getPlayers() {
		return countOfPlayers;
	}

	int MainLobby();
	void Rules() {
		system("cls");
		cout << "Choose rules which u want to read : \n0 - Exit\n1 - Texas holdem\n2 - Default poker" << endl;
		getKey = _getch();
		switch (getKey) {
		case 48:
			MainLobby();
			break;
		case 49:
			PrintTexasHoldemRules();
			break;
		case 50:
			PrintDefaultPokerRules();
			break;
		}
	}

	void PrintDefaultPokerRules();
	void  PrintTexasHoldemRules();
	void GameMode();
};

int lobby::MainLobby() {
	while (true) {
		system("cls");
		cout << "\t\t\t####  #       #####  #####   #  #  " << endl;
		cout << "\t\t\t#  #  #       #   #  #       # #   " << endl;
		cout << "\t\t\t####  #       #####  #       ##    " << endl;
		cout << "\t\t\t#  #  #       #   #  #       # #   " << endl;
		cout << "\t\t\t####  ######  #   #  #####   #  #  " << endl;
		cout << "\n\n";
		cout << "\t\t\t     #  #####  #####   #  #  " << endl;
		cout << "\t\t\t     #  #   #  #       # #   " << endl;
		cout << "\t\t\t     #  #####  #       ##    " << endl;
		cout << "\t\t\t     #  #   #  #       # #   " << endl;
		cout << "\t\t\t######  #   #  #####   #  #  " << endl;
		cout << "\n1 - Start Game " << endl;
		cout << "2 - Game Mode" << endl;
		cout << "3 - Rules" << endl;
		cout << "0,4 - Exit" << endl;
		cout << "Enter your choice: ";
		char key;
		cin >> key;

		switch (key) {
		case '0': 
		case '4':
			return 0;
		case '1':
			cout << "Go Go Go" << endl;
			return 1;
		case '2': 
			GameMode();
			break;
		case '3': 
			Rules();
			break;
		default:
			cout << "Invalid input. Try again.\n";
			system("pause");
			break;
		}
	}
}

void lobby::PrintTexasHoldemRules() {
	cout << "----------------------------------------\n";
	cout << "         Texas Hold'em Poker Rules       \n";
	cout << "----------------------------------------\n";
	cout << "1. Each player is dealt two private cards (hole cards).\n";
	cout << "2. Five community cards are dealt face-up on the 'board'.\n";
	cout << "3. Players combine their two hole cards with the community cards\n";
	cout << "   to make the best possible five-card hand.\n";
	cout << "4. The game has four betting rounds:\n";
	cout << "   - Pre-Flop: After players receive hole cards.\n";
	cout << "   - Flop: After the first three community cards are revealed.\n";
	cout << "   - Turn: After the fourth community card is revealed.\n";
	cout << "   - River: After the fifth and final community card is revealed.\n";
	cout << "5. The player with the best five-card hand wins the pot.\n";
	cout << "6. Hand Rankings (from best to worst):\n";
	cout << "   - Royal Flush, Straight Flush, Four of a Kind,\n";
	cout << "     Full House, Flush, Straight, Three of a Kind,\n";
	cout << "     Two Pair, One Pair, High Card.\n";
	cout << "7. If all players but one fold, the last player standing wins the pot.\n";
	cout << "----------------------------------------\n";
	getKey = _getch();
	MainLobby();
}

void lobby::PrintDefaultPokerRules() {
	cout << "----------------------------------------\n";
	cout << "             Default Poker Rules        \n";
	cout << "----------------------------------------\n";
	cout << "1. Players are dealt a specific number of cards (e.g., 5 cards in 5-Card Draw).\n";
	cout << "2. There are multiple betting rounds depending on the variation.\n";
	cout << "3. Players can 'fold', 'check', 'call', 'raise', or 'bet' during betting rounds.\n";
	cout << "4. In 5-Card Draw:\n";
	cout << "   - Players are dealt 5 cards face-down.\n";
	cout << "   - A round of betting occurs.\n";
	cout << "   - Players can discard 1-3 cards and receive replacements.\n";
	cout << "   - Another round of betting occurs, and hands are revealed.\n";
	cout << "5. The player with the best hand according to hand rankings wins the pot.\n";
	cout << "----------------------------------------\n";
	getKey = _getch();
	MainLobby();
}

void lobby::GameMode() {
	while (true) {
		system("cls");
		cout << "Choose an option:\n0 - Exit\n1 - Change Game Mode\n2 - Set Number of Players" << endl;
		int choice;
		cin >> choice;

		switch (choice) {
		case 0:
			return;
		case 1: {
			system("cls");
			char confirm;
			cout << "Current mode: "
				<< (TexasPokerMode ? "Texas Poker" : "Default Poker")
				<< ". Change mode? (y/n): ";
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y') {
				TexasPokerMode = !TexasPokerMode;
				cout << "Mode switched to "
					<< (TexasPokerMode ? "Texas Poker" : "Default Poker")
					<< ".\n";
			}
			getKey = _getch();
			break;
		}
		case 2:
			system("cls");
			cout << "Enter the number of players (1-5): ";
			cin >> countOfPlayers;
			while (countOfPlayers < 1 || countOfPlayers > 5) {
				cout << "Invalid number of players. Try again.\n";
				cout << "Enter the number of players (1-5): ";
				cin >> countOfPlayers;
			}
			cout << "Number of players set to " << countOfPlayers << ".\n";
			getKey = _getch();
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}
	}
}
