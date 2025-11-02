#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\noriginal values: a = %d, b = %d\n", a, b);

    int x = a, y = b;
    int temp = x;
    x = y;
    y = temp;
    printf("\nafter swaping: a = %d, b = %d", x, y);

    return 0;
}
