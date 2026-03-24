#include <stdio.h>

void calc(int* n1 , int* n2 , int* n3){
    int d = *n1;
    int e = *n2;
    *n1 = *n3;
    *n2 = d;
    *n3 = e;
}

int main(){
    int a = 10;
    int b = 20;
    int c = 30;
    calc(&a,&b,&c);

    printf("%d is 1st\n" , a);
    printf("%d is 2nd\n" , b);
    printf("%d is 3nd\n" , c);

    return 0 ;
}