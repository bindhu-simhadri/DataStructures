/* Write a program to create a circular doubly linked list.
  Perform insertion and deletion at the beginning and end of the list */

#include <stdio.h>
#include <stdlib.h>

// Define a node in the circular doubly linked list
struct node {
  struct node *next;
  int data;
  struct node *prev;
};

struct node *start = NULL;

// Function prototypes
struct node *create_cdll(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_list(struct node *start);

int main() {
  int option;

  // Main menu for the program
  do {
    printf("\n ***** MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Delete a node from the beginning");
    printf("\n 6: Delete a node from the end");
    printf("\n 7: Delete a specific node");
    printf("\n 8: Delete the entire list");
    printf("\n 9: Exit");
    printf("\n Enter your option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      start = create_cdll(start);
      printf("\n Circular doubly linked list created.");
      break;
    case 2:
      start = display(start);
      break;
    case 3:
      start = insert_beg(start);
      break;
    case 4:
      start = insert_end(start);
      break;
    case 5:
      start = delete_beg(start);
      break;
    case 6:
      start = delete_end(start);
      break;
    case 7:
      start = delete_node(start);
      break;
    case 8:
      start = delete_list(start);
      printf("\n Circular doubly linked list deleted.");
      start = NULL; // Reset start to NULL after deletion
      break;
    }
  } while (option != 9);
  return 0;
}

// Function to create a circular doubly linked list
struct node *create_cdll(struct node *start) {
  struct node *new_node, *ptr;
  int num;

  printf("\n Enter -1 to end.");
  printf("\n Enter the data: ");
  scanf("%d", &num);

  while (num != -1) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    // If the list is empty, initialize it with the new node
    if (start == NULL) {
      new_node->next = new_node;
      new_node->prev = new_node;
      start = new_node;
    } else {
      ptr = start->prev; // Find last node in the list
      new_node->next = start;
      start->prev = new_node;
      new_node->prev = ptr;
      ptr->next = new_node;
    }
    printf("\n Enter the data: ");
    scanf("%d", &num);
  }
  return start;
}

// Function to display the circular doubly linked list
struct node *display(struct node *start) {
  struct node *ptr = start;

  if (start == NULL) {
    printf("\nList is empty.\n");
    return start;
  }

  printf("\nList elements: ");
  do {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  } while (ptr != start);

  return start;
}

// Function to insert a node at the beginning of the circular doubly linked list
struct node *insert_beg(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);

  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  if (start == NULL) { // If list is empty
    new_node->next = new_node;
    new_node->prev = new_node;
    start = new_node;
  } else {
    ptr = start->prev; // Last node
    new_node->next = start;
    new_node->prev = ptr;
    ptr->next = new_node;
    start->prev = new_node;
    start = new_node; // Update start to new beginning
  }
  return start;
}

// Function to insert a node at the end of the circular doubly linked list
struct node *insert_end(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);

  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  if (start == NULL) {
    new_node->next = new_node;
    new_node->prev = new_node;
    start = new_node;
  } else {
    ptr = start->prev; // Last node
    new_node->next = start;
    new_node->prev = ptr;
    ptr->next = new_node;
    start->prev = new_node;
  }
  return start;
}

// Function to delete a node from the beginning of the circular doubly linked
// list
struct node *delete_beg(struct node *start) {
  struct node *temp;

  if (start == NULL) {
    printf("\nList is empty.\n");
    return start;
  }

  temp = start;
  if (start->next == start) { // Only one node in the list
    free(start);
    start = NULL;
  } else {
    struct node *last = start->prev;
    start = start->next;
    start->prev = last;
    last->next = start;
    free(temp);
  }
  return start;
}

// Function to delete a node from the end of the circular doubly linked list
struct node *delete_end(struct node *start) {
  struct node *temp;

  if (start == NULL) {
    printf("\nList is empty.\n");
    return start;
  }

  temp = start->prev;  // Last node
  if (temp == start) { // Only one node in the list
    free(start);
    start = NULL;
  } else {
    struct node *second_last = temp->prev;
    second_last->next = start;
    start->prev = second_last;
    free(temp);
  }
  return start;
}

// Function to delete a specific node based on its value
struct node *delete_node(struct node *start) {
  struct node *ptr;
  int val;

  if (start == NULL) {
    printf("\nList is empty.\n");
    return start;
  }

  printf("\n Enter the value of the node to be deleted: ");
  scanf("%d", &val);
  ptr = start;

  // Traverse the list to find the node to delete
  do {
    if (ptr->data == val) {
      if (ptr == start) { // If node is the start node
        start = delete_beg(start);
      } else if (ptr->next == start) { // If node is the last node
        start = delete_end(start);
      } else { // Node is somewhere in between
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
      }
      return start;
    }
    ptr = ptr->next;
  } while (ptr != start);

  printf("\nNode with value %d not found.\n", val);
  return start;
}

// Function to delete the entire circular doubly linked list
struct node *delete_list(struct node *start) {
  while (start != NULL) {
    start = delete_beg(start);
  }
  return start;
}

/* SAMPLE OUTPUT
 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 1

 Enter -1 to end.
 Enter the data: 10
 Enter the data: 20
 Enter the data: 30
 Enter the data: -1
 Circular doubly linked list created.

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 2

List elements: 10    20    30

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 3

 Enter the data: 5

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 2

List elements: 5    10    20    30

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 5

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 2

List elements: 10    20    30

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 7

 Enter the value of the node to be deleted: 20

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 2

List elements: 10    30

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 8

 Circular doubly linked list deleted.

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 2

List is empty.

 ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a specific node
 8: Delete the entire list
 9: Exit
 Enter your option: 9
*/