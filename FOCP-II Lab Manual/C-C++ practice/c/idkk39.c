#include <stdio.h>

// void val(){
//     static int a = 10;
//     a++;
//     printf("%d\n" , a);
// }

// int main(){

//     val();
//     val();
//     val();

//     return 0;
// }

// int main(){

//     register int a = 10;
//     register int b = 20;
//     int c = a + b;
// }

void val(){
    extern int a;
    printf("%d\n" , a);
}

int a = 10;

int main(){
    val();

    return 0;
}


// Storage classes
// auto , static , extern , register