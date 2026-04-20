#include <iostream>
using namespace std;

int main() {

    long long L,R;
    
    if (!(cin>>L>>R)) return 0;

    long long odds_up_to_R=(R+1)/2;
    
    long long odds_up_to_L_minus_1=(L)/2;

    long long total_odds=odds_up_to_R-odds_up_to_L_minus_1;
    if (total_odds % 2==0){
        cout<<"even"<<endl;
    } else{
        cout<<"odd"<<endl;
    }

    return 0;
}