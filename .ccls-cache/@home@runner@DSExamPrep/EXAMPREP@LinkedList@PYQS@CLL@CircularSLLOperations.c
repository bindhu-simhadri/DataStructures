/* Write user defined functions to perform the following operations on circular
singly linked list: i) Print repeated elements in the given list. ii) Right
shift the list A counter clockwise for a given value of k.

Ex: 10->20->30->40->50->60->NULL and k = 3, then
      40->50->60->10->20->30-NULL

(Do not use array, stacks or queues)
*/

#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for Circular Singly Linked List
struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to print the circular singly linked list
void printList(struct Node *head) {
  struct Node *temp = head;
  if (head != NULL) {
    do {
      printf("%d -> ", temp->data);
      temp = temp->next;
    } while (temp != head);
    printf("NULL\n");
  }
}

// Function to insert a node at the end of the circular singly linked list
struct Node *insertEnd(struct Node *head, int data) {
  struct Node *newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    head->next = head; // Point to itself
  } else {
    struct Node *temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }
  return head;
}

// Function to print repeated elements in the circular singly linked list
void printRepeated(struct Node *head) {
  struct Node *temp = head;
  struct Node *innerTemp;
  struct Node *check = NULL;
  int found = 0;

  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  do {
    found = 0;
    innerTemp = head;
    while (innerTemp != temp) {
      if (innerTemp->data == temp->data && innerTemp != check) {
        printf("Repeated Element: %d\n", temp->data);
        found = 1;
        check = temp; // Mark this node as checked
        break;
      }
      innerTemp = innerTemp->next;
    }
    temp = temp->next;
  } while (temp != head);
}

// Function to right shift the circular singly linked list counterclockwise by k
// positions
struct Node *rightShiftList(struct Node *head, int k) {
  if (head == NULL || k == 0)
    return head;

  struct Node *temp = head;
  int length = 1;

  // Calculate the length of the list
  while (temp->next != head) {
    length++;
    temp = temp->next;
  }

  // If k is greater than length, reduce it
  k = k % length;

  if (k == 0)
    return head; // No need to shift if k is a multiple of list length

  // Find the node at the (length - k)th position
  struct Node *current = head;
  for (int i = 1; i < length - k; i++) {
    current = current->next;
  }

  struct Node *newHead = current->next;
  current->next = head;

  // Set the new tail
  struct Node *tail = newHead;
  while (tail->next != head) {
    tail = tail->next;
  }
  tail->next = newHead;

  return newHead;
}

int main() {
  struct Node *head = NULL;

  // Create the circular linked list with some values
  head = insertEnd(head, 10);
  head = insertEnd(head, 20);
  head = insertEnd(head, 30);
  head = insertEnd(head, 40);
  head = insertEnd(head, 50);
  head = insertEnd(head, 60);

  printf("Original Circular Linked List: \n");
  printList(head);

  // Print repeated elements in the list
  printf("\nRepeated Elements in the List: \n");
  printRepeated(head);

  // Right shift the list counterclockwise by k positions
  int k = 3;
  head = rightShiftList(head, k);

  printf("\nCircular Linked List after right shifting by %d positions:\n", k);
  printList(head);

  return 0;
}

/*SAMPLE OUTPUT
Original Circular Linked List:
10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

Repeated Elements in the List:
(No repeated elements in this list)

Circular Linked List after right shifting by 3 positions:
40 -> 50 -> 60 -> 10 -> 20 -> 30 -> NULL
*/