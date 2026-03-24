// largest / smallest from 2d array

#include <stdio.h>

int main(){
    int arr[2][3]={{1,2,3},{4,5,6}};
    int a = arr[0][0];
    int b = arr[0][0];
    for( int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (a < arr[i][j])
                a = arr[i][j];
            if (arr[i][j] < b)
                b = arr[i][j];
        }
    }
    printf("%d" , a);
    printf("%d" , b);
}
    
