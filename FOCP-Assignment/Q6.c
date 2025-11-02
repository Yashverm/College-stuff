#include <stdio.h>

int main() {
    int num, sum = 0, n;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        n = num % 10;
        sum += n;
        num /= 10;
    }

    printf("Sum of digits = %d\n", sum);
    
    return 0;
}
