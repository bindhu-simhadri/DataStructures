/* Write a program to create a circular doubly linked list.
  Perform insertion and deletion at the beginning and end of the list */

#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int data;
  struct node *prev;
};

struct node *start = NULL;
struct node create_cdll(struct node *);
struct node display(struct node *);
struct node insert_beg(struct node *);
struct node insert_end(struct node *);
struct node delete_beg(struct node *);
struct node delete_end(struct node *);
struct node delete_node(struct node *);
struct node delete_list(struct node *);

int main() {
  int option;
  do {
    printf("\n ***** MAIN MENU *****");
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
      start = create_cdll(start);
      printf("\n circulat doubly linked list created.");
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
      printf("\n circulat doubly linked list deleted.");
      break;
    }
  } while (option != 9);
  return 0;
}

//Func to create cdll
struct node *create_cdll(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter -1 to end.");
  printf("\n Enter the data: ");
  scanf("%d", &num);
  while (num != -1)
    {
      if(start == NULL)
      {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->prev = NULL;
        new_node->data = num;
        new_node->next = start;
        start = new_node;
      }
      else
      {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        ptr = start;
        while(ptr->next != start)
          ptr = ptr->next;
        new_node->prev = ptr;
        ptr->next = new_node;
        new_node->next = start;
        start->prev = new_node;
      }
      printf("\n Enter the data: ");
      scanf("%d", &num);
    }
  return start;
}

//Func to display cdll
struct node *display(struct node *start)
{
  struct node *ptr;
  ptr = start;
  while(ptr->next != start)
    {
      printf("%d\t", ptr->data);
      ptr = ptr->next;
    }
  printf("%d\t", ptr->data);
  return start;
}

//Func to insert at beg
struct node *insert_beg(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while(ptr->next != start)
    ptr = ptr->next;
  new_node->prev = ptr;
  ptr->next = new_node;
  new_node->next = start;
  start->prev = new_node;
  start = new_node;
  return start;
}

//Func to insert at end
struct node *insert_end(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while(ptr->next != start)
    ptr = ptr->next;
  ptr->next = new_node;
  new_node->prev = ptr;
  new_node->next = start;
  start->prev = new_node;
  return start;
}

//Func to delete at beg
struct node *delete_beg(struct node *start)
{
  struct node *ptr;
  ptr = start;
  while(ptr->next != start)
    ptr = ptr->next;
  ptr->next = start->next;
  temp = start;
  start = start->next;
  start->prev = ptr;
  free(temp);
  return start;
}

//Func to delete at end
struct node *delete_end(struct node *start)
{
  struct node *ptr;
  ptr = start;
  while(ptr->next != start)
    ptr = ptr->next;
  ptr->prev->next = start;
  start->prev = ptr->prev;
  free(ptr);
  return start;
}

//Func to delete a node
struct node *delete_node(struct node *start)
{
  struct node *ptr;
  int val;
  printf("\n Enter the value of the node to be deleted: ");
  scanf("%d", &val);
  ptr = start;
  if(ptr->data == val)
  {
    start = delete_beg(start);
    return start;
  }
  else
  {
    while(ptr->data != start)
      ptr = ptr->next;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return start;
      
  }
  
}

//Func to delete cdll
struct node *delete_list(struct node *start)
{
  struct node *ptr;
  ptr = start;
  while(ptr->next != start)
    start = delete_end(start);
  free(start);
  return start;
}
