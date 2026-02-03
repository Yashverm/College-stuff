#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of sales entries: ";
    cin >> n;

    double sales, maxSales;

    cout << "Enter sales figure 1: ";
    cin >> sales;
    maxSales = sales;

    for (int i = 2; i <= n; i++) {
        cout << "Enter sales figure " << i << ": ";
        cin >> sales;

        if (sales > maxSales) {
            maxSales = sales;
        }
    }

    cout << "\nMaximum sales figure = " << maxSales << endl;

    return 0;
}