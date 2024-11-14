/* Given a pointer to the first node of a doubly linked list. Write a function
 * to display the number of nodes in the list and also free all the nodes of the
 * linked list.*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

// Function to display the number of nodes and free all nodes of the doubly
// linked list
void countAndFree(struct Node *head) {
  struct Node *temp = head;
  int count = 0;

  // Traverse the list and count the nodes
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  // Print the number of nodes
  printf("Number of nodes in the list: %d\n", count);

  // Free the nodes
  temp = head;
  while (temp != NULL) {
    struct Node *nextNode = temp->next;
    free(temp);      // Free the current node
    temp = nextNode; // Move to the next node
  }

  // Set the head to NULL (list is now empty)
  head = NULL;
}

int main() {
  // Create a simple doubly linked list
  struct Node *head = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;

  // Allocate memory for nodes
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  // Initialize data and link the nodes
  head->data = 10;
  head->next = second;
  head->prev = NULL;

  second->data = 20;
  second->next = third;
  second->prev = head;

  third->data = 30;
  third->next = NULL;
  third->prev = second;

  // Call the function to display the number of nodes and free all nodes
  countAndFree(head);

  return 0;
}

/* SAMPLE OUTPUT
Number of nodes in the list: 3
*/