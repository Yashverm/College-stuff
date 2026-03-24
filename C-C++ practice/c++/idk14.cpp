#include <iostream>
using namespace std;

class Triangle {
private:
    float base, height, area;

public:
    // Constructor
    Triangle() {
        cout << "Enter base of triangle: ";
        cin >> base;

        cout << "Enter height of triangle: ";
        cin >> height;

        area = 0.5 * base * height;
    }//fahhhhh

    // Function to display area
    void display() {
        cout << "Area of Triangle = " << area << endl;
    }

    // Destructor
    ~Triangle() {
        cout << "Destructor called. Triangle object destroyed." << endl;
    }
};

int main() {
    Triangle t;   // Constructor automatically called
    t.display();  // Display area
    return 0;
}