#include <stdio.h>

void rev(int ar[] , int s){
    int sta = 0 ;
    int end = s-1;
    while (sta < end){
        int temp = ar[sta];
        ar[sta] = ar[end];
        ar[end] = temp;

        sta++;
        end--;
    }
    }

int main(){
    
    int arr[5] = {1,2,3,4,5};
    int s = sizeof(arr)/sizeof(arr[0]);
    rev(arr , s);

    for (int i = 0 ; i < s ; i++){
        printf("%d  " , arr[i]);
    }
}