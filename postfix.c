#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the maximum size of the stack
#define MAXSTACK 100

// Define a stack structure
typedef struct {
    int top;
    int items[MAXSTACK];
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAXSTACK - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        s->items[++(s->top)] = value;
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return s->items[(s->top)--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    Stack stack;
    initStack(&stack);
    int i;

    // Scan all characters one by one
    for (i = 0; exp[i]; ++i) {
        // If the character is a space, skip it
        if (exp[i] == ' ') continue;

        // If the character is a digit, push it to the stack
        if (isdigit(exp[i])) {
            int num = 0;

            // There may be more than one digit in the number
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;

            push(&stack, num);
        }
        // If the character is an operator, pop two elements from the stack, apply the operator, and push the result back
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
    }

    // The result is the last element in the stack
    return pop(&stack);
}

int main() {
    char exp[] = "100 200 + 2 / 5 * 7 +";
    printf("Postfix evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}
