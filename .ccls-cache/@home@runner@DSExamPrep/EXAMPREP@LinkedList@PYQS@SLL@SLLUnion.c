/*Write function “struct node* findunion (struct node *LLOne, struct node
 * *LLTwo)” which returns the union of two lists represented using singly linked
 * list. */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
struct node {
  int data;
  struct node *next;
};

// Function to create a new node with a given value
struct node *createNode(int value) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct node **head, int value) {
  struct node *newNode = createNode(value);
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// Function to print the linked list
void printList(struct node *head) {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Function to check if a value is present in the list
int isPresent(struct node *head, int value) {
  struct node *temp = head;
  while (temp != NULL) {
    if (temp->data == value) {
      return 1; // Value is present
    }
    temp = temp->next;
  }
  return 0; // Value not found
}

// Function to find the union of two singly linked lists
struct node *findUnion(struct node *LLOne, struct node *LLTwo) {
  struct node *result = NULL;

  // Traverse the first list and add each element to the result list if not
  // already present
  struct node *temp = LLOne;
  while (temp != NULL) {
    if (!isPresent(result, temp->data)) {
      insertEnd(&result, temp->data);
    }
    temp = temp->next;
  }

  // Traverse the second list and add each element to the result list if not
  // already present
  temp = LLTwo;
  while (temp != NULL) {
    if (!isPresent(result, temp->data)) {
      insertEnd(&result, temp->data);
    }
    temp = temp->next;
  }

  return result;
}

int main() {
  struct node *LLOne = NULL;
  struct node *LLTwo = NULL;

  // Inserting elements in the first linked list
  insertEnd(&LLOne, 1);
  insertEnd(&LLOne, 3);
  insertEnd(&LLOne, 5);
  insertEnd(&LLOne, 7);

  // Inserting elements in the second linked list
  insertEnd(&LLTwo, 2);
  insertEnd(&LLTwo, 3);
  insertEnd(&LLTwo, 6);
  insertEnd(&LLTwo, 7);

  // Printing the two lists
  printf("List One: ");
  printList(LLOne);
  printf("List Two: ");
  printList(LLTwo);

  // Finding the union of the two lists
  struct node *unionList = findUnion(LLOne, LLTwo);

  // Printing the union of the lists
  printf("Union of the two lists: ");
  printList(unionList);

  return 0;
}

/*SAMPLE OUTPUT
List One: 1 -> 3 -> 5 -> 7 -> NULL
List Two: 2 -> 3 -> 6 -> 7 -> NULL
Union of the two lists: 1 -> 3 -> 5 -> 7 -> 2 -> 6 -> NULL
*/