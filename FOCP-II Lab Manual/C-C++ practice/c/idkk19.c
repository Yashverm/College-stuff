#include <stdio.h>

int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int a;
    for( int i = 0 ; i < 3; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (i == j)
            printf("%d" , arr[i][j]);
        }
        printf("\n");

    }
}

/*
  i j       i j       i j
1(0,0)    2(0,1)    3(0,2)
4(1,0)    5(1,1)    6(1,2)
7(2,0)    8(2,1)    9(2,2)

for( int i = 0 ; i < 3; i++){
        for (int j = 0 ; j < 3 ; j++){
            if ((i+j) % 2 = 0)
                printf("0 \t")}
            else 
                printf("1 \t")

*/