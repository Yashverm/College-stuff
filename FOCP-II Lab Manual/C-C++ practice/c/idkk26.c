#include <stdio.h>

void idk(int l , int b){
    int c;
    c = l*b;
    printf("%d",c);
}

int main(){
    int a;
    int b;
    scanf("%d" , &a);
    scanf("%d" , &b);
    idk(a,b);
    return 0;
}