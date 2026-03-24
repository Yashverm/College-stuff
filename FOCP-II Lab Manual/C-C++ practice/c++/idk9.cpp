#include <iostream>
using namespace std;

void swap(int &x , int &y){
    cout << "before swap : "<< x << "," << y << endl;
    int t = x;
    x = y;
    y = t;
    cout << "after swap : "<< x << "," << y << endl;
}

int main(){
    int n1 , n2;

    cout << "enter val" << endl;
    cin >> n1 >> n2;
    cout << "before func : " << n1 << "," << n2 << endl;

    swap(n1 , n2);
    cout << "after func : " << n1 << "," << n2 << endl;
    return 0;
}