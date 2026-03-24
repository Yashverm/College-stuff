#include <iostream>
using namespace std;

class student {

    private:
        int marks;        // only accessible inside this class

    protected:        
        int rollno;       // accessible inside class (and derived classes)

    public:
        string name;      // accessible everywhere

        void setdata(int m , int r){
            marks = m;
            rollno = r;
        }

        int getmarks(){
            return marks;
        }

        void showrollno(){
            cout << "roll no. : " << rollno << endl;
        }
};

int main(){

    student s1;

    s1.name = "Alice";
    
}