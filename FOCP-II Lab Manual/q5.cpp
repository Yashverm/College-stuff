#include <iostream>
using namespace std;

int main() {
    int a, b, x;

    cout << "Enter two numbers:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "\n--- Swap Menu ---\n";
    cout << "1. Swap using temporary variable\n";
    cout << "2. Swap using arithmetic (+ and -)\n";
    cout << "3. Swap using XOR\n";
    cout << "Enter your choice: ";
    cin >> x;

    switch(x) {
        case 1: {
            int temp = a;
            a = b;
            b = temp;
            break;
        }
        case 2: {
            a = a + b;
            b = a - b;
            a = a - b;
            break;
        }
        case 3: {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }
    cout << "\nAfter Swap: a = " << a << ", b = " << b << endl;
    return 0;
}