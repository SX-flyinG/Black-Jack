#pragma once
class REGplusLOGIN {
    char* username = new char[16];
    char* password = new char[64];
    int age = 2001;
    int choice = 0;
public:

    void registration(bool & closeProg);
    int reg(bool & closeProg);
    void LogIn(bool&  closeProg);

    ~REGplusLOGIN() {
        delete[]username;
        username = nullptr;
        delete[]password;
        password = nullptr;
    }
};


int REGplusLOGIN::reg(bool & closeProg) {

    cout << "Write a num of move :\n0 - Exit;\n1 - Registration;\n2 - Log in;\n ";
    cout << "LOG IN DON'T WORK !!!!!" << endl;
    cin >> choice;
    cin.ignore();

    while (choice < 0 || choice > 2) {
        cout << "Write a valid num of move: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 0) {
        cout << "Goodbye!" << endl;
        closeProg == false;
        return 0;
    }
    else if (choice == 1) {
        registration(closeProg);
    }
    else if (choice == 2) {
        LogIn(closeProg);
    }


    return 0;
}

/*Function in which user registrate
He need to write username and password
After that user goes to main lobby of program*/
void REGplusLOGIN::registration(bool & closeProg) {
    system("cls");
    cout << "Write your nickname (max 16 letters and no space): ";
    cin.getline(username, 16);
    //Write in txt file an username of the user
    ofstream inFileName("username.txt");
    inFileName << username;
    inFileName.close();

    cout << "Write your year of boarn : ";
    cin >> age;
    cin.ignore();

    if (age - 2025 <= -18) {
        cout << "Write your password (max 64 letters and no space): ";
        cin.getline(password, 64);
        //Write in txt file a password which user wrote
        ofstream inFilePass("password.txt");
        inFilePass << password;
        inFilePass.close();
    }
    else {
        cout << "Goodbye little kid" << endl;
        closeProg == false;
    }




}

/*Function to log in acc by username and password
If u write wrong username or password program dont go to next*/
void REGplusLOGIN::LogIn(bool & closeProg) {
    system("cls");
    cout << "Write your nickname (max 16 letters and no space): ";
    cin.getline(username, 16);
    string user;
    ifstream outFileName("username.txt");
    getline(outFileName, user);
    outFileName.close();
    cout << "Write your password (max 64 letters and no space): ";
    cin.getline(password, 64);
    string pass;
    ifstream outFilePass("username.txt");
    getline(outFilePass, pass);
    outFilePass.close();
    if (username == user) {
        cout << "Good";
    }
    if (password == pass) {
        cout << "Good pass";
    }
    else {
        cout << "U write incorect username or password , do u want to try again? [0 - no ; 1 - yes]";
        cin >> choice;
        cin.ignore();
        if (choice == 0) {
            cout << "Goodbye!";
            closeProg == false;
        }
        else {
            LogIn(closeProg);
        }
    }
}