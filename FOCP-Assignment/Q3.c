#include <stdio.h>

int main() {
    int a, b, result;

    printf("Enter two numbers (a b): ");
    scanf("%d %d", &a, &b);

    result = a + (~b + 1);

    printf("Result: %d\n", result);
    return 0;
}
