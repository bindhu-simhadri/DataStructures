/* program to create a linked list and perform insertions and deletions of all
 * cases */

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct node {
  int data;
  struct node *next;
};

// Function prototypes
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

// Global pointer to the start of the list
struct node *start = NULL;

int main() {
  int option;
  do {
    printf("\n\n ***** MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Add a node before a given node");
    printf("\n 6: Add a node after a given node");
    printf("\n 7: Delete a node from the beginning");
    printf("\n 8: Delete a node from the end");
    printf("\n 9: Delete a given node");
    printf("\n 10: Delete a node after a given node");
    printf("\n 11: Delete the entire list");
    printf("\n 12: Sort the list");
    printf("\n 13: Exit");
    printf("\n\n Enter your option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      start = create_ll(start);
      printf("\n Linked list created.");
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
      start = delete_node(start);
      break;
    case 10:
      start = delete_after(start);
      break;
    case 11:
      start = delete_list(start);
      printf("\n Linked list deleted.");
      break;
    case 12:
      start = sort_list(start);
      printf("\n Linked list sorted.");
      break;
    case 13:
      printf("\n Exiting program.");
      break;
    default:
      printf("\n Invalid option. Please try again.");
      break;
    }
  } while (option != 13);

  return 0;
}

// Function to create a linked list by inserting nodes at the end
struct node *create_ll(struct node *start) {
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
      start = new_node;
    } else {
      ptr = start;
      while (ptr->next != NULL)
        ptr = ptr->next;
      ptr->next = new_node;
    }
    printf("\n Enter the data: ");
    scanf("%d", &num);
  }
  return start;
}

// Function to display the linked list
struct node *display(struct node *start) {
  struct node *ptr = start;
  printf("\n Linked list elements: ");
  while (ptr != NULL) {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  }
  return start;
}

// Function to insert a node at the beginning of the list
struct node *insert_beg(struct node *start) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  printf("\n Enter the data: ");
  scanf("%d", &new_node->data);
  new_node->next = start;
  start = new_node;
  return start;
}

// Function to insert a node at the end of the list
struct node *insert_end(struct node *start) {
  struct node *ptr = start;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  printf("\n Enter the data: ");
  scanf("%d", &new_node->data);
  new_node->next = NULL;
  if (start == NULL) {
    start = new_node;
  } else {
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = new_node;
  }
  return start;
}

// Function to insert a node before a given node value
struct node *insert_before(struct node *start) {
  struct node *new_node, *ptr, *preptr;
  int num, val;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  printf("\n Enter the value before which the data has to be inserted: ");
  scanf("%d", &val);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  if (ptr->data == val) {
    new_node->next = start;
    start = new_node;
  } else {
    while (ptr->data != val) {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
  }
  return start;
}

// Function to insert a node after a given node value
struct node *insert_after(struct node *start) {
  struct node *new_node, *ptr;
  int num, val;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  printf("\n Enter the value after which the data has to be inserted: ");
  scanf("%d", &val);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while (ptr->data != val) {
    ptr = ptr->next;
  }
  new_node->next = ptr->next;
  ptr->next = new_node;
  return start;
}

// Function to delete a node from the beginning
struct node *delete_beg(struct node *start) {
  struct node *ptr = start;
  if (start != NULL) {
    start = start->next;
    free(ptr);
  }
  return start;
}

// Function to delete a node from the end
struct node *delete_end(struct node *start) {
  struct node *ptr = start, *preptr;
  if (start == NULL)
    return start;
  if (start->next == NULL) {
    free(start);
    start = NULL;
    return start;
  }
  while (ptr->next != NULL) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = NULL;
  free(ptr);
  return start;
}

// Function to delete a specific node by value
struct node *delete_node(struct node *start) {
  struct node *ptr = start, *preptr;
  int val;
  printf("\n Enter the value of the node to be deleted: ");
  scanf("%d", &val);
  if (start == NULL)
    return start;
  if (ptr->data == val) {
    start = delete_beg(start);
  } else {
    while (ptr != NULL && ptr->data != val) {
      preptr = ptr;
      ptr = ptr->next;
    }
    if (ptr == NULL) {
      printf("\n Node not found.");
    } else {
      preptr->next = ptr->next;
      free(ptr);
    }
  }
  return start;
}

// Function to delete a node after a given value
struct node *delete_after(struct node *start) {
  struct node *ptr = start, *temp;
  int val;
  printf("\n Enter the value after which the node has to be deleted: ");
  scanf("%d", &val);
  while (ptr != NULL && ptr->data != val) {
    ptr = ptr->next;
  }
  if (ptr != NULL && ptr->next != NULL) {
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
  }
  return start;
}

// Function to delete the entire list
struct node *delete_list(struct node *start) {
  struct node *ptr;
  while (start != NULL) {
    ptr = start;
    printf("\n %d is deleted.", start->data);
    start = start->next;
    free(ptr);
  }
  return start;
}

// Function to sort the linked list in ascending order
struct node *sort_list(struct node *start) {
  struct node *ptr1, *ptr2;
  int temp;
  if (start == NULL)
    return start;
  for (ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next) {
    for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
      if (ptr1->data > ptr2->data) {
        temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
      }
    }
  }
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
9: Delete a given node
10: Delete a node after a given node
11: Delete the entire list
12: Sort the list
13: Exit

Enter your option: 1

Enter -1 to end.
Enter the data: 10
Enter the data: 20
Enter the data: 30
Enter the data: -1

Linked list created.

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 10    20    30

***** MAIN MENU *****
Enter your option: 3

Enter the data: 5

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 5    10    20    30

***** MAIN MENU *****
Enter your option: 4

Enter the data: 40

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 5    10    20    30    40

***** MAIN MENU *****
Enter your option: 5

Enter the data: 15
Enter the value before which the data has to be inserted: 20

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 5    10    15    20    30    40

***** MAIN MENU *****
Enter your option: 6

Enter the data: 25
Enter the value after which the data has to be inserted: 20

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 5    10    15    20    25    30    40

***** MAIN MENU *****
Enter your option: 7

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 10    15    20    25    30    40

***** MAIN MENU *****
Enter your option: 8

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 10    15    20    25    30

***** MAIN MENU *****
Enter your option: 9

Enter the value of the node to be deleted: 25

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 10    15    20    30

***** MAIN MENU *****
Enter your option: 12

***** MAIN MENU *****
Enter your option: 2

Linked list elements: 10    15    20    30

***** MAIN MENU *****
Enter your option: 11

10 is deleted.
15 is deleted.
20 is deleted.
30 is deleted.

Linked list deleted.

***** MAIN MENU *****
Enter your option: 13

Exiting program.

*/
