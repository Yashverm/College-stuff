#include <stdio.h>

int main() {
    int n, i, pos, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray before deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nWhere do you want to delete?\n");
    printf("1. Front\n2. Middle\n3. End\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        for(i = 0; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        n--;
    }
    else if(choice == 2) {
        pos = n/2;
        for(i = pos; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        n--;
    }
    else if(choice == 3) {
        n--;
    }
    else {
        printf("Invalid choice!");
        return 0;
    }

    printf("\nArray after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
