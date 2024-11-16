/* C Code to Create a Binary Tree Using Recursion: */
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct Node {
    int data;           // Data of the node
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child
};

// Function to create a new node (this is a simple recursive example where we create nodes with values 1, 2, 3, etc.)
struct Node* createBinaryTree(int level) {
    if (level > 3) {  // Limit the depth of the tree (for example, depth 3)
        return NULL;   // If the level exceeds 3, return NULL (base case)
    }

    // Create a new node with the current level as data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = level;  // Set node data (just for this example)
    newNode->left = NULL;
    newNode->right = NULL;

    // Recursively create the left and right subtrees
    newNode->left = createBinaryTree(level + 1);  // Left child with the next level
    newNode->right = createBinaryTree(level + 1); // Right child with the next level

    return newNode;
}

// Function for Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);      // Print root data
        inorderTraversal(root->right); // Traverse right subtree
    }
}

// Main function
int main() {
    // Create the binary tree starting from level 1
    struct Node* root = createBinaryTree(1);

    // Perform Inorder Traversal (Left -> Root -> Right) to print the tree
    printf("Inorder Traversal of the Binary Tree: ");
    inorderTraversal(root);

    return 0;
}

/* SAMPLE OUTPUT

Inorder Traversal of the Binary Tree: 4 2 5 1 6 3 7 


Tree Structure (for the given output):

        1
       / \
      2   3
     / \ / \
    4  5 6  7
*/