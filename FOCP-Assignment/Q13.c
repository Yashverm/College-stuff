#include <stdio.h>

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        if ((i == 0 || arr[i] >= arr[i-1]) && 
            (i == n-1 || arr[i] >= arr[i+1])) {

            printf("Peak element: %d at index %d\n", arr[i], i);
            return 0;
        }
    }

    printf("No peak element found.\n");
    return 0;
}
