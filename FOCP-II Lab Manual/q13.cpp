#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Not a quadratic equation (a cannot be 0)." << endl;
        return 0;
    }

    double D = pow(b, 2) - 4 * a * c;

    if (D > 0) {
        double root1 = (-b + sqrt(D)) / (2 * a);
        double root2 = (-b - sqrt(D)) / (2 * a);
        cout << "Two real roots: " << root1 << " and " << root2 << endl;
    }
    else if (D == 0) {
        double root = -b / (2 * a);
        cout << "One real root: " << root << endl;
    }
    else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-D) / (2 * a);
        cout << "Complex roots: " << realPart << " + " << imagPart << "i"
             << " and " << realPart << " - " << imagPart << "i" << endl;
    }

    return 0;
}