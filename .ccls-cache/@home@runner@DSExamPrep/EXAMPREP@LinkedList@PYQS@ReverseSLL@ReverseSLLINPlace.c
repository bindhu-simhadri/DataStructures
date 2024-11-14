/*Write a function to reverse a singly linked list without creating a new list
 * and returns the address of the beginning of the reversed list. Only the links
 * are to be changed   */

#include <stdio.h>
#include <stdlib.h>

// Definition of a singly linked list node
struct Node {
  int data;
  struct Node *next;
};

// Function to insert a node at the end of the list
void insertEnd(struct Node **head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *last = *head;
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }
  last->next = newNode;
}

// Function to reverse the singly linked list
struct Node *reverseList(struct Node *head) {
  struct Node *prev = NULL;
  struct Node *current = head;
  struct Node *next = NULL;

  while (current != NULL) {
    next = current->next; // Save next node
    current->next = prev; // Reverse current node's pointer
    prev = current;       // Move prev and current one step forward
    current = next;
  }

  head = prev; // New head is the last node (previously at the end)
  return head;
}

// Function to display the list
void display(struct Node *head) {
  struct Node *temp = head;
  if (temp == NULL) {
    printf("List is empty.\n");
    return;
  }
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Main function to test the reverse function
int main() {
  struct Node *head = NULL;

  // Inserting elements into the list
  insertEnd(&head, 10);
  insertEnd(&head, 20);
  insertEnd(&head, 30);
  insertEnd(&head, 40);
  insertEnd(&head, 50);

  printf("Original list:\n");
  display(head);

  // Reversing the list
  head = reverseList(head);

  printf("Reversed list:\n");
  display(head);

  return 0;
}

/*SAMPLE OUTPUT
Original list:
10 -> 20 -> 30 -> 40 -> 50 -> NULL
Reversed list:
50 -> 40 -> 30 -> 20 -> 10 -> NULL
*/