#include <stdio.h>
#include <string.h>

struct user {
    char name[50];
    int age;
    float height;
};

int main(){
    struct user arr[3];
    arr[0].age = 25;
    arr[0].height = 5.5;
    strcpy(arr[0].name , "hello");

    return 0;
}