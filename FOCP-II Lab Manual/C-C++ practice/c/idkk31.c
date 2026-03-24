#include <stdio.h>

int fact(int n1){

    if (n1 == 0)
    return 1;

    return n1 * fact(n1 - 1);
}

int main(){
    int a = 5;
    int factval = fact(a);
    printf(factval);
}