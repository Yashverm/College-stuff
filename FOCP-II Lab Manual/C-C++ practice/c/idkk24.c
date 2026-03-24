#include <stdio.h>
int main(){
    int arr[] = {10,20,30,40,50};
    int* arrptr = &arr;
    for (int i = 0 ; i < 5 ;){
        // printf("%u\n" , *(arrptr + 1));
        printf("%u\n" , arrptr);
        arrptr++;
    }
}