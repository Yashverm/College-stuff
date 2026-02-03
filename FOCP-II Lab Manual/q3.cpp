#include <iostream>
using namespace std;

int main() {
    int x;
    double fah, cel;

    cout << "Temperature Conversion Program\n";
    cout << "1. Convert Fahrenheit to Celsius\n";
    cout << "2. Convert Celsius to Fahrenheit\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> x;

    if (x==1){
        cout<<"Enter temperature in Fahrenheit: ";
        cin>>fah;
        cel=(fah-32)*5.0/9.0;
        cout<<"Temperature in Celsius: "<<cel<<" C"<< endl;
    } 
    else if (x==2){
        cout << "Enter temperature in Celsius: ";
        cin >> cel;
        fah=(cel*9.0/5.0)+32;
        cout<<"Temperature in Fahrenheit: "<<fah<<" F"<<endl;
    } 
    else{
        cout<<"Invalid choice! Please run the program again."<<endl;
    }
    return 0;
}