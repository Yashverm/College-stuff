#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if (year % 400 == 0) {
        cout << year << " is a Leap Year. February has 29 days." << endl;
    }
    else if (year % 100 == 0) {
        cout << year << " is NOT a Leap Year. February has 28 days." << endl;
    }
    else if (year % 4 == 0) {
        cout << year << " is a Leap Year. February has 29 days." << endl;
    }
    else {
        cout << year << " is NOT a Leap Year. February has 28 days." << endl;
    }

    return 0;
}