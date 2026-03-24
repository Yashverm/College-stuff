#include<stdio.h>
int main() {
    int a ;
    int b = 0;
    printf("Enter value of a : ");
    scanf("%d" , &a);
    for (int i = 1 ; i <= 10 ; i++) {
        b = a*i ;
        printf("%d\n",b);
    }
}