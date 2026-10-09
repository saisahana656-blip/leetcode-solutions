/* Binary Search: array must be sorted. Time O(log n), extra space O(1). */
#include <stdio.h>

int binary_search(const int a[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void) {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));
    printf("Index: %d\n", binary_search(nums, n, 9));
    return 0;
}
