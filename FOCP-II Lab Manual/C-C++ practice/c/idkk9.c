#include<stdio.h>

/*
Entry control loop : for , while
Exit control loop : do while
*/

int main(){
    for (int i = 5 ; i>=1 ; i--){
        for (int j = 1 ; j<=i ; j++){
            printf("*");
        }
    printf("\n");
    }
}

int main(){
    for (int i = 1 ; i <= 5 ; i++){
        for (int j = 1 ; j<=i ; j++){
            printf("*");
        }
    printf("\n");
    }
}