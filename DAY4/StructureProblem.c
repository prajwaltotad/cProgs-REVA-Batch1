#include<stdio.h>

typedef struct {
    char str[250];
    int pinCode;
} Address;

typedef struct {
    int id;
    char name[50];
    float sCap;
    Address address;
} Member;

int main() {
    int n;
    scanf("%d",&n);
    if (n<=0 || n>200) {
        printf("INVALID COUNT");
        return 0;
    }
    Member m[n];
    printf("\nMEMBER LEDGER\n");
    for (int i=0; i<n; i++) {
        scanf("%d%s%f%s%d",&m[i].id,m[i].name,&m[i].sCap,m[i].address.str,&m[i].address.pinCode);
    }
    float cnt=0;
    for (int i=0; i<n; i++) {
        printf("%d %s %s %d %.2f\n",m[i].id,m[i].name,m[i].address.str,m[i].address.pinCode,m[i].sCap);
        cnt+=m[i].sCap;
    }
    printf("Total share capital (Rs): %.2f\n",cnt);
    int idx=0;
    for (int i=0; i<n; i++) {
        if (m[i].sCap > m[idx].sCap){
            idx = i;
        }
    }
    printf("Highest holder: %d %s %s %d %.2f\n",m[idx].id,m[idx].name,m[idx].address.str,m[idx].address.pinCode,m[idx].sCap);
    return 0;
}