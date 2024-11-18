/* 1C. One of the applications of a stack is to convert prefix expressions to postfix expressions.
Determine the steps involved to demonstrate the use of stack in converting prefix to postfix expression.*/

/* REFER TO GOOGLE DOCS / chatgpt for algorithm https://docs.google.com/document/d/1jqwwo7oYQVkM4DQ_fiVnXGJHBSsL2ikxgg2wvYjOoUc/edit?tab=t.0*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX][MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, char *item) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    strcpy(s->data[++(s->top)], item);
}

// Pop an element from the stack
void pop(Stack *s, char *result) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return;
    }
    strcpy(result, s->data[(s->top)--]);
}

// Convert prefix to postfix
void prefixToPostfix(char *prefix, char *postfix) {
    Stack s;
    initStack(&s);

    // Reverse the prefix expression
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) { // If operand
            char operand[2] = {prefix[i], '\0'};
            push(&s, operand);
        } else { // If operator
            char operand1[MAX], operand2[MAX];
            pop(&s, operand1);
            pop(&s, operand2);

            // Combine operands in postfix format
            char combined[MAX];
            sprintf(combined, "%s %s %c", operand1, operand2, prefix[i]);
            push(&s, combined);
        }
    }

    // Final result is the only element left in the stack
    pop(&s, postfix);
}

int main() {
    char prefix[MAX], postfix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


/*SAMPLE OUTPUT
INPUT:
Enter a prefix expression: *+ABC

OUTPUT:
Postfix expression: A B + C *
*/
