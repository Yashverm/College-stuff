#include <stdio.h>

int main() {
    int n, i, pos, value, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray before insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter value to insert: ");
    scanf("%d", &value);

    printf("\nWhere do you want to insert?\n");
    printf("1. Front\n2. Middle\n3. End\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        for(i = n; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        n++;
    }
    else if(choice == 2) {
        pos = n/2;
        for(i = n; i > pos; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos] = value;
        n++;
    }
    else if(choice == 3) {
        arr[n] = value;
        n++;
    }
    else {
        printf("Invalid choice!");
        return 0;
    }

    printf("\nArray after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
