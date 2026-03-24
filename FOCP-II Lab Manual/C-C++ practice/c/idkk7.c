#include<stdio.h>
int main(){
    int c = 1;
    int a;
    printf("Enter value of a : ");
    scanf("%d/n" , &a);
    for(a ; a >= 1 ; a--) {
        c = c*a;
    }
    printf("Total : %d " , c);
    return 0;
}