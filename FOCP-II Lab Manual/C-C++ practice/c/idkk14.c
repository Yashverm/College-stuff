/*#include <stdio.h>
int main(){
    char arr[] = {'h','e','l','l','o','\0'};
    int c = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0 ; i < c ; i++){
        printf("%c\n",arr[i]);
    }
    printf("%s" , arr);
}*/

#include <stdio.h>
int main(){
    char arr[] = "";
    printf("enter your name :");
    // scanf("%s" , arr);
    // printf("%s" , arr);
    fgets(arr , 100 , stdin);
    printf("%s" , arr);

    return 0;
}