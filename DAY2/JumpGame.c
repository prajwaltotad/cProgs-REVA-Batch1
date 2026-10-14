
#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int reach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > reach)
            return false;

        if (i + nums[i] > reach)
            reach = i + nums[i];
    }

    return true;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    bool result = canJump(nums, size);

    printf("Input: [2, 3, 1, 1, 4]\n");
    printf("Output: %s\n", result ? "true" : "false");

    return 0;
}
