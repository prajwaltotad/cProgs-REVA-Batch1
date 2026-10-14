#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*ptr)(int, int) = add;
    int x=10;
    int *const p=&x;
    *p=50;
    printf("%p %d ",p,x);
    printf("%d ",ptr(10,20));
    return 0;
}
