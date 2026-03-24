#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*int main(){
    char x = 'a';
    char y  = 'B';
    printf("%c" , toupper(x));
    printf("%c" , tolower(y));
}*/

/*int main(){
    char arr[100] = "Hello";
    for (int i = 0 ; i < 5 ; i++){
        printf("%c" ,tolower(arr[i]));
    }
    printf("\n");

    for (int i = 0 ; i < 5 ; i++){
        printf("%c" ,toupper(arr[i]));
    }
    printf("\n");
}*/

int main(){
    char arr[100] = "Hello";
    char arr1[] = "Everyone";

    printf("%d" , strlen(arr)); //find length

    strcpy(arr , arr1); //copies
    printf("%s" , arr); //output : "Everyone"

    strcat(arr , arr1); //concates/combines
    printf("%s" , arr);
}