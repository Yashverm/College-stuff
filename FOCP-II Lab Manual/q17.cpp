#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect(int n) {
    if (n <= 1) return false;
    int sum = 1; 
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}
bool isArmstrong(int n) {
    int original = n;
    int digits = 0;
    int temp = n;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    int sum = 0;
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPerfect(num))
        cout << num << " is a Perfect number." << endl;
    else
        cout << num << " is not a Perfect number." << endl;

    if (isArmstrong(num))
        cout << num << " is an Armstrong number." << endl;
    else
        cout << num << " is not an Armstrong number." << endl;

    return 0;
}