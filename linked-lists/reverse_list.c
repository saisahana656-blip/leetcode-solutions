/* Reverse Linked List. Time O(n), extra space O(1). */
#include <stdio.h>

typedef struct Node { int value; struct Node *next; } Node;

Node *reverse_list(Node *head) {
    Node *previous = NULL, *current = head;
    while (current != NULL) {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
void print_list(const Node *head) {
    while (head != NULL) {
        printf("%d%s", head->value, head->next ? " -> " : "\n");
        head = head->next;
    }
}
int main(void) {
    Node a = {1, NULL}, b = {2, NULL}, c = {3, NULL};
    a.next = &b; b.next = &c;
    print_list(reverse_list(&a));
    return 0;
}
