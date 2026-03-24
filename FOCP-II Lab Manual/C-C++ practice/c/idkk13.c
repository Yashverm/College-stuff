#include <stdio.h>
int main(){
    int arr[10] = {10,20,30,40,50,60,70}; 
    int c = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1 ; i < c ; i++){
        arr[i-1] = arr[i];
    }
    for (int j = 0 ; j < c ; j++){
        printf("%d\n" , arr[j]);
    }
    return 0;
}
/*int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int c = sizeof(arr) / sizeof(arr[0]);

    for (int i = c-1 ; i >= 0 ; i--){
        arr[i] = arr[i-1];
    }
    for (int j = 0 ; j < c ; j++){
        printf("%d\n" , arr[j]);
    }
    return 0;
}
*/