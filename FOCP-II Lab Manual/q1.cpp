#include <iostream>
using namespace std;

int main(){
    float mark1, mark2, mark3, average;

    cout << "Enter marks of student 1: ";
    cin >> mark1;
    cout << "Enter marks of student 2: ";
    cin >> mark2;
    cout << "Enter marks of student 3: ";
    cin >> mark3;

    average = (mark1 + mark2 + mark3) / 3;

    cout << "The average marks of the class is: " << average << endl;

    return 0;
}
