#include <stdio.h>
#include <string.h>

struct user{
    char name[100];
    int age;
    float height;
};

int main(){
    struct user user1;
    user1.age = 25;
    user1.height = 5.6;
    strcpy(user1.name , "idk1");

    struct user user2;
    user2.age = 30;
    user2.height = 4.6;
    strcpy(user2.name , "idk2");
    
    printf("%s\n" , user1.name);
    printf("%d\n" , user1.age);
    printf("%f\n" , user1.height);
    printf("--------------------\n");
    printf("%s\n" , user2.name);
    printf("%d\n" , user2.age);
    printf("%f\n" , user2.height);

    return 0;
}