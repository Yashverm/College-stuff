#include<stdio.h>

int main(){
    int arr[5];
    for (int a = 0 ; a < 5 ; a++){
        printf("Enter value :");
        scanf("%d" , &arr[a]);
    }
    for (int b = 0 ; b < 5 ; b++){
        printf("%d\n" , arr[b]);
    }

}