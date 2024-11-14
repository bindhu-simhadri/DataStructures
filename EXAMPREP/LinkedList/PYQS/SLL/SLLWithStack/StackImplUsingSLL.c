/* Write C functions to implement stack using singly linked list without a
header node and the list is not circular. The prototype of stack operations are:
void push (int data, struct node ** s) and
int pop (struct node ** s)  */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the stack node
struct node {
  int data;
  struct node *next;
};

// Function to push an element onto the stack
void push(int data, struct node **s) {
  // Create a new node
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  // Assign the data to the new node
  new_node->data = data;

  // Link the new node to the previous top of the stack
  new_node->next = *s;

  // Update the top of the stack to the new node
  *s = new_node;
  printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct node **s) {
  if (*s == NULL) {
    // Stack is empty
    printf("Stack is empty, cannot pop.\n");
    return -1; // Return a sentinel value to indicate stack is empty
  }

  // Store the data of the top node
  int popped_data = (*s)->data;

  // Temporarily store the current top node
  struct node *temp = *s;

  // Move the top of the stack to the next node
  *s = (*s)->next;

  // Free the memory of the popped node
  free(temp);

  printf("Popped %d from the stack.\n", popped_data);

  return popped_data;
}

// Function to display the elements of the stack
void display(struct node *s) {
  if (s == NULL) {
    printf("Stack is empty.\n");
    return;
  }

  struct node *temp = s;
  printf("Stack contents: ");

  // Traverse the stack and print the elements
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct node *stack =
      NULL; // Initialize an empty stack (NULL represents an empty stack)

  // Push elements onto the stack
  push(10, &stack);
  push(20, &stack);
  push(30, &stack);

  // Display the stack
  display(stack);

  // Pop elements from the stack
  pop(&stack);
  pop(&stack);

  // Display the stack again
  display(stack);

  // Pop the last element
  pop(&stack);

  // Try to pop from an empty stack
  pop(&stack);

  return 0;
}

/* SAMPLE OUTPUT
Pushed 10 onto the stack.
Pushed 20 onto the stack.
Pushed 30 onto the stack.
Stack contents: 30 20 10
Popped 30 from the stack.
Popped 20 from the stack.
Stack contents: 10
Popped 10 from the stack.
Stack is empty, cannot pop.
*/