#include <stdio.h>
#include <string.h>

struct user{
    char name[50];
    int age;
    float height;
};

int main(){
    struct user user1;
    user1.age = 25;
    user1.height = 5.6;
    strcpy(user1.name , "idk1");

    printf("%u\n" , user1.name);        //even tho the arr is 50 size the address has a difference of 52 as integer
    printf("%u\n" , &user1.age);        //cant fit in the 2 space left as it takes 4 , this thing is called padding
    printf("%u\n" , &user1.height);

    return 0;
}