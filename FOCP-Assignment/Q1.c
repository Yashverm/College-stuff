#include <stdio.h>

int main() {
    int num, temp, sum = 0, digit, digits = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    int n = num;
    while (n != 0) {
        digits++;
        n /= 10;
    }

    n = num;
    while (n != 0) {
        digit = n % 10;

        int power = 1;
        for(int i = 0; i < digits; i++) {
            power *= digit;
        }

        sum += power;
        n /= 10;
    }

    if (sum == temp)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
