

class Gaming {
    string myCards[12];
    string dealerCards[12];
    int keyboard;

public:
    Gaming() {
        keyboard = 27;
    }

    void StartGame() {
        CardDeck deck = CardDeck();
        deck.ShuffleDeck();

        for (int i = 0; i < 2; i++) {
            myCards[i] = deck.DealCard();
            cout << myCards[i] << endl;
        }

        int score = CountOfCards(myCards);
        cout << "\nInitial score: " << score << endl;
        if (score == 21) {
            cout << "Black Jack Yoooooo!!!";
        }

        while (true) {
            cout << "Press 1 to hit or 2 to stand: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                string card = deck.DealCard();
                score = CountOfCards(myCards);
                cout << "New card: " << card << ". Current score: " << score << endl;

                if (score > 21) {
                    cout << "You bust! Game over." << endl;
                    break;
                }
            }
            else if (choice == 2) {
                cout << "Final score: " << score << endl;
                break;
            }
            else {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }

    int CountOfCards(const string Cards[12]) {
        int points = 0;

        for (int i = 0; i < 12; i++) {
            if (myCards[i] == "Two") {
                points += 2;
            }
            else if (myCards[i] == "Three") {
                points += 3;
            }
            else if (myCards[i] == "Four") {
                points += 4;
            }
            else if (myCards[i] == "Five") {
                points += 5;
            }
            else if (myCards[i] == "Six") {
                points += 6;
            }
            else if (myCards[i] == "Seven") {
                points += 7;
            }
            else if (myCards[i] == "Eight" || myCards[i] == "Jack") {
                points += 8;
            }
            else if (myCards[i] == "Nine" || myCards[i] == "Queen") {
                points += 9;
            }
            else if (myCards[i] == "Ten" || myCards[i] == "King") {
                points += 10;
            }
            else if (myCards[i] == "Ace") {
                cout << "How we want to calculate Ace card : \n1 - How ONE\n2 - How ELEVEN : " << endl;
                keyboard = _getch();
                switch (keyboard)
                {
                case '1':
                    points += 1;
                    break;
                case '2':
                    points += 2;
                    break;
                }
            }
        }
        return points;
    }
};
