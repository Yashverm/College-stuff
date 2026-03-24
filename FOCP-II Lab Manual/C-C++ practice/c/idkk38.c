#include <stdio.h>
#include <string.h>

struct student {
    char name[100];
    int rollnum;
    float cgpa;
};

int main(){
struct student studentdata[5];

studentdata[0].rollnum = 1000;
studentdata[0].cgpa = 5.5;
strcpy(studentdata[0].name , "eeeee");

studentdata[1].rollnum = 1000;
studentdata[1].cgpa = 5.5;
strcpy(studentdata[1].name , "eeeee");

for (int i = 0 ; i < 3 ; i++){
    printf("%s\n" , studentdata[i].name);
}
}