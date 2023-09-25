//To perform Strassen's Matrix Multiplication in c
#include <stdio.h>
#define N 64 
void addMatrix(int A[][N], int B[][N], int C[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrix(int A[][N], int B[][N], int C[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassenMultiply(int A[][N], int B[][N], int C[][N], int size) {
    if (size <= 32) { // Base case: Use a simple matrix multiplication algorithm
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                C[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return;
    }
    int newSize = size / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    subtractMatrix(B12, B22, temp1, newSize);
    strassenMultiply(A11, temp1, C11, newSize);
    addMatrix(A11, A12, temp1, newSize);
    strassenMultiply(temp1, B22, C12, newSize);
    addMatrix(A21, A22, temp1, newSize);
    strassenMultiply(temp1, B11, C21, newSize);
    subtractMatrix(B21, B11, temp1, newSize);
    strassenMultiply(A22, temp1, C22, newSize);
    addMatrix(A12, A22, temp1, newSize);
    strassenMultiply(temp1, B21, temp2, newSize);
    addMatrix(temp2, C11, C12, newSize);
    subtractMatrix(C21, C11, C11, newSize);
    subtractMatrix(C12, C22, C12, newSize);
    addMatrix(C11, C12, temp1, newSize);
    addMatrix(temp1, C21, temp2, newSize);
    addMatrix(temp2, C22, C, newSize);
}
void printMatrix(int A[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int size;
    printf("-------------------------------------------------------------");
    printf("\nEnter the size of the square matrices (must be a power of 2): ");
    scanf("%d", &size);
    int A[N][N], B[N][N], C[N][N];
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    strassenMultiply(A, B, C, size);
    printf("Resultant matrix C:\n");
    printMatrix(C, size);
    printf("-------------------------------------------------------------");
    return 0;
}
