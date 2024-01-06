#include<stdio.h>
void addMatrices(int *arr1, int *arr2, int *arr3, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(arr3 + i * cols + j) = *(arr1 + i * cols + j) + *(arr2 + i * cols + j);
        }
    }
}
void printMatrix(int *arr3, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr3 + i * cols + j));
        }
        printf("\n");
    }
}
void MultiplyMatrices(int *arr1, int *arr2, int *arr3, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(arr3 + i * cols + j) = 0;
             for (int k = 0; k < cols; k++) {
                *(arr3 + i * cols + j) += *(arr1 + i * cols + k) * *(arr2 + k * cols + j);
            }
        }
    }
}
void TransposeMatrix(int rows, int cols, int matrix[rows][cols]) {
    int matrix1[cols][rows];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
       matrix1[j][i] = matrix[i][j];
        }
    }
    printf("The given matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        };printf("\n");}
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            printf("%d ", matrix1[i][j]);}; printf("\n");}
}
void Determinant(int matrix[2][2]) {
    printf("Matrix:\n");
    printMatrix(&matrix[0][0],2,2);
    printf("Determinant: %d",matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}
