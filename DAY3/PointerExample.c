#include<stdio.h>

int main() {
    int n=10;
    int *ptr=&n;
    int *ptr2=NULL;
    printf("%d ",n);
    printf("%p ",(void*)&n);
    printf("%p ",(void*)ptr2);
    char ch='A';
    char *p=&ch;
    *p='B';
    printf("%c ",ch);

}