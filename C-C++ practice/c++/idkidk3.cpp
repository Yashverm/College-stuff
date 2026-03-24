#include <iostream>
using namespace std;

class CarRental {

private:
    double dailyRate;
    int    days;
    double taxRate;

public:

    // Constructor 1: Only daily rate (1 day, no tax)
    CarRental(double dailyRate) {
        this->dailyRate = dailyRate;
        this->days      = 1;
        this->taxRate   = 0.0;
    }

    // Constructor 2: Daily rate + number of days (no tax)
    CarRental(double dailyRate, int days) {
        this->dailyRate = dailyRate;
        this->days      = days;
        this->taxRate   = 0.0;
    }

    // Constructor 3: Daily rate + days + tax rate
    CarRental(double dailyRate, int days, double taxRate) {
        this->dailyRate = dailyRate;
        this->days      = days;  
        this->taxRate   = taxRate;
    }

    // Calculate total cost
    double calculateCost() {
        double subtotal = dailyRate * days;
        double tax      = subtotal * (taxRate / 100);
        return subtotal + tax;
    }

    // Display booking details
    void displayDetails() {
        cout << "Daily Rate : $" << dailyRate << endl;
        cout << "Days       : "  << days      << endl;
        cout << "Tax Rate   : "  << taxRate   << "%" << endl;
        cout << "Total Cost : $" << calculateCost() << endl;
        cout << "----------------------------" << endl;
    }
};

int main() {

    // Using Constructor 1 — only daily rate
    CarRental booking1(50.0);
    cout << "Booking 1 (1 day, no tax):" << endl;
    booking1.displayDetails();

    // Using Constructor 2 — daily rate + days
    CarRental booking2(50.0, 5);
    cout << "Booking 2 (5 days, no tax):" << endl;
    booking2.displayDetails();

    // Using Constructor 3 — daily rate + days + tax
    CarRental booking3(50.0, 5, 8.5);
    cout << "Booking 3 (5 days + 8.5% tax):" << endl;
    booking3.displayDetails();

    return 0;
}
