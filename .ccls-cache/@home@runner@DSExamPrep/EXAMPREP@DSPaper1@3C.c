/* 3C. Write a function to insert an item at the end of Circular Singly Linked List with header node. Use the (2) following function prototype:
Nodeptr InsertLast (Nodeptr head, int x); where head represents the header node and x is the item to be inserted.*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Nodeptr;

// Function to create a new node
Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an item at the end of a circular singly linked list
Nodeptr InsertLast(Nodeptr head, int x) {
    if (head == NULL) {
        printf("Header node is NULL.\n");
        return NULL;
    }

    Nodeptr newNode = createNode(x);
    if (head->next == head) {
        // List is empty (only header node exists)
        head->next = newNode;
        newNode->next = head;
    } else {
        // Traverse to the last node
        Nodeptr temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        // Insert new node at the end
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

// Function to display the circular singly linked list
void displayList(Nodeptr head) {
    if (head == NULL || head->next == head) {
        printf("List is empty.\n");
        return;
    }

    Nodeptr temp = head->next; // Skip the header node
    printf("Circular List: ");
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("HEAD\n");
}

// Main function to test InsertLast
int main() {
    // Create a header node
    Nodeptr head = createNode(0); // Header node's data is not used
    head->next = head; // Points to itself initially

    // Insert elements
    head = InsertLast(head, 10);
    head = InsertLast(head, 20);
    head = InsertLast(head, 30);

    // Display the list
    displayList(head);

    return 0;
}

/* SAMPLE OUTPUT

INPUT:
head = InsertLast(head, 10);
head = InsertLast(head, 20);
head = InsertLast(head, 30);

OUTPUT:
Circular List: 10 -> 20 -> 30 -> HEAD

*/

