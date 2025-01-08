class Card {


public:
    string Cards[52];

    Card() {
        string ranks[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                          "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
        int index = 0;
        int card = 0 ;
        for (int i = 0; i < 52; i++) {
            if (i % 4 == 0 && i != 0) {
                card++;
            }
            Cards[index++] = ranks[card];
        }
    }


    void PrintCards() {
        for (int i = 0; i < 52; i++) {
            cout << Cards[i] << endl;
        }
    }
}; 
