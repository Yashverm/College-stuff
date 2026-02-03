#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    switch (marks/10) {
        case 10:
            cout << "Grade S";
            break;
            
        case 9:
            cout << "Grade: A";
            break;

        case 8:
            cout << "Grade: B";
            break;

        case 7:
            cout << "Grade: C";
            break;

        case 6:
            cout << "Grade: D";
            break;

        default:
            cout << "Grade: F";
    }

    return 0;
}