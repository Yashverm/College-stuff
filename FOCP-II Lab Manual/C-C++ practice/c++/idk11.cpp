#include <iostream>
using namespace std;

class student {

    private:
        int marks;       

    protected:        
        int rollno;       

    public:
        string name;      

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
