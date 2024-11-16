/* C program that creates a binary tree and implements Preorder, Inorder, and Postorder traversals in a iterative way. */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct Node {
    int data;           // Data of the node
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child
};

// Define the structure for a stack node
struct StackNode {
    struct Node* treeNode;
    struct StackNode* next;
};

// Function to push a node onto the stack
void push(struct StackNode** top, struct Node* node) {
    struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newStackNode->treeNode = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

// Function to pop a node from the stack
struct Node* pop(struct StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct Node* node = temp->treeNode;
    free(temp);
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Iterative Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(&stack);
        printf("%d ", current->data);  // Visit the root node

        // Push right child first so that left child is processed first
        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

// Iterative Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) {
    struct StackNode* stack = NULL;
    struct Node* current = root;

    while (!isEmpty(stack) || current != NULL) {
        // Reach the leftmost node
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        // Pop the node from the stack and visit it
        current = pop(&stack);
        printf("%d ", current->data);

        // Move to the right subtree
        current = current->right;
    }
}

// Iterative Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* current = pop(&stack1);
        push(&stack2, current);  // Push the node to stack2 after visiting it

        // Push left and right children to stack1
        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    // Pop from stack2 and print the nodes
    while (!isEmpty(stack2)) {
        struct Node* current = pop(&stack2);
        printf("%d ", current->data);
    }
}

// Main function to test the iterative traversals
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


/* Sample output

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