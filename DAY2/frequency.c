#include <stdio.h>

int main()
{
    char str[] = "BWibsuaBSIbsiB";
    int hash[52] = {0};
    for (int i = 0; str[i] != 0; i++)
    {
        char ch = str[i];
        int idx;
        if (ch >= 'A' && ch <= 'Z')
        {
            idx = ch - 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            idx = ch - 'a';
        }
        else
        {
            continue;
        }
        hash[idx]++;
    }

    for (int i = 0; i < 52; i++)
    {
        if (hash[i] > 0)
        {
            char ch = (i < 26) ? 'A' + i : 'a' + i - 26;
            printf("%c: %d\n", ch, hash[i]);
        }
    }
}