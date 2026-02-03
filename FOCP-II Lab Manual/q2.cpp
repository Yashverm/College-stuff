#include <iostream>
using namespace std;

int main() {
    double radius, area;
    const double PI = 3.14;

    cout << "Enter the radius of the circular fountain: ";
    cin >> radius;

    area = PI * radius * radius;

    cout << "The area covered by the fountain is: " << area << " square units." << endl;

    return 0;
}
