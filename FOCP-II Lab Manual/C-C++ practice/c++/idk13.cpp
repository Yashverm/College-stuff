#include <iostream>
#include <vector>
using namespace std;

class ArrayTraversal {
private:
    vector<int> arr;   

public:
   
    void input() {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        arr.resize(n);  

        cout << "Enter " << n << " elements: ";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

 
    void display() {
        cout << "Array elements are: ";
        for(int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayTraversal obj;   
    obj.input();         
    obj.display();       

    return 0;
}
