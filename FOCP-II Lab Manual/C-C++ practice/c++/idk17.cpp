#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;

    Employee(string name, int id) {
        this->name = name;
        this->id   = id;
    }

    void displayEmployee() {
        cout << "Name : " << name << endl;
        cout << "ID   : " << id   << endl;
    }
};

class Manager : public Employee {
public:
    float salary;
    float bonus;

    Manager(string name, int id, float salary, float bonus)
        : Employee(name, id) {
        this->salary = salary;
        this->bonus  = bonus;
    }

    void displayManager() {
        displayEmployee();
        cout << "Salary       : " << salary           << endl;
        cout << "Bonus        : " << bonus            << endl;
        cout << "Total Salary : " << salary + bonus   << endl;
    }
};

int main() {
    Manager m1("Amit", 5001, 30000, 5000);

    m1.displayManager();

    return 0;
}