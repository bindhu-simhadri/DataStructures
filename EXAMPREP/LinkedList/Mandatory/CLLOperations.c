#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a circular linked list
struct node {
  int data;
  struct node *next;
};

// Initialize the start pointer to NULL (start of the circular linked list)
struct node *start = NULL;

// Function prototypes
struct node *create_cll(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);

int main() {
  int option;
  // Display menu options to the user
  do {
    printf("\n\n ***** MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Delete a node from the beginning");
    printf("\n 6: Delete a node from the end");
    printf("\n 7: Delete a node after a given node");
    printf("\n 8: Delete the entire list");
    printf("\n 9: Exit");
    printf("\n Enter your option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      start = create_cll(start);
      printf("\n Circular Linked list created.");
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
      start = delete_after(start);
      break;
    case 8:
      start = delete_list(start);
      printf("\n Circular Linked list deleted.");
      break;
    }

  } while (option != 9);
  return 0;
}

// Function to create a circular linked list
struct node *create_cll(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter -1 to end.");
  printf("\n Enter the data: ");
  scanf("%d", &num);
  while (num != -1) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (start == NULL) { // For the first node
      new_node->next = new_node;
      start = new_node;
    } else {
      ptr = start;
      while (ptr->next != start) // Traverse to the last node
        ptr = ptr->next;
      ptr->next = new_node;   // Link new node to the list
      new_node->next = start; // Point back to start for circularity
    }
    printf("\n Enter the data: ");
    scanf("%d", &num);
  }
  return start;
}

// Function to display the circular linked list
struct node *display(struct node *start) {
  struct node *ptr = start;
  if (start == NULL) {
    printf("\n List is empty.");
    return start;
  }
  printf("\n Circular Linked List: ");
  do {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  } while (ptr != start);
  return start;
}

// Function to insert a node at the beginning of the circular linked list
struct node *insert_beg(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while (ptr->next != start) // Traverse to the last node
    ptr = ptr->next;
  ptr->next = new_node;   // Link last node to new node
  new_node->next = start; // New node points to the start
  start = new_node;       // Update start to new node
  return start;
}

// Function to insert a node at the end of the circular linked list
struct node *insert_end(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while (ptr->next != start) // Traverse to the last node
    ptr = ptr->next;
  ptr->next = new_node;   // Link last node to new node
  new_node->next = start; // New node points back to start
  return start;
}

// Function to delete a node from the beginning of the circular linked list
struct node *delete_beg(struct node *start) {
  struct node *ptr = start;
  if (start == NULL)
    return start;
  while (ptr->next != start) // Traverse to the last node
    ptr = ptr->next;
  ptr->next = start->next; // Last node points to the second node
  free(start);             // Free the first node
  start = ptr->next;       // Update start to the second node
  return start;
}

// Function to delete a node from the end of the circular linked list
struct node *delete_end(struct node *start) {
  struct node *ptr = start, *preptr;
  if (start == NULL)
    return start;
  while (ptr->next != start) { // Traverse to the last node
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = start; // Second-last node points back to start
  free(ptr);            // Free the last node
  return start;
}

// Function to delete a node after a given node value in the circular linked
// list
struct node *delete_after(struct node *start) {
  struct node *ptr = start, *temp;
  int val;
  printf("\n Enter the value after which the node has to be deleted: ");
  scanf("%d", &val);
  while (ptr->data != val) // Traverse to the specified node
    ptr = ptr->next;
  temp = ptr->next;       // Node to be deleted
  ptr->next = temp->next; // Link current node to the next of temp
  free(temp);             // Free the deleted node
  return start;
}

// Function to delete the entire circular linked list
struct node *delete_list(struct node *start) {
  struct node *ptr = start;
  if (start == NULL)
    return start;
  while (ptr->next != start) // Delete nodes one by one
    start = delete_end(start);
  free(start);  // Free the last remaining node
  start = NULL; // Set start to NULL
  return start;
}

/***** OUTPUT *

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 1

  Enter -1 to end.
  Enter the data: 5
  Enter the data: 10
  Enter the data: 15
  Enter the data: -1
  Linked list created.

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 2

  Circular Linked List: 5	10	15

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 3

  Enter the data: 2

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 2

  Circular Linked List: 2	5	10	15

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 4

  Enter the data: 20

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 2

  Circular Linked List: 2	5	10	15	20

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
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
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 2

  Circular Linked List: 5	10	15	20

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 7

  Enter the value after which the node has to be deleted: 10

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 2

  Circular Linked List: 5	10	20

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 8

  Circular Linked list deleted.

  ***** MAIN MENU *****
  1: Create a list
  2: Display the list
  3: Add a node at the beginning
  4: Add a node at the end
  5: Delete a node from the beginning
  6: Delete a node from the end
  7: Delete a node after a given node
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
  7: Delete a node after a given node
  8: Delete the entire list
  9: Exit
  Enter your option: 9

  Process exited with status 0.

*/