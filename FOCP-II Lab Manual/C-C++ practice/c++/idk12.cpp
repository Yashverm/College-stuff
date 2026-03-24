#include <iostream>
using namespace std;

class triangle {
private:
    float b;
    float h;

public:
    void getData() {
        cout << "Enter base of triangle: ";
        cin >> b;
        cout << "Enter height of triangle: ";
        cin >> h;
    }

    void area() {
        float area = 0.5 * b * h;
        cout << "Area of Triangle = " << area << endl;
    }
};

int main() {
    triangle t;
    t.getData();
    t.area();
    return 0;
}
