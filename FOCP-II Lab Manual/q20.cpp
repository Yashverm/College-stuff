#include <iostream>
using namespace std;
int main(){
    int rows=5;
    for (int i=1;i<=rows;i++){
        for(int j=rows;j>=i;j--){
            cout<<" " << j ;
        }
        cout<<endl;
    }
    return 0;
}