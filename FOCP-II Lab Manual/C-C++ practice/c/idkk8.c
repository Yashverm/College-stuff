#include<stdio.h>
int main(){
    int a ;
    printf("Enter a no. : ");
    scanf("%d" , &a);
    for (int i = 2 ; i < a ; i++){
        if (a % i == 0){
            printf("The given number is not prime");
        }
        else {
            printf("The given number is prime");
        }
    }
}