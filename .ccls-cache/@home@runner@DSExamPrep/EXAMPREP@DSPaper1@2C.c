/* 2C. Consider the following structure definition of a doubly linked list. Each node of the list consists of a character. Collection of all the nodes represents a word.

struct Node
{
char data;
struct Node *next; struct Node *prev; 
};
struct Node *start = NULL;

Write a function palindrome which checks whether the word formed for the doubly linked list represents a palindrome or not. The function is passed with address of leftmost node in the list. Also write the function to display the word represented by the list.*/

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
};

// Global start pointer for the doubly linked list
struct Node *start = NULL;

// Function to create a new node
struct Node *createNode(char data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a character to the doubly linked list
void appendNode(char data) {
    struct Node *newNode = createNode(data);
    if (start == NULL) {
        start = newNode;
    } else {
        struct Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display the word represented by the doubly linked list
void displayWord() {
    struct Node *temp = start;
    printf("Word: ");
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the word in the doubly linked list is a palindrome
int palindrome(struct Node *left) {
    if (left == NULL) {
        return 1; // Empty list is a palindrome
    }

    // Find the rightmost node
    struct Node *right = left;
    while (right->next != NULL) {
        right = right->next;
    }

    // Check characters from both ends
    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            return 0; // Not a palindrome
        }
        left = left->next;
        right = right->prev;
    }
    return 1; // Palindrome
}

// Main function
int main() {
    char word[] = "radar"; // Example word to check
    int i;

    // Build the doubly linked list from the word
    for (i = 0; word[i] != '\0'; i++) {
        appendNode(word[i]);
    }

    // Display the word
    displayWord();

    // Check if the word is a palindrome
    if (palindrome(start)) {
        printf("The word is a palindrome.\n");
    } else {
        printf("The word is not a palindrome.\n");
    }

    return 0;
}

/* SAMPLE OUTPUT
INPUT:
char word[] = "radar";
OUTPUT: 
Word: radar
The word is a palindrome.


INPUT:
char word[] = "hello";
OUTPUT:
Word: hello
The word is not a palindrome.
*/