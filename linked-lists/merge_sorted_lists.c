/* Merge two sorted lists. Time O(n+m), O(1) auxiliary space. */
#include <stdio.h>

typedef struct Node { int value; struct Node *next; } Node;

Node *merge_sorted(Node *a, Node *b) {
    Node dummy = {0, NULL};
    Node *tail = &dummy;
    while (a != NULL && b != NULL) {
        if (a->value <= b->value) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a != NULL ? a : b;
    return dummy.next;
}
void print_list(const Node *head) {
    while (head != NULL) {
        printf("%d%s", head->value, head->next ? " -> " : "\n");
        head = head->next;
    }
}
int main(void) {
    Node a1 = {1, NULL}, a3 = {3, NULL}, a5 = {5, NULL};
    Node b2 = {2, NULL}, b4 = {4, NULL}, b6 = {6, NULL};
    a1.next = &a3; a3.next = &a5; b2.next = &b4; b4.next = &b6;
    print_list(merge_sorted(&a1, &b2));
    return 0;
}
