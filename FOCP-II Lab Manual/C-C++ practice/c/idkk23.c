#include <stdio.h>

int main(){
    /*
    int a = 10;
    int *aptr = &a;
    (*aptr)++;
    printf("%d" , a);
    */

    int a = 10;
    int *aptr = &a;
    int **aaptr = &aptr;
    printf("%d\n" , a);       //value of a
    printf("%p\n" , &a);      //address of variable a
    printf("%u\n" , &a);      //address of variable a
    printf("%u\n" , aptr);    //value of a
    printf("%d\n" , *aptr);   //address of aptr
    printf("%u\n" , aaptr);   //address of aptr
    printf("%u\n" , &aaptr);  //address of aaptr
    printf("%u\n" , *aaptr);  //value of aptr / address of a
    printf("%u\n" , **aaptr); //address of aptr
}   


/*
  a   => value of variable
 &a   => address of variable
*aptr => value of variable
*/