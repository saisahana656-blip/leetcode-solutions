/*
 * Problem: Two Sum
 * Approach: Check each pair. This simple version is easy to understand.
 * Time: O(n^2) | Extra space: O(1)
 */
#include <stdio.h>

int main(void) {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = (int)(sizeof(nums) / sizeof(nums[0]));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                printf("Indices: %d, %d\n", i, j);
                return 0;
            }
        }
    }
    puts("No pair found");
    return 0;
}
