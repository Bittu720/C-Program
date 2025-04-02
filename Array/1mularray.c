#include <stdio.h>
int main() {
    int m, n, p, q, i, j, k;
    scanf("%d %d", &m, &n);
    int matrix1[m][n];
    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    scanf("%d %d", &p, &q);
    int matrix2[p][q];
    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    if (n == p) {
        int product[m][q];
        for (i = 0; i < m; i++) {
            for (j = 0; j < q; j++) {
                product[i][j] = 0;
                for (k = 0; k < n; k++) {
                    product[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        printf("Matrix Multiplication Result:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < q; j++) {
                printf("%d ", product[i][j]);
            }
            printf("\n");
        }
    } 
    return 0;
}