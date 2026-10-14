#include<stdio.h>

int main() {
    int arr[5];
    int (*ptr)[5]=&arr;
    for (int i=0; i<5; i++) {
        scanf("%d", &(*ptr)[i]);
    }
    for (int i=0; i<5; i++) {
        printf("%d ",(*ptr)[i]);
    }
    return 0;
}