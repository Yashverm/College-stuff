#include <stdio.h>

int main(){
    int arr[4][4];
    for (int i = 0 ; i<4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            printf("Enter values of array :");
            scanf("%d" , &arr[i][j]);
        }
    printf("\n");
    }

    for (int i = 0 ; i<4; i++){
        for (int j = 0 ; j < 4 ; j++){
            printf("%d\t" , arr[i][j]);
        }
    printf("\n");
    }
}



// arr[i] != '\0'    null tak chelga