/* C Program to Copy a Binary Tree:*/

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

// Function to copy a binary tree
struct Node* copyTree(struct Node* root) {
    // Base case: If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // Create a new node with the same data as the current node
    struct Node* newNode = createNode(root->data);

    // Recursively copy the left and right subtrees
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

// Function to print inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    // Creating the original binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Printing the inorder traversal of the original tree
    printf("Inorder Traversal of Original Tree: ");
    inorderTraversal(root);
    printf("\n");

    // Copying the tree
    struct Node* copiedTree = copyTree(root);

    // Printing the inorder traversal of the copied tree
    printf("Inorder Traversal of Copied Tree: ");
    inorderTraversal(copiedTree);
    printf("\n");

    return 0;
}

/* Sample Output:
For the tree structure:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7

The output will be:
Inorder Traversal of Original Tree: 4 2 5 1 6 3 7 
Inorder Traversal of Copied Tree: 4 2 5 1 6 3 7


*/