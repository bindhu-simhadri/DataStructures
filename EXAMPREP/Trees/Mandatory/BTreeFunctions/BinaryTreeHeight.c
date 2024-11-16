/* C Program to Find Height of Binary Tree: */

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

// Function to find the height of the binary tree
int findHeight(struct Node* root) {
    // If the tree is empty, return -1
    if (root == NULL) {
        return -1;
    }

    // Recursively find the height of the left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // The height of the tree is the maximum of the left and right subtree heights plus 1
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

// Main function
int main() {
    // Creating the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    // Finding and printing the height of the binary tree
    int height = findHeight(root);
    printf("The height of the binary tree is: %d\n", height);

    return 0;
}

/* SAMPLE OUTPUT
For the binary tree:
          1
        /   \
       2     3
      / \   /
     4   5 6
The output will be:
The height of the binary tree is: 2

*/