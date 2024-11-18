/* 3A) Write a function to find the largest number node in a binary tree (ii) Find the height of the given tree and show the left child-right sibling representation of the following tree. (C Program) 

          A
       /  |  \
      B   C   D
    /  \  |  / | \
   E    F G  H I  J
  /  \         |
 K    L        M
*/

//Code for Finding Largest Number Node
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the largest number node in the binary tree
int findLargest(struct Node *root) {
    if (root == NULL) {
        return INT_MIN; // Return a very small value if the tree is empty
    }

    int leftLargest = findLargest(root->left);
    int rightLargest = findLargest(root->right);

    // Return the maximum of the current node, leftLargest, and rightLargest
    return (root->data > leftLargest ? (root->data > rightLargest ? root->data : rightLargest) : (leftLargest > rightLargest ? leftLargest : rightLargest));
}






