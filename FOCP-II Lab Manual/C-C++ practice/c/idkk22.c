#include<stdio.h>

int main(){
    int a = 1;
    int b = 2;
    int* ap = &a;
    int* bp = &b;

    int c = *ap;

    a = *bp;
    b = c;
    

    printf("%d" , a);
    printf("%d" , b);
}