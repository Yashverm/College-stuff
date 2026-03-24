#include <iostream>
using namespace std;

class Rental {
public:

    double computeRentalCost(double dailyRate) {
        return dailyRate;
    }

    double computeRentalCost(double dailyRate, int days) {
        return dailyRate * days;
    }

    double computeRentalCost(double dailyRate, int days, double taxRate) {
        double subtotal = dailyRate * days;
        double tax = subtotal * (taxRate / 100);
        return subtotal + tax;
    }
};

int main() {
    Rental r;

    cout << "Cost for 1 day         : $" << r.computeRentalCost(50.0)           << endl;
    cout << "Cost for 5 days        : $" << r.computeRentalCost(50.0, 5)        << endl;
    cout << "Cost with 8.5% tax     : $" << r.computeRentalCost(50.0, 5, 8.5)   << endl;

    return 0;
}