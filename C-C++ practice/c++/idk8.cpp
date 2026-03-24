#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[5];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int lar = INT_MIN;
    int slar = INT_MIN;

    for (int i = 0; i < 5; i++) {
        if (arr[i] > lar) {
            slar = lar;
            lar = arr[i];
        } 
        else if (arr[i] < lar && arr[i] > slar) {
            slar = arr[i];
        }
    }

    if (slar == INT_MIN) {
        cout << "No second largest element (all values may be equal)." << endl;
    } else {
        cout << "Largest number: " << lar << endl;
        cout << "Second largest number: " << slar << endl;
    }

    return 0;
}
