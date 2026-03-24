/*
   int - %d
   float - %f
   char - %c
   double - %lf
*/

#include<stdio.h>
int main() {
    char t = 'C';
    int p = 275;
    int l = 1972;
    float pr = 350.50;
    printf("Title : %c \n" , t);
    printf("Page : %d \n" , p);
    printf("Launch : %d \n" , l);
    printf("Price : %f \n" , pr);
    printf("Title : %c \nPage : %d \nLaunch : %d \nPrice %f \n", t , p , l , pr);
    return 0;
}