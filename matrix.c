#include<stdio.h>
#include"matrix.h"
int main() {
    int arr1[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int arr2[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int arr3[2][3];
    int rows = 2;
    int cols = 3;
    printf("*Implementing Addition Function*\n");
    addMatrices(&arr1[0][0], &arr2[0][0], &arr3[0][0], rows, cols);
    printMatrix(&arr3[0][0], rows, cols);
    int arr4[2][2] = {{1, 2}, {3, 4}};
    int arr5[2][2] = {{1, 2}, {3, 4}};
    int arr6[2][2];
    int rows1 = 2;
    int cols1 = 2;
    printf("\n*Implementing Multiplication Function*\n");
    MultiplyMatrices(&arr4[0][0], &arr5[0][0], &arr6[0][0], rows1,cols1);
     printMatrix(&arr6[0][0],rows1, cols1); printf("\n*Implementing Transpose function*\n");
    TransposeMatrix(rows,cols,arr1);
    printf("\n*Implementing Determinant Function*\n");
    Determinant( arr4);
    return 0;
}
