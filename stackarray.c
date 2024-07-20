#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Maximum size of the stack

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
// By default the value of the 'top' variable in stack is initialized to -1 when the stack is empty
void initialize(Stack *s) {
    s->top = -1; 
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1; 
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
    // '++(s->top)': This increments the top index by 1. 
    // 's->items[...]': After incrementing s->top, this new value is used as the index to access the array 'items'.
    // 's->items[++(s->top)]': This accesses the position in the array where the new element will be stored.
    // '= value;': The given value is assigned to this position in the array.
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
    // '(s->top)--': the current value of s->top is used in the expression first, and then s->top is decremented by 1.
    // 's->items[...]': This accesses the array items at the index specified by the current value of 's->top'.

}

// Peek at the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

int main() {
    Stack s;
    initialize(&s);

    // Inserting the values in the stack one by one.
    printf("Enter elements in the stack (enter a non-integer to stop):\n");
    while (1) {
        int value;
        if (scanf("%d", &value) != 1) {
            break; // Stop reading if input is not an integer
        }
        push(&s, value);
    }

    printf("Top element is %d\n", peek(&s));
    printf("Popped element is %d\n", pop(&s));
    printf("Top element is %d\n", peek(&s));

    return 0;
}
