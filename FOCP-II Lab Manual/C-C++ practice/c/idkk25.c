#include <stdio.h>

int main(){
    int a;
    printf("enter no1 :");
    scanf("%d" , &a);
    int b;
    printf("enter no1 :");
    scanf("%d" , &a);
    int c;
    printf("enter no1 :");
    scanf("%d" , &a);
    int *ap = &a;
    int *bp = &b;
    int *cp = &c;

    if (ap > bp && ap > cp){
        printf("%d is biggest" , *ap);
    }
    if (bp > ap && bp > cp){
        printf("%d is biggest" , *bp);
    }
    if (cp > ap && cp > bp){
        printf("%d is biggest" , *cp);
    }
}