
#include <stdio.h>
#include <stdlib.h>

union Value {
    float temperature;
    char door;
    long pulses;
};

struct Reading {
    int sensorID;
    char kind;
    union Value value;
};

// Equivalent structure with all fields stored simultaneously
struct AllValues {
    int sensorID;
    char kind;
    float temperature;
    char door;
    long pulses;
};

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0 || N > 1000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Reading *readings = malloc(N * sizeof(struct Reading));

    if (readings == NULL) {
        return 1;
    }

    // Read and validate all sensor records
    for (int i = 0; i < N; i++) {
        scanf("%d %c", &readings[i].sensorID, &readings[i].kind);

        if (readings[i].kind != 'T' && readings[i].kind != 'D' && readings[i].kind != 'P') {
            printf("INVALID KIND\n");
            free(readings);
            return 0;
        }

        switch (readings[i].kind) {
            case 'T':
                scanf("%f", &readings[i].value.temperature);
                break;

            case 'D':
                scanf(" %c", &readings[i].value.door);
                break;

            case 'P':
                scanf("%ld", &readings[i].value.pulses);
                break;
        }
    }

    printf("\nSENSOR REPORT\n");

    for (int i = 0; i < N; i++) {
        printf("Sensor %d ", readings[i].sensorID);

        switch (readings[i].kind) {
            case 'T':
                printf("temperature %.2f C\n", readings[i].value.temperature);
                break;

            case 'D':
                if (readings[i].value.door == 'O')
                    printf("door OPEN\n");
                else
                    printf("door CLOSED\n");
                break;

            case 'P':
                printf("pulses %ld\n", readings[i].value.pulses);
                break;
        }
    }

    printf("sizeof(union Value): %zu\n", sizeof(union Value));

    printf("sizeof(Reading) with union: %zu\n", sizeof(struct Reading));

    printf("sizeof(Reading) with all fields: %zu\n", sizeof(struct AllValues));

    printf("Bytes saved per record: %zu\n", sizeof(struct AllValues) - sizeof(struct Reading));

    free(readings);

    return 0;
}
