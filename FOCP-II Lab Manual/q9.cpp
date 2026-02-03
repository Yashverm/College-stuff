#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;


    if (ch >= '0' && ch <= '9') {
        cout << "It is a Number." << endl;
    }
    
    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
       
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            cout << "It is a Vowel." << endl;
        } else {
            cout << "It is a Consonant." << endl;
        }
    }
  
    else {
        cout << "It is a Special Symbol." << endl;
    }

    return 0;
}