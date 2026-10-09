/* Fibonacci Number, iterative. Time O(n), extra space O(1). */
#include <stdio.h>

int fibonacci(int n) {
    if (n < 0) return -1;
    if (n < 2) return n;
    int previous = 0, current = 1;
    for (int i = 2; i <= n; ++i) {
        int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int main(void) {
    printf("F(6) = %d\n", fibonacci(6));
    return 0;
}
