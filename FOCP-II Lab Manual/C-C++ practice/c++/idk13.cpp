#include <iostream>
#include <vector>
using namespace std;

class ArrayTraversal {
private:
    vector<int> arr;   // Dynamic array

public:
    // Function to take input
    void input() {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        arr.resize(n);   // Resize vector to required size

        cout << "Enter " << n << " elements: ";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // Function to traverse and display array
    void display() {
        cout << "Array elements are: ";
        for(int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayTraversal obj;   // Create object
    obj.input();          // Input elements
    obj.display();        // Traverse & display

    return 0;
}
