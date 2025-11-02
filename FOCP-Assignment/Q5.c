#include <stdio.h>

int main() {
    int x, y;
    
    printf("Enter coordinates (x y): ");
    scanf("%d %d", &x, &y);

    if (x > 0 && y > 0)
        printf("Point lies in 1st Quadrant.\n");
    else if (x < 0 && y > 0)
        printf("Point lies in 2nd Quadrant.\n");
    else if (x < 0 && y < 0)
        printf("Point lies in 3rd Quadrant.\n");
    else if (x > 0 && y < 0)
        printf("Point lies in 4th Quadrant.\n");
    else if (x == 0 && y == 0)
        printf("Point lies at the Origin.\n");
    else if (x == 0 && y != 0)
        printf("Point lies on Y-axis.\n");
    else
        printf("Point lies on X-axis.\n");

    return 0;
}
