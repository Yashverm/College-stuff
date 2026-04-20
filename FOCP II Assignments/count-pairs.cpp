#include <iostream>

using namespace std;

int main() {
    int t;

    if (!(cin>>t)) return 0;

    while (t--){
        long long n;
        cin>>n;
        
        if (n==1){
            cout<<1<<endl;
            continue;
        }
    
        int count=0;
        long long temp=n;
        
        for (long long i=2;i*i<=temp;i++){
            if (temp%i==0){
                count++;
                while (temp%i==0)temp/=i;
            }
        }
        if (temp>1) count++;

        long long ans=1;
        for (int i=0;i<count;i++) {
            ans*=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}