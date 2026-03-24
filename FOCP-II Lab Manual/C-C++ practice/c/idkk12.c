#include <stdio.h>
int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int c = sizeof(arr) / sizeof(arr[0]);

    int n = 5;

    for (int i = c-1 ; i > n ; i--){
        arr[i] = arr[i-1];
    }
    arr[5] = 7;
    
    for (int j = 0 ; j < c ; j++){
        printf("%d\n" , arr[j]);
    }
    return 0;
}