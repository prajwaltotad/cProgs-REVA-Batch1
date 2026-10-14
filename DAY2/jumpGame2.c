
#include <stdio.h>

int jump(int* nums, int numsSize) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (i + nums[i] > farthest)
            farthest = i + nums[i];

        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Minimum jumps: %d\n", jump(nums, size));

    return 0;
}
