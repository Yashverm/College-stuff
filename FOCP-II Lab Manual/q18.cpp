#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit; 
    }
    return original == reversed;
}

int main() {
    int id;
    cout << "Enter numeric ID: ";
    cin >> id;

    if (isPalindrome(id))
        cout << id << " is a palindrome." << endl;
    else
        cout << id << " is not a palindrome." << endl;

    return 0;
}





