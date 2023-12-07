#include "utility.h"

using namespace std;

int menu() {
    int choice;
    cout << "What would you like to do? " << std::endl;
    cout << "1. Upload Feats file\n2. Upload Spells file\n3. Quit" << std::endl;
    cout << "Enter your choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "Invalid choice, Please enter a number between 1 and 2.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

string getFilename() {
    string name;
    cin >> name;
    cin.ignore();
    return name + ".csv";
}

string getExcelname() {
    string name;
    cout << "Enter the txt filename: ";
    cin >> name;
    cin.ignore();
    return name + ".txt";
}

bool stringToBool(string s) {
    return (s == "1");
}