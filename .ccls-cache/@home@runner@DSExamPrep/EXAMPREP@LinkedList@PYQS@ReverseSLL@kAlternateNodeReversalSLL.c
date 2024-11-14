/* Write a complete C program consisting of a function kAltReverse(. . .) to
 * reverse every alternate k nodes in a singly linked list, where k is read from
 * the keyboard. Include functions to insert the nodes in the front of the list
 * and also to display the nodes in the list. */

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the singly linked list
struct Node {
  int data;
  struct Node *next;
};

// Function to insert a node at the front of the list
void insertFront(struct Node **head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
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

// Function to reverse every alternate k nodes in the list
struct Node *kAltReverse(struct Node *head, int k) {
  if (head == NULL || k <= 1) {
    return head;
  }

  struct Node *current = head;
  struct Node *prevTail = NULL;
  struct Node *newHead = NULL;

  while (current != NULL) {
    struct Node *tail = current;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    // Reverse the first k nodes
    int count = 0;
    while (current != NULL && count < k) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
      count++;
    }

    // Set new head if it's the first group of k nodes
    if (newHead == NULL) {
      newHead = prev;
    }

    // Link the reversed segment to the previous part of the list
    if (prevTail != NULL) {
      prevTail->next = prev;
    }

    // Skip the next k nodes (do not reverse them)
    count = 0;
    while (current != NULL && count < k - 1) {
      current = current->next;
      count++;
    }

    // Connect the last node of the non-reversed segment to the next reversed
    // segment
    prevTail = tail;
  }

  return newHead;
}

// Main function
int main() {
  struct Node *head = NULL;
  int n, data, k;

  // Input the number of nodes
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  // Insert nodes at the front
  printf("Enter the elements to insert in the list (one by one):\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &data);
    insertFront(&head, data);
  }

  // Display the original list
  printf("Original list: ");
  displayList(head);

  // Input value of k
  printf("Enter the value of k: ");
  scanf("%d", &k);

  // Reverse every alternate k nodes
  head = kAltReverse(head, k);

  // Display the modified list
  printf("Modified list after k alternate reverse: ");
  displayList(head);

  return 0;
}

/* SAMPLE OUTPUT
Enter the number of nodes: 10
Enter the elements to insert in the list (one by one):
1 2 3 4 5 6 7 8 9 10
Original list: 10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
Enter the value of k: 3
Modified list after k alternate reverse: 3 -> 2 -> 1 -> 7 -> 6 -> 5 -> 10 -> 9-> 8 -> 4 -> NULL
*/