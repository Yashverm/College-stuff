#include <stdio.h>

void calc(int n1 , int n2 , int* sum , int* sub){
    *sum = n1 + n2;
    *sub = n1 - n2;
}

int main(){
    int a = 10;
    int b = 20;
    int sum , sub;
    calc(a,b,&sum,&sub);

    printf("%d\n" , sum);
    printf("%d\n" , sub);

    return 0 ;
}