#include <iostream>
using namespace std;

int main(){
    int arr[5];
    int su = 0;
    float per;

    for(int i = 0 ; i < 5 ; i++){
        cout << "Enter subject " << i+1 << "  marks : ";
        cin >> arr[i];
        su += arr[i];
    }

    per = su / 5;

    cout << "Total : " << su << " / 500"<< endl;
    cout << "Percentage : " << per << endl;
    
}