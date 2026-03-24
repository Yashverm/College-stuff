#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int arr[10];
    int m = 0;

    for(int i = 0 ; i < 10 ; i++){
        cout << "Enter item " << i+1 << "  cost : ";
        cin >> arr[i];
    }

    for (int i = 1 ; i < 10 ; i++) {
    if (arr[i] > m)
        m = arr[i];
    }

    cout << m;
}