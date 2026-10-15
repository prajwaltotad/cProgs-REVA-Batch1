
#include <stdio.h>
#include <stdlib.h>

struct Ticket
{
    int ticketNo;
    char vehicleNo[20];
    float grossWeight;
    float tareWeight;
};

// Helper 1: Calculate net weight using a pointer
float netWeight(struct Ticket *t)
{
    return t->grossWeight - t->tareWeight;
}

// Helper 2: Print ticket details using a pointer
void printTicket(struct Ticket *t)
{
    printf("%d %s gross %.2f tare %.2f net %.2f\n",
           t->ticketNo,
           t->vehicleNo,
           t->grossWeight,
           t->tareWeight,
           netWeight(t));
}

int main()
{
    int N;
    scanf("%d", &N);

    if (N <= 0 || N > 100000)
    {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Ticket *tickets = malloc(N * sizeof(struct Ticket));

    if (tickets == NULL)
    {
        return 1;
    }

    float total = 0.0f;
    int heaviest = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %19s %f %f", &tickets[i].ticketNo, tickets[i].vehicleNo, &tickets[i].grossWeight, &tickets[i].tareWeight);

        float net = netWeight(&tickets[i]);
        total += net;

        if (i == 0 || net > netWeight(&tickets[heaviest]))
        {
            heaviest = i;
        }
    }

    printf("\nWEIGHBRIDGE DAY BOOK\n");

    for (int i = 0; i < N; i++)
    {
        printTicket(&tickets[i]);
    }

    printf("Tickets: %d\n", N);
    printf("Total net weight (kg): %.2f\n", total);

    printf("Heaviest net load: ticket %d %s %.2f\n",
           tickets[heaviest].ticketNo,
           tickets[heaviest].vehicleNo,
           netWeight(&tickets[heaviest]));

    free(tickets);

    return 0;
}