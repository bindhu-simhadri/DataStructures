/*C Program to Test Equality of Two Binary Trees */

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

// Function to check if two binary trees are equal
int areTreesEqual(struct Node* root1, struct Node* root2) {
    // If both trees are empty, they are equal
    if (root1 == NULL && root2 == NULL) {
        return 1;  // Both trees are empty
    }

    // If both trees are not empty, compare the data and the left & right subtrees
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) &&
               areTreesEqual(root1->left, root2->left) &&
               areTreesEqual(root1->right, root2->right);
    }

    // If one tree is empty and the other is not, they are not equal
    return 0;
}

// Function to print the result of tree equality
void printEqualityResult(int result) {
    if (result == 1) {
        printf("The trees are equal.\n");
    } else {
        printf("The trees are not equal.\n");
    }
}

// Main function
int main() {
    // Creating the first binary tree
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    // Creating the second binary tree
    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    // Check if the two binary trees are equal
    int result = areTreesEqual(root1, root2);

    // Print the result of equality
    printEqualityResult(result);

    return 0;
}


/* SAMPLE OUTPUT 

If the trees are equal:
The trees are equal.

If the trees are not equal (e.g., if one tree is missing a node or has different values):
The trees are not equal.

Example 1 (Equal Trees):
Given two trees:
        1                1
       / \              / \
      2   3            2   3
     / \              / \
    4   5            4   5

The output will be: The trees are equal.

Example 2 (Unequal Trees):
If we modify one of the trees, e.g., change 5 to 6:
    1                1
   / \              / \
  2   3            2   3
 / \              / \
4   5            4   6

The output will be: The trees are not equal.
*/