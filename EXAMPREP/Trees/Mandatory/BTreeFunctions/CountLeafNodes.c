/*C Program to Count Leaf Nodes in a Binary Tree: */

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

// Function to count the number of leaf nodes
int countLeafNodes(struct Node* root) {
    // Base case: if the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }

    // If the node is a leaf node (no children), return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recursively count the leaf nodes in both the left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
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

    // Counting the number of leaf nodes
    int leafCount = countLeafNodes(root);
    printf("The number of leaf nodes in the binary tree is: %d\n", leafCount);

    return 0;
}

/* Sample Output
For the binary tree:
      1
    /   \
   2     3
  / \   /
 4   5 6

The output will be:

The output will be:
The number of leaf nodes in the binary tree is: 3


*/