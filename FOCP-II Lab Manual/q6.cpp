#include <iostream>
using namespace std;

int main() {
    int numEmployees;
    cout << "Enter number of employees: ";
    cin >> numEmployees;

    for (int i = 1; i <= numEmployees; i++) {
        double basic, bonus, net;
        cout << "Enter basic salary for Employee " << i << ": ";
        cin >> basic;

        bonus = basic * 0.12;
        net = basic + bonus;

        cout << "Employee " << i << " -> "
             << "Bonus: " << bonus << ", Net Salary: " << net << endl;
    }

    return 0;
}