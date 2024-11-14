/* Construct a C program, to delete the last element in a Doubly Linked List*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the doubly linked list node
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

// Function to delete the last element of the doubly linked list
void deleteLast(struct Node **head) {
  if (*head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  // If there is only one node in the list
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    printf("The last node has been deleted.\n");
    return;
  }

  // Traverse to the last node
  struct Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  // Unlink the last node and free it
  temp->prev->next = NULL;
  free(temp);
  printf("The last node has been deleted.\n");
}

// Function to display the doubly linked list
void display(struct Node *head) {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  struct Node *temp = head;
  printf("The doubly linked list is: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to insert a new node at the beginning
void insertFront(struct Node **head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = *head;

  if (*head != NULL) {
    (*head)->prev = newNode;
  }

  *head = newNode;
}

// Main function to test the above functionality
int main() {
  struct Node *head = NULL;

  // Insert nodes
  insertFront(&head, 10);
  insertFront(&head, 20);
  insertFront(&head, 30);
  insertFront(&head, 40);
  insertFront(&head, 50);

  // Display the list
  display(head);

  // Delete the last element
  deleteLast(&head);

  // Display the list again
  display(head);

  return 0;
}

/* SAMPLE OUTPUT
The doubly linked list is: 50 40 30 20 10
The last node has been deleted.
The doubly linked list is: 50 40 30 20
*/