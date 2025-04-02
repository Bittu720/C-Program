#include <stdio.h>
int main() {
    int m, n, i, j;
    printf("Enter number of rows and columns for the matrices: ");
    scanf("%d %d", &m, &n);
    int matrix1[m][n], matrix2[m][n], sub[m][n];
    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sub[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Sub of the matrices:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
    return 0;
}
