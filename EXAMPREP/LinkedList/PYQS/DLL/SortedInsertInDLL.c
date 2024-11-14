/* Write a complete C program consisting of a function sortedInsert(. . .) to insert an integer into a sorted doubly linked list, such that after insertion the list remains sorted. Also include function to display the contents of the list.*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to display the contents of the doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert an integer into a sorted doubly linked list
void sortedInsert(struct Node** head_ref, int data) {
    // Create a new node to be inserted
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    // If the list is empty, insert the new node as the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // If the new node should be inserted at the beginning
    if ((*head_ref)->data >= data) {
        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
        return;
    }

    // Find the correct position to insert the new node
    struct Node* temp = *head_ref;
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    // Insert the new node after the found node
    new_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

int main() {
    struct Node* head = NULL;

    // Insert some elements into the sorted list
    sortedInsert(&head, 5);
    sortedInsert(&head, 3);
    sortedInsert(&head, 8);
    sortedInsert(&head, 1);
    sortedInsert(&head, 6);

    // Display the sorted doubly linked list
    display(head);

    return 0;
}


/* SAMPLE OUTPUT
List: 1 3 5 6 8 
*/