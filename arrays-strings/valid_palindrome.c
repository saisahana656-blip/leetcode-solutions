/*
 * Problem: Valid Palindrome (ASCII alphanumeric input)
 * Time: O(n) | Extra space: O(1)
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s) {
    int left = 0;
    int right = (int)strlen(s) - 1;
    while (left < right) {
        while (left < right && !isalnum((unsigned char)s[left])) ++left;
        while (left < right && !isalnum((unsigned char)s[right])) --right;
        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) return 0;
        ++left;
        --right;
    }
    return 1;
}

int main(void) {
    const char *sample = "A man, a plan, a canal: Panama";
    printf("%s\n", is_palindrome(sample) ? "true" : "false");
    return 0;
}
