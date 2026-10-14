#include<stdio.h>

int main() {
    int notes[] = {100, 50, 20, 5, 2, 1};
    int num = 856, cnt;
    int n = sizeof notes/sizeof(int);
    for (int i = 0; i < n; i++) {
        cnt += num/notes[i];
        num = num%notes[i];
    }
    printf("The minimum no.of notes: %d\n",cnt);
}