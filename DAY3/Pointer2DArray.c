#include<stdio.h>

int main() {
    int arr[2][3]={
        {10, 20, 30},
        {40, 50, 60}
    };
    int (*ptr)[3]=arr;
    printf("%d ", ptr[1][2]);
    printf("%d ",*((*ptr) + 2));
    return 0;
}