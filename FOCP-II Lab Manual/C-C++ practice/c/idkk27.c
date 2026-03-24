#include<stdio.h>

void idk(int a){
    int b;
    for (int i = 1 ; i <= 10 ; i++){
        b = a * i;
        printf("%d x %d = %d \n" , a , i , b);
    }
}

int main(){
    int a;
    scanf("%d" , &a);
    idk(a);
}