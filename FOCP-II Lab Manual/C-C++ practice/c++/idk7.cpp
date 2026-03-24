#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int count = 0;

    cout << "Enter 5 numbers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++) {
        if (arr[i] % 3 == 0 && arr[i] % 5 == 0) {
            count++;
        }
    }

    cout << "Numbers divisible by both 3 and 5: " << count << endl;

    return 0;
}
