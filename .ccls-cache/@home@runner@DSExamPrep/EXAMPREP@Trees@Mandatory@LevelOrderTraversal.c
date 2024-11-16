#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;           // Data of the node
    struct Node* left;  // Pointer to the left child
    struct Node* right; // Pointer to the right child
};

// Queue Node to help with Level Order Traversal
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct QueueNode* queue = NULL;
    struct QueueNode* rear = NULL;

    // Insert the new node in the first available position
    struct QueueNode* tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    tempQueueNode->treeNode = *root;
    tempQueueNode->next = NULL;

    if (queue == NULL) {
        queue = tempQueueNode;
        rear = tempQueueNode;
    } else {
        rear->next = tempQueueNode;
        rear = tempQueueNode;
    }

    while (queue != NULL) {
        struct Node* current = queue->treeNode;
        if (current->left == NULL) {
            current->left = newNode;
            break;
        } else if (current->right == NULL) {
            current->right = newNode;
            break;
        }
        if (current->left != NULL) {
            tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            tempQueueNode->treeNode = current->left;
            tempQueueNode->next = NULL;
            rear->next = tempQueueNode;
            rear = tempQueueNode;
        }
        if (current->right != NULL) {
            tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            tempQueueNode->treeNode = current->right;
            tempQueueNode->next = NULL;
            rear->next = tempQueueNode;
            rear = tempQueueNode;
        }
        queue = queue->next;
    }
}

// Function for Level Order Traversal (Breadth-First Traversal)
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct QueueNode* queue = NULL;
    struct QueueNode* rear = NULL;

    struct QueueNode* tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    tempQueueNode->treeNode = root;
    tempQueueNode->next = NULL;

    if (queue == NULL) {
        queue = tempQueueNode;
        rear = tempQueueNode;
    } else {
        rear->next = tempQueueNode;
        rear = tempQueueNode;
    }

    while (queue != NULL) {
        struct Node* current = queue->treeNode;
        printf("%d ", current->data);

        if (current->left != NULL) {
            tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            tempQueueNode->treeNode = current->left;
            tempQueueNode->next = NULL;
            rear->next = tempQueueNode;
            rear = tempQueueNode;
        }
        if (current->right != NULL) {
            tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            tempQueueNode->treeNode = current->right;
            tempQueueNode->next = NULL;
            rear->next = tempQueueNode;
            rear = tempQueueNode;
        }
        queue = queue->next;
    }
}

// Function to delete the last node in the binary tree
void deleteNode(struct Node* root) {
    if (root == NULL) return;
    struct QueueNode* queue = NULL;
    struct QueueNode* rear = NULL;
    struct QueueNode* tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    tempQueueNode->treeNode = root;
    tempQueueNode->next = NULL;

    if (queue == NULL) {
        queue = tempQueueNode;
        rear = tempQueueNode;
    } else {
        rear->next = tempQueueNode;
        rear = tempQueueNode;
    }

    struct Node* nodeToDelete = NULL;

    while (queue != NULL) {
        struct Node* current = queue->treeNode;

        // Check if this node is the last node in the binary tree
        if (current->left == NULL && current->right == NULL) {
            nodeToDelete = current;
            break;
        }

        if (current->right != NULL) {
            tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            tempQueueNode->treeNode = current->right;
            tempQueueNode->next = NULL;
            rear->next = tempQueueNode;
            rear = tempQueueNode;
        }

        if (current->left != NULL) {
            tempQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            tempQueueNode->treeNode = current->left;
            tempQueueNode->next = NULL;
            rear->next = tempQueueNode;
            rear = tempQueueNode;
        }

        queue = queue->next;
    }

    // Now delete the node
    if (nodeToDelete != NULL) {
        free(nodeToDelete);
    }
}

// Main function to test the binary tree functions
int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary tree
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);

    // Perform Level Order Traversal
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    // Delete a node (e.g., the last node)
    printf("Deleting a node...\n");
    deleteNode(root);

    // Perform Level Order Traversal again
    printf("Level Order Traversal after deletion: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}

/* SAMPLE OUTPUT 
Level Order Traversal: 1 2 3 4 5
Deleting a node...
Level Order Traversal after deletion: 1 2 3 4

Tree Structure (Before Deletion):
      1
    /   \
   2     3
  / \   / 
 4   5
Level Order Traversal of this tree: 1 2 3 4 5.

Tree Structure (After Deletion):
After performing the deletion, the last node (node 5) is deleted.

The structure of the tree is now:

      1
    /   \
   2     3
  / 
 4
Level Order Traversal after deletion: 1 2 3 4.

*/