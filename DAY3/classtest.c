#include <stdio.h>

void rotate(int (*arr)[3], int (*res)[3], int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(res + j) + (row - 1 - i)) = *(*(arr + i) + j);
        }
    }
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int res[3][3];
    int row = 3, cols = 3;

    rotate(arr, res, row, cols);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(res + i) + j));
        }
        printf("\n");
    }

    return 0;
}