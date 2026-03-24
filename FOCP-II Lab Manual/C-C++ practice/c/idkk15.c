#include <stdio.h>
int main(){
    char arr[100];
    printf("enter your name :");
    scanf("%s" , arr);
    for (int i = 1 ; i <= 5 ; i++){
        printf("%s\n" , arr);
    }

    return 0;
}

/*#include <stdio.h>
int main(){
    char arr[] = {'h','e','l','l','o','\0'};
    int c = sizeof(arr) / sizeof(arr[0]);
    printf("%d" , c)
}*/