#include <iostream>
#include <string>
using namespace std;


class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void displayPerson() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

class Student : public Person {
public:
    int rollNumber;
    float marks;

    Student(string name, int age, int rollNumber, float marks)
        : Person(name, age) {
        this->rollNumber = rollNumber;
        this->marks = marks;
    }

    void displayStudent() {
        displayPerson();
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Marks       : " << marks << endl;
    }
};

int main() {
    Student s1("Alice", 20, 101, 88.5);
    Student s2("Bob",   19, 102, 76.0);

    cout << "===== Student 1 =====" << endl;
    s1.displayStudent();

    cout << "\n===== Student 2 =====" << endl;
    s2.displayStudent();

    return 0;
}