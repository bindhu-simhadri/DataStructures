/* C program that creates a binary tree and implements Preorder, Inorder, and Postorder traversals in a recursive way. */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct Node {
    int data;           // Data of the node
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);         // Visit root node
        preorderTraversal(root->left);     // Traverse left subtree
        preorderTraversal(root->right);    // Traverse right subtree
    }
}

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);      // Traverse left subtree
        printf("%d ", root->data);         // Visit root node
        inorderTraversal(root->right);     // Traverse right subtree
    }
}

// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);    // Traverse left subtree
        postorderTraversal(root->right);   // Traverse right subtree
        printf("%d ", root->data);         // Visit root node
    }
}

// Main function to test the traversals
int main() {
    // Creating a simple binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    preorderTraversal(root);  // Perform Preorder Traversal
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);   // Perform Inorder Traversal
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root); // Perform Postorder Traversal
    printf("\n");

    return 0;
}


/* SAMPLE OUTPUT
Preorder Traversal: 1 2 4 5 3 
Inorder Traversal: 4 2 5 1 3 
Postorder Traversal: 4 5 2 3 1

Tree Structure:
    1
   / \
  2   3
 / \
4   5

*/