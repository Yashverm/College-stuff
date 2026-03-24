#include <stdio.h>

int main(){
    char a ;
    printf("Enter a character : ");
    scanf("%c" , &a);
    char arr[] = "aAeEiIoOuU";  // 1,2,3,4  
    int b = sizeof(arr) / sizeof(arr[1]);
    for (int i = 0 ; i < b ; i++ ){
        if (arr[i] != 'a'){
            printf("\n not a vovel");
            break;
        }
        else{
            printf("\n vovel");
            break;
        }
    }
    return 0;
}

// arr[i] != '\0'    null tak chelga

// int = 4
// char = 1

/*
char list1[100];
scanf("%s" , arr);
int b = sizeof(arr) / sizeof(arr[1]);
int c = 0;
for (int i = 0 ; i < b ; i++ ){
    if ( list1[i] == 'a'{
        c+=1
        }
}
printf(c)
*/