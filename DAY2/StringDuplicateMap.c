
#include <stdio.h>

int main() {
    char str[] = "abccf";
    int hash[26] = {0};
    for (int i = 0; str[i]!='\0'; i++) {
        char ch = str[i];
        int idx = ch - 'a';
        if (hash[idx] > 0) {
            printf("Duplicated");
            return 0;
        } else {
            hash[idx]++;
        }
    }
    printf("No duplicated");
}