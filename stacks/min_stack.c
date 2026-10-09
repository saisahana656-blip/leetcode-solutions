/* Min Stack teaching example. Push/pop/get-min are O(1). */
#include <stdio.h>
#define CAPACITY 100

typedef struct { int values[CAPACITY]; int mins[CAPACITY]; int size; } MinStack;

int push(MinStack *s, int value) {
    if (s->size == CAPACITY) return 0;
    s->values[s->size] = value;
    s->mins[s->size] = s->size == 0 || value < s->mins[s->size - 1] ? value : s->mins[s->size - 1];
    ++s->size;
    return 1;
}
int pop(MinStack *s, int *value) {
    if (s->size == 0) return 0;
    *value = s->values[--s->size];
    return 1;
}
int get_min(const MinStack *s, int *value) {
    if (s->size == 0) return 0;
    *value = s->mins[s->size - 1];
    return 1;
}
int main(void) {
    MinStack stack = { .size = 0 };
    int value;
    push(&stack, 3); push(&stack, 5); push(&stack, 2);
    if (get_min(&stack, &value)) printf("Minimum: %d\n", value);
    return 0;
}
