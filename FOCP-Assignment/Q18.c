#include <stdio.h>

int main() {
    int n, i, j;
    int found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[100], visited[100];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    printf("\nDuplicate elements: ");

    for(i = 0; i < n; i++) {
        if(visited[i] == 0) {
            int count = 1;

            for(j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    visited[j] = 1;
                }
            }

            if(count > 1) {
                printf("%d ", arr[i]);
                found = 1;
            }
        }
    }

    if(found == 0)
        printf("-1");

    return 0;
}
