/* write a program to create a doubly linked list and perform the following
   operations: insertion and deletion at the beginning and end of the list */
#include <stdio.h>
#include <stdlib.h>

// Definition of a doubly linked list node
struct node {
  struct node *prev;
  int data;
  struct node *next;
};

struct node *start = NULL; // Start pointer for the doubly linked list

// Function prototypes
struct node *create_dll(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_before(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);

int main() {
  int option;
  do {
    printf("\n ***** MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Add a node before a given node");
    printf("\n 6: Add a node after a given node");
    printf("\n 7: Delete a node from the beginning");
    printf("\n 8: Delete a node from the end");
    printf("\n 9: Delete a node before a given node");
    printf("\n 10: Delete a node after a given node");
    printf("\n 11: Delete the entire list");
    printf("\n 12: Exit");
    printf("\n Enter your option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      start = create_dll(start);
      printf("\n Doubly Linked list created.");
      break;
    case 2:
      display(start);
      break;
    case 3:
      start = insert_beg(start);
      break;
    case 4:
      start = insert_end(start);
      break;
    case 5:
      start = insert_before(start);
      break;
    case 6:
      start = insert_after(start);
      break;
    case 7:
      start = delete_beg(start);
      break;
    case 8:
      start = delete_end(start);
      break;
    case 9:
      start = delete_before(start);
      break;
    case 10:
      start = delete_after(start);
      break;
    case 11:
      start = delete_list(start);
      printf("\n Doubly Linked list deleted.");
      break;
    }
  } while (option != 12);

  return 0;
}

// Function to create a doubly linked list
struct node *create_dll(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter -1 to end.");
  printf("\n Enter the data: ");
  scanf("%d", &num);

  while (num != -1) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if (start == NULL) {
      new_node->prev = NULL;
      start = new_node;
    } else {
      ptr = start;
      while (ptr->next != NULL)
        ptr = ptr->next;
      ptr->next = new_node;
      new_node->prev = ptr;
    }
    printf("\n Enter the data: ");
    scanf("%d", &num);
  }
  return start;
}

// Function to display the doubly linked list
struct node *display(struct node *start) {
  struct node *ptr = start;
  while (ptr != NULL) {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  }
  return start;
}

// Function to insert a node at the beginning
struct node *insert_beg(struct node *start) {
  struct node *new_node;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  new_node->next = start;
  new_node->prev = NULL;

  if (start != NULL)
    start->prev = new_node;
  start = new_node;

  return start;
}

// Function to insert a node at the end
struct node *insert_end(struct node *start) {
  struct node *ptr, *new_node;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  new_node->next = NULL;

  if (start == NULL) {
    new_node->prev = NULL;
    start = new_node;
    return start;
  }

  ptr = start;
  while (ptr->next != NULL)
    ptr = ptr->next;
  ptr->next = new_node;
  new_node->prev = ptr;

  return start;
}

// Function to insert a node before a given node
struct node *insert_before(struct node *start) {
  struct node *new_node, *ptr;
  int num, val;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  printf("\n Enter the value before which the data has to be inserted: ");
  scanf("%d", &val);

  ptr = start;
  while (ptr != NULL && ptr->data != val)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\n Node with value %d not found.", val);
    return start;
  }

  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  new_node->next = ptr;
  new_node->prev = ptr->prev;

  if (ptr->prev != NULL)
    ptr->prev->next = new_node;
  else
    start = new_node;

  ptr->prev = new_node;

  return start;
}

// Function to insert a node after a given node
struct node *insert_after(struct node *start) {
  struct node *new_node, *ptr;
  int num, val;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  printf("\n Enter the value after which the data has to be inserted: ");
  scanf("%d", &val);

  ptr = start;
  while (ptr != NULL && ptr->data != val)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("\n Node with value %d not found.", val);
    return start;
  }

  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  new_node->next = ptr->next;
  new_node->prev = ptr;

  if (ptr->next != NULL)
    ptr->next->prev = new_node;
  ptr->next = new_node;

  return start;
}

