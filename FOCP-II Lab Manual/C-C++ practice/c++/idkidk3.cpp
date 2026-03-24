#include <iostream>
using namespace std;

class CarRental {

private:
    double dailyRate;
    int    days;
    double taxRate;

public:

    CarRental(double dailyRate) {
        this->dailyRate = dailyRate;
        this->days      = 1;
        this->taxRate   = 0.0;
    }

    CarRental(double dailyRate, int days) {
        this->dailyRate = dailyRate;
        this->days      = days;
        this->taxRate   = 0.0;
    }

    CarRental(double dailyRate, int days, double taxRate) {
        this->dailyRate = dailyRate;
        this->days      = days;  
        this->taxRate   = taxRate;
    }

    double calculateCost() {
        double subtotal = dailyRate * days;
        double tax      = subtotal * (taxRate / 100);
        return subtotal + tax;
    }

    void displayDetails() {
        cout << "Daily Rate : $" << dailyRate << endl;
        cout << "Days       : "  << days      << endl;
        cout << "Tax Rate   : "  << taxRate   << "%" << endl;
        cout << "Total Cost : $" << calculateCost() << endl;
        cout << "----------------------------" << endl;
    }
};

int main() {

    CarRental booking1(50.0);
    cout << "Booking 1 (1 day, no tax):" << endl;
    booking1.displayDetails();

    CarRental booking2(50.0, 5);
    cout << "Booking 2 (5 days, no tax):" << endl;
    booking2.displayDetails();

    CarRental booking3(50.0, 5, 8.5);
    cout << "Booking 3 (5 days + 8.5% tax):" << endl;
    booking3.displayDetails();

    return 0;
}
