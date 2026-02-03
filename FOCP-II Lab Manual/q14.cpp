#include <iostream>
using namespace std;

int main() {
    char op;
    double a, b;

    do {
        cout << "\nEnter operation (+, -, *, /) or q to quit: ";
        cin >> op;

        if (op == 'q') break;

        cout << "Enter two numbers: ";
        cin >> a >> b;

        if (op == '+') cout << "Result = " << a + b << endl;
        else if (op == '-') cout << "Result = " << a - b << endl;
        else if (op == '*') cout << "Result = " << a * b << endl;
        else if (op == '/') {
            if (b != 0) cout << "Result = " << a / b << endl;
            else cout << "Error: Division by zero!\n";
        }
        else cout << "Invalid operation!\n";

    } while (true);

    cout << "Goodbye!\n";
    return 0;
}
