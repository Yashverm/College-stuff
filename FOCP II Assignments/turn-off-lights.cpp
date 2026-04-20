#include <iostream>
#include <string>

using namespace std;

bool can_do_it(int len, int n, int k, string bulbs){
    int charges_used=0;
    for (int i=0;i<n;i++) {
        if (bulbs[i] == '1') {
            charges_used++;
            i=i+len-1;
        }
    }
    return charges_used<=k;
}

int main() {
    int n,k;
    cin>>n>>k;
    string bulbs;
    cin>>bulbs;

    int low=1;
    int high=n;     
    int result=n;

    while (low<=high) {
        int mid=(low+high)/2;
        if(can_do_it(mid,n,k,bulbs)){
            result=mid; 
            high=mid-1;
        } else{
            low=mid+1;
        }
    }
    cout<<result<<endl;
    return 0;
}