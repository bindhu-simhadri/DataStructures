/* C Program to Implement Search in Binary Tree*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;           // Data of the node
    struct Node* left;  // Pointer to the left child
    struct Node* right; // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to search for a value in the binary tree
struct Node* search(struct Node* root, int key) {
    // Base case: If the tree is empty or the node is found
    if (root == NULL || root->data == key)
        return root;

    // Recur for the left subtree
    struct Node* leftSearch = search(root->left, key);
    if (leftSearch != NULL) {
        return leftSearch;
    }

    // Recur for the right subtree
    return search(root->right, key);
}

// Function to print the search result
void printSearchResult(struct Node* result) {
    if (result != NULL) {
        printf("Node found with value: %d\n", result->data);
    } else {
        printf("Node not found.\n");
    }
}

// Main function
int main() {
    // Creating nodes of the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    // Searching for a value in the binary tree
    int key = 5;  // You can change this to test other values
    struct Node* result = search(root, key);

    // Printing the result of the search
    printSearchResult(result);

    return 0;
}


/* SAMPLE OUTPUT

For this program, the tree created is:
        1
       / \
      2   3
     / \    \
    4   5    6

If you search for the key 5, the output will be:
Node found with value: 5

If you search for a non-existent node (e.g., 7), the output will be:
Node not found.

*/