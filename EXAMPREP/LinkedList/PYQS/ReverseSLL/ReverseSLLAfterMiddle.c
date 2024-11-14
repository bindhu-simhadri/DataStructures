/* Write a user defined functions to perform the following:
 i) Create a singly linked list A with N nodes.
 ii) Reverse the singly linked list A after the (N/2) th node.

Ex: 1->2->3->4->5->6->7->8->9->10->NULL becomes
      1->2->3->4->5->10->9->8->7->6->NULL */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a singly linked list with N nodes
struct Node* createList(int N) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode;

    for (int i = 1; i <= N; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list from the (N/2 + 1)-th node to the end
struct Node* reverseAfterMid(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;

    // Find the middle point using the fast and slow pointers
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // `slow` is now at (N/2 + 1)-th node, which is where the reversal should start
    struct Node* curr = slow;
    struct Node* prevNode = NULL;
    struct Node* nextNode;

    // Reverse the list from the middle to the end
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    // Attach the first half to the reversed second half
    prev->next = prevNode;

    return head;
}

int main() {
    int N;

    printf("Enter the number of nodes (N): ");
    scanf("%d", &N);

    // Create list A
    struct Node* head = createList(N);
    printf("Original List A: ");
    printList(head);

    // Reverse list A after the middle node
    head = reverseAfterMid(head);
    printf("List A after reversing from the middle: ");
    printList(head);

    return 0;
}


/*SAMPLE OUTPUT 
Enter the number of nodes (N): 10
Original List A: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
List A after reversing from the middle: 1 -> 2 -> 3 -> 4 -> 5 -> 10 -> 9 -> 8 -> 7 -> 6 -> NULL
*/

