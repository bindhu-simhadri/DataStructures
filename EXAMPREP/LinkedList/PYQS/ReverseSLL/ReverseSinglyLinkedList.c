/* Write a C function to invert a singly linked list. The function should accept
 * a pointer to	the given list and return a pointer to the inverted list.*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a singly linked list
struct Node {
  int data;
  struct Node *next;
};

// Function to invert (reverse) the linked list
struct Node *invertList(struct Node *head) {
  struct Node *prev = NULL;
  struct Node *current = head;
  struct Node *next = NULL;

  // Traverse the list and reverse the pointers
  while (current != NULL) {
    next = current->next; // Store the next node
    current->next = prev; // Reverse the current node's pointer
    prev = current;       // Move prev to this node
    current = next;       // Move to the next node
  }
  head = prev; // Update head to the new first node
  return head;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int newData) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

// Function to display the list
void displayList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
  struct Node *head = NULL;

  // Inserting elements into the list
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);
  insertAtBeginning(&head, 40);

  printf("Original List:\n");
  displayList(head);

  // Inverting the list
  head = invertList(head);

  printf("\nInverted List:\n");
  displayList(head);

  return 0;
}

/*SAMPLE OUTPUT
Original List:
40 -> 30 -> 20 -> 10 -> NULL

Inverted List:
10 -> 20 -> 30 -> 40 -> NULL
*/