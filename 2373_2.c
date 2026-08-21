

#include <stdio.h>

#define MAX 50   

int mat[10][10];       
int rows, cols;

int compact[MAX][3];    
int terms;             

int result[MAX][3];     


void inputMatrix() {
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}


void convertToCompact() {
    terms = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                compact[terms][0] = i;
                compact[terms][1] = j;
                compact[terms][2] = mat[i][j];
                terms++;
            }
        }
    }
    printf("Matrix converted to compact form. Non-zero terms = %d\n", terms);
}


void displayCompact(int arr[][3], int n, int r, int c) {
    printf("Rows: %d, Cols: %d, Terms: %d\n", r, c, n);
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}


void simpleTranspose() {
    int k = 0;
    for (int c = 0; c < cols; c++) {
        for (int i = 0; i < terms; i++) {
            if (compact[i][1] == c) {
                result[k][0] = compact[i][1]; 
                result[k][1] = compact[i][0]; 
                result[k][2] = compact[i][2];
                k++;
            }
        }
    }
    printf("\nSimple Transpose:\n");
    displayCompact(result, terms, cols, rows);
}


void fastTranspose() {
    int count[10] = {0};       
    int pos[10] = {0};         

    
    for (int i = 0; i < terms; i++) {
        count[compact[i][1]]++;
    }

  
    pos[0] = 0;
    for (int i = 1; i < cols; i++) {
        pos[i] = pos[i - 1] + count[i - 1];
    }

    
    for (int i = 0; i < terms; i++) {
        int c = compact[i][1];
        int p = pos[c];

        result[p][0] = compact[i][1];
        result[p][1] = compact[i][0];
        result[p][2] = compact[i][2];

        pos[c]++;
    }

    printf("\nFast Transpose:\n");
    displayCompact(result, terms, cols, rows);
}


int main() {
    int choice;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Enter Sparse Matrix\n");
        printf("2. Convert to Compact Form\n");
        printf("3. Simple Transpose\n");
        printf("4. Fast Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix();
                break;
            case 2:
                convertToCompact();
                displayCompact(compact, terms, rows, cols);
                break;
            case 3:
                simpleTranspose();
                break;
            case 4:
                fastTranspose();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);

    return 0;
}