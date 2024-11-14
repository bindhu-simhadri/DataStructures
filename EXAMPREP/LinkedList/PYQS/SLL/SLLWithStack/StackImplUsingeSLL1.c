/*Write code to implement stack operations (push and pop) using singly linked
 * list. */

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the stack (singly linked list)
struct Node {
  int data;
  struct Node *next;
};

// Function to push an item onto the stack
void push(int data, struct Node **top) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  new_node->data = data; // Set the data
  new_node->next = *top; // Link the new node to the current top
  *top = new_node;       // Update the top pointer to the new node
  printf("Pushed %d onto the stack\n", data);
}

// Function to pop an item from the stack
int pop(struct Node **top) {
  if (*top == NULL) {
    printf("Stack is empty\n");
    return -1; // Return -1 if stack is empty
  }

  struct Node *temp = *top;      // Temporary pointer to hold the top node
  int popped_value = temp->data; // Get the data from the top node
  *top = (*top)->next;           // Move the top pointer to the next node
  free(temp);                    // Free the memory of the popped node

  return popped_value;
}

// Function to display the stack
void display(struct Node *top) {
  if (top == NULL) {
    printf("Stack is empty\n");
    return;
  }

  struct Node *temp = top;
  printf("Stack: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function to test stack operations
int main() {
  struct Node *top = NULL; // Initially, the stack is empty

  push(10, &top); // Push 10 onto the stack
  push(20, &top); // Push 20 onto the stack
  push(30, &top); // Push 30 onto the stack

  display(top); // Display the current stack

  int popped_value = pop(&top);         // Pop the top item from the stack
  printf("Popped: %d\n", popped_value); // Display the popped item

  display(top); // Display the current stack after popping

  popped_value = pop(&top);             // Pop another item from the stack
  printf("Popped: %d\n", popped_value); // Display the popped item

  display(top); // Display the current stack after popping again

  return 0;
}

/* SAMPLE OUTPUT
Pushed 10 onto the stack
Pushed 20 onto the stack
Pushed 30 onto the stack
Stack: 30 20 10
Popped: 30
Stack: 20 10
Popped: 20
Stack: 10
*/