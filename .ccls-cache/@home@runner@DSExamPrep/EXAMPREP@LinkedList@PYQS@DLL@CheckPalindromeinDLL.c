/*Consider the following structure definition of a doubly linked list. Each node of the list consists of a character. Collection of all the nodes represents a word.       [3]					
		 	 	 		
struct Node
 {
 char data;
 struct Node *next; struct Node *prev; 
 };
						
struct Node *start = NULL;
						
Write a function palindrome which checks whether the word formed for the doubly linked list represents a palindrome or not. The function is passed with address of leftmost node in the list. Also write the function to display the word represented by the list. 
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly linked list
struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
};

// Function prototypes
void display(struct Node *start);
int palindrome(struct Node *start);
struct Node* insert_end(struct Node *start, char data);

int main() {
    struct Node *start = NULL;
    char str[] = "madam";  // You can change this string to test with different words
    int i;

    // Create the doubly linked list from the input string
    for (i = 0; str[i] != '\0'; i++) {
        start = insert_end(start, str[i]);
    }

    // Display the word represented by the list
    printf("Word represented by the list: ");
    display(start);

    // Check if the word is a palindrome
    if (palindrome(start)) {
        printf("The word is a palindrome.\n");
    } else {
        printf("The word is not a palindrome.\n");
    }

    return 0;
}

// Function to insert a new node at the end of the list
struct Node* insert_end(struct Node *start, char data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (start == NULL) {
        new_node->prev = NULL;
        start = new_node;
    } else {
        struct Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return start;
}

// Function to display the word represented by the doubly linked list
void display(struct Node *start) {
    struct Node *temp = start;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the word represented by the list is a palindrome
int palindrome(struct Node *start) {
    if (start == NULL) {
        return 1; // An empty list is considered a palindrome
    }

    // Find the rightmost node (end of the list)
    struct Node *end = start;
    while (end->next != NULL) {
        end = end->next;
    }

    // Check characters from the beginning and end, moving towards the center
    struct Node *left = start;
    struct Node *right = end;
    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            return 0; // Not a palindrome if characters don't match
        }
        left = left->next;
        right = right->prev;
    }
    return 1; // The word is a palindrome
}


/*SAMPLE OUTPUT
Word represented by the list: madam
The word is a palindrome.

Word represented by the list: hello
The word is not a palindrome.

*/