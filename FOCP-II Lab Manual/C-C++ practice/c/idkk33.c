//command line arguments
#include <stdio.h>
#include <stdlib.h>

int main (int argc , char* argv[]){

    // printf("%d\n" , argc);
    // printf("%s\n" , argv[0]);
    // printf("%s\n" , argv[1]);
    // printf("%s\n" , argv[2]);
    int a = atoi(argv[1]);         // atoi turns the value into integer
    int b = atoi(argv[2]);

    printf("%d\n" , a + b);

    return 0;
}