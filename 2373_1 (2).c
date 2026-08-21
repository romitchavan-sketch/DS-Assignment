#include <stdio.h>
#include <stdlib.h>

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[10][10], int mat2[10][10], int r, int c) {
    int result[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("\nResult of Addition:\n");
    displayMatrix(result, r, c);
}

void subtractMatrices(int mat1[10][10], int mat2[10][10], int r, int c) {
    int result[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printf("\nResult of Subtraction:\n");
    displayMatrix(result, r, c);
}

void multiplyMatrices(int mat1[10][10], int r1, int c1, int mat2[10][10], int r2, int c2) {
    if (c1 != r2) {
        printf("\nError: Multiplication not possible. Columns of Matrix 1 must equal Rows of Matrix 2.\n");
        return;
    }
    int result[10][10] = {0};
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("\nResult of Multiplication:\n");
    displayMatrix(result, r1, c2);
}

void transposeMatrix(int matrix[10][10], int r, int c) {
    int result[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    displayMatrix(result, c, r);
}

int main() {
    int mat1[10][10], mat2[10][10];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements for Matrix 1:\n");
    readMatrix(mat1, r1, c1);

    printf("\nEnter rows and columns for Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements for Matrix 2:\n");
    readMatrix(mat2, r2, c2);

    while (1) {
        printf("\n--- MATRIX OPERATIONS MENU ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (r1 == r2 && c1 == c2) {
                    addMatrices(mat1, mat2, r1, c1);
                } else {
                    printf("\nError: Matrices must have identical dimensions for addition.\n");
                }
                break;
            case 2:
                if (r1 == r2 && c1 == c2) {
                    subtractMatrices(mat1, mat2, r1, c1);
                } else {
                    printf("\nError: Matrices must have identical dimensions for subtraction.\n");
                }
                break;
            case 3:
                multiplyMatrices(mat1, r1, c1, mat2, r2, c2);
                break;
            case 4:
                printf("\nTranspose of Matrix 1:\n");
                transposeMatrix(mat1, r1, c1);
                printf("\nTranspose of Matrix 2:\n");
                transposeMatrix(mat2, r2, c2);
                break;
            case 5:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