// Function to delete a node from the beginning
struct node *delete_beg(struct node *start) {
  struct node *ptr = start;
  if (start == NULL)
    return start;

  start = start->next;
  if (start != NULL)
    start->prev = NULL;

  free(ptr);
  return start;
}

// Function to delete a node from the end
struct node *delete_end(struct node *start) {
  struct node *ptr = start;
  if (start == NULL)
    return start;

  while (ptr->next != NULL)
    ptr = ptr->next;

  if (ptr->prev != NULL)
    ptr->prev->next = NULL;
  else
    start = NULL;

  free(ptr);
  return start;
}

// Function to delete a node before a given node
struct node *delete_before(struct node *start) {
  struct node *ptr, *temp;
  int val;
  printf("\n Enter the value before which the node has to be deleted: ");
  scanf("%d", &val);

  ptr = start;
  while (ptr != NULL && ptr->data != val)
    ptr = ptr->next;

  if (ptr == NULL || ptr->prev == NULL) {
    printf("\n Deletion not possible.");
    return start;
  }

  temp = ptr->prev;
  if (temp->prev != NULL)
    temp->prev->next = ptr;
  else
    start = ptr;

  ptr->prev = temp->prev;
  free(temp);

  return start;
}

// Function to delete a node after a given node
struct node *delete_after(struct node *start) {
  struct node *ptr, *temp;
  int val;
  printf("\n Enter the value after which the node has to be deleted: ");
  scanf("%d", &val);

  ptr = start;
  while (ptr != NULL && ptr->data != val)
    ptr = ptr->next;

  if (ptr == NULL || ptr->next == NULL) {
    printf("\n Deletion not possible.");
    return start;
  }

  temp = ptr->next;
  ptr->next = temp->next;
  if (temp->next != NULL)
    temp->next->prev = ptr;

  free(temp);

  return start;
}

// Function to delete the entire list
struct node *delete_list(struct node *start) {
  while (start != NULL)
    start = delete_beg(start);
  return start;
}

/* SAMPLE OUTPUT
     ***** MAIN MENU *****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a node before a given node
10: Delete a node after a given node
11: Delete the entire list
12: Exit
Enter your option: 1

Enter -1 to end.
Enter the data: 10
Enter the data: 20
Enter the data: 30
Enter the data: -1
Doubly Linked list created.

***** MAIN MENU *****
Enter your option: 2
10    20    30

***** MAIN MENU *****
Enter your option: 3
Enter the data: 5
List after insertion at the beginning:
5    10    20    30

***** MAIN MENU *****
Enter your option: 4
Enter the data: 40
List after insertion at the end:
5    10    20    30    40

***** MAIN MENU *****
Enter your option: 5
Enter the data: 15
Enter the value before which the data has to be inserted: 20
List after insertion before 20:
5    10    15    20    30    40

***** MAIN MENU *****
Enter your option: 6
Enter the data: 35
Enter the value after which the data has to be inserted: 30
List after insertion after 30:
5    10    15    20    30    35    40

***** MAIN MENU *****
Enter your option: 7
List after deletion at the beginning:
10    15    20    30    35    40

***** MAIN MENU *****
Enter your option: 8
List after deletion at the end:
10    15    20    30    35

***** MAIN MENU *****
Enter your option: 9
Enter the value before which the node has to be deleted: 20
List after deletion before 20:
10    20    30    35

***** MAIN MENU *****
Enter your option: 10
Enter the value after which the node has to be deleted: 30
List after deletion after 30:
10    20    30

***** MAIN MENU *****
Enter your option: 11
Doubly Linked list deleted.

***** MAIN MENU *****
Enter your option: 2
List is empty.

***** MAIN MENU *****
Enter your option: 12
Exiting the program.

*/
