/* C Code Example for Linked List Representation of Binary Tree */

#include <stdio.h>
#include <stdlib.h>

// Tree Node Structure
struct Node {
    int data;           // Data of the node
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);    // Print root data
        preorder(root->left);         // Traverse left subtree
        preorder(root->right);        // Traverse right subtree
    }
}

int main() {
    // Constructing the tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    // Print preorder traversal of the binary tree
    printf("Preorder Traversal: ");
    preorder(root);

    return 0;
}

/* SAMPLE OUTPUT 
Preorder Traversal: 1 2 4 5 3 6
*/
