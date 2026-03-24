#include<stdio.h>

int main(){

    int arr[4][4];

    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            printf("enter value :");
            scanf("%d" , &arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            printf("%d \t" , arr[i][j]);
        }
        printf("\n");
    }
}

// 1 2 3 4    5 6 7 8
// 1 2 3 4    5 6 7 8
// 1 2 3 4    5 6 7 8
// 1 2 3 4    5 6 7 8