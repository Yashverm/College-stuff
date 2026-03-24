#include <iostream>
#include <string>
using namespace std;

class vehicle
{
private:
protected:
public:
    string brand;
    int year;

    vehicle()
    {
        cout << "Parent constructor called: object created" << endl;
    }

    void dispbrand()
    {
        cout << "Brand: " << brand << endl;
    }
};

class car : public vehicle
{
private:
public:
    string model;
    int seatingcapacity;

    car()
    {
        cout << "Child constructor called: object created" << endl;
    }

    void dispmodel()
    {
        cout << "Model: " << model << endl;
    }
};

int main()
{
    car x;

    x.brand = "Toyota";
    x.model = "Camry";
    x.year = 2023;
    x.seatingcapacity = 5;

    x.dispbrand();
    x.dispmodel();

    return 0;
}