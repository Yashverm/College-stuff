#include <iostream>
using namespace std;

int main() {
    int itemNo, quantity;
    float unitPrice, amount, netAmount;

    cout<<"Enter Item Number: ";
    cin>>itemNo;
    cout<<"Enter Quantity: ";
    cin>>quantity;
    cout<<"Enter Unit Price: ";
    cin>>unitPrice;

    amount=quantity*unitPrice;
    netAmount=amount-(amount*0.20);

    cout << "Total Amount: " << amount << endl;
    cout << "Net Amount after 20% discount: " << netAmount << endl;

    return 0;
}