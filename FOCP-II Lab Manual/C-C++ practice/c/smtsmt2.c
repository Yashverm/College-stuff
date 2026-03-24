#include <stdio.h>

int main(){
    int arr[8][8]={{1,2,3,4,5,6,7,8},{4,5,6,4,5,6,7,8},{7,8,9,4,5,6,7,8}};
    int a;
    for( int i = 0 ; i < 8; i++){
        for (int j = 0 ; j < 8 ; j++){
            if ((i + j) % 2 == 0){
                printf("1  ");
            }
            else{
                printf("0  ");
            }

        }
    printf("\n");
    }
}