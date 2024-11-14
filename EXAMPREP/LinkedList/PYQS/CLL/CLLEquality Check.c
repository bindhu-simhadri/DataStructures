/* Write a recursive function EQUALITY which takes the addresses of the header
node of two circular singly linked list as its parameter. This function checks
if the individual elements of the two linked list are equal and returns its
status. Linked list can be of any size.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
  int data;
  struct Node *next;
};

// Function to create a circular singly linked list
struct Node *createCircularList(int n) {
  struct Node *head = NULL, *temp = NULL, *newNode = NULL;
  int data, i;

  for (i = 0; i < n; i++) {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &data);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      temp->next = newNode;
    }
    temp = newNode;
  }

  // Making the list circular by connecting the last node to the head
  if (temp != NULL) {
    temp->next = head;
  }

  return head;
}

// Recursive function to check equality of two circular singly linked lists
int EQUALITY(struct Node *head1, struct Node *head2) {
  // Base case: If both heads are NULL (empty lists), they are considered equal
  if (head1 == NULL && head2 == NULL) {
    return 1;
  }

  // If one list is NULL and the other is not, they are not equal
  if (head1 == NULL || head2 == NULL) {
    return 0;
  }

  // If the data in the current nodes do not match, return 0
  if (head1->data != head2->data) {
    return 0;
  }

  // Move to the next nodes in both lists (circular list condition)
  // We need to stop when we've returned to the head node
  if (head1->next == head1 || head2->next == head2) {
    return 1; // Both lists have completed a full cycle and match
  }

  return EQUALITY(head1->next, head2->next);
}

// Function to display a circular singly linked list
void displayList(struct Node *head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = head;
  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != head); // Loop until we reach the header node again

  printf("(head)\n");
}

int main() {
  int n1, n2;

  // Input for first list
  printf("Enter number of nodes for the first list: ");
  scanf("%d", &n1);
  struct Node *head1 = createCircularList(n1);
  printf("First Circular List: ");
  displayList(head1);

  // Input for second list
  printf("Enter number of nodes for the second list: ");
  scanf("%d", &n2);
  struct Node *head2 = createCircularList(n2);
  printf("Second Circular List: ");
  displayList(head2);

  // Check if both circular singly linked lists are equal
  if (EQUALITY(head1, head2)) {
    printf("Both circular singly linked lists are equal.\n");
  } else {
    printf("Both circular singly linked lists are not equal.\n");
  }

  return 0;
}

/* SAMPLE OUTPUT
Enter number of nodes for the first list: 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
First Circular List: 10 -> 20 -> 30 -> (head)

Enter number of nodes for the second list: 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Second Circular List: 10 -> 20 -> 30 -> (head)

Both circular singly linked lists are equal.
*/