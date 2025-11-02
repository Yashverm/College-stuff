#include <stdio.h>

int main() {
    int arr[100], n, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        if(arr[i] == 99) {
            printf("First occurrence of 99 is at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("99 not found in the array.\n");
    }

    return 0;
}
