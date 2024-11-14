/*Write a function to insert an item at the end of Circular Singly Linked List
with header node. Use the (2) following function prototype:

Nodeptr InsertLast (Nodeptr head, int x); where head represents the header node
and x is the item to be inserted.  */

#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a circular singly linked list with a header node
struct Node {
  int data;
  struct Node *next;
};

typedef struct Node *Nodeptr;

// Function to insert an item at the end of the circular singly linked list
Nodeptr InsertLast(Nodeptr head, int x) {
  // Create a new node to hold the data
  Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->next =
      head; // New node should point to head, maintaining the circular nature

  // If the list is empty (head is the only node)
  if (head->next == head) {
    head->next = newNode; // Point head's next to the new node
  } else {
    // Traverse to the last node (node pointing back to head)
    Nodeptr temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    // Insert the new node at the end and make it circular
    temp->next = newNode;
  }
  return head;
}

// Helper function to display the circular singly linked list
void DisplayList(Nodeptr head) {
  Nodeptr temp = head->next; // Start from the first element
  if (temp == head) {
    printf("List is empty.\n");
    return;
  }
  while (temp != head) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("HEAD\n"); // Indicate the circular link back to head
}

// Main function to test InsertLast
int main() {
  // Initialize the header node
  Nodeptr head = (Nodeptr)malloc(sizeof(struct Node));
  head->next = head; // Circular reference to itself initially (empty list)

  // Insert elements at the end of the list
  head = InsertLast(head, 10);
  head = InsertLast(head, 20);
  head = InsertLast(head, 30);

  // Display the list
  printf("Circular Singly Linked List with Header Node:\n");
  DisplayList(head);

  return 0;
}

/*SAMPLE OUTPUT
Circular Singly Linked List with Header Node:
10 -> 20 -> 30 -> HEAD
*/