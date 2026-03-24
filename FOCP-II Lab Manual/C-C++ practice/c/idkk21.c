#include <stdio.h>

int main() {
    int arr[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    int flag = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && arr[i][j] != 1) {    // 1 0 1 0     i = 0 , j = 0    val 1
                flag = 0;                      // 0 1 0 1     i = 1 , j = 0    val 0
                break;
            } else if (i != j && arr[i][j] != 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }

    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}