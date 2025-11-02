#include <stdio.h>

int main() {
    int n, a, reversed = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    a = n;

    while (n != 0) {
        digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    if (a == reversed)
        printf("%d is a Palindrome number.\n", a);
    else
        printf("%d is not a Palindrome number.\n", a);

    return 0;
}
