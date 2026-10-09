/* Valid Parentheses: supports (), [], {}. Time O(n), space O(n). */
#include <stdio.h>

int is_valid(const char *s) {
    char stack[1024];
    int top = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            if (top >= (int)sizeof(stack)) return 0;
            stack[top++] = c;
        } else {
            if (top == 0) return 0;
            char open = stack[--top];
            if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{')) return 0;
        }
    }
    return top == 0;
}

int main(void) {
    printf("%s\n", is_valid("{[()]}") ? "true" : "false");
    return 0;
}
