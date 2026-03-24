#include <iostream>
using namespace std;

class Triangle {
private:
    float base, height, area;

public:
 
    Triangle() {
        cout << "Enter base of triangle: ";
        cin >> base;

        cout << "Enter height of triangle: ";
        cin >> height;

        area = 0.5 * base * height;
    }

    
    void display() {
        cout << "Area of Triangle = " << area << endl;
    }

  
    ~Triangle() {
        cout << "Destructor called. Triangle object destroyed." << endl;
    }
};

int main() {
    Triangle t;   
    t.display(); 
    return 0;
}
