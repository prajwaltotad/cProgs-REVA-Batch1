#include<stdio.h>

int main() {
    int arr[3]={10,20,30};
    int (*ptr)[3]=&arr;
    printf("%d ",(*ptr)[2]);
}