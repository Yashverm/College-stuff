#include <iostream>
using namespace std;

int main() {
    int quantity;
    double ppi, total, discount, finalAmount;

  
    cout << "Enter number of items: ";
    cin >> quantity;
    cout << "Enter price per item: ";
    cin >> ppi;

  
    total = quantity * ppi;


    if (quantity > 1000) {
        discount = total * 0.10;         
        finalAmount = total - discount;
    } else {
        discount = 0;
        finalAmount = total;
    }

   
    cout << "\nTotal before discount: " << total;
    cout << "\nDiscount applied: " << discount;
    cout << "\nFinal amount to pay: " << finalAmount << endl;

    return 0;
}