#include <stdio.h>

void printNumbers(int a , int b) {
    if (a > b) {
        return;
    }
    printf("%d ", a);
    printNumbers(a + 1 , b);
}

int main() {
    int a;
    int b;
    scanf("enter starting point %d" , &a);
    scanf("enter ending point %d" , &b);
    printNumbers(a , b);
    return 0;
}