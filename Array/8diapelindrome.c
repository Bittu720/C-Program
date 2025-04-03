#include <stdio.h>
int main() {
    int rows ; 
    int i, j;
    printf("enter rows :");
    scanf("%d",&rows);
    for (i = 1; i <= rows; i++) {
        for (j = i; j < rows; j++) {
            printf("  ");
        }
        for (j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        for (j = 2; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
