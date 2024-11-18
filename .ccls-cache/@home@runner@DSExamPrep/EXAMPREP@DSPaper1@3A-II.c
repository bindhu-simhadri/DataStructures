/* Part (ii): Finding the Height and Left Child-Right Sibling Representation
Steps to Find Height:
The height of a tree is the maximum depth of its nodes.
Use a recursive approach to calculate the height:
Height = 1 + max(height of left subtree, height of right subtree).
Steps for Left Child-Right Sibling Representation:
Represent the root's left child as its "left pointer."
Represent the next sibling of a node as its "right pointer."
Traverse the tree to rearrange pointers accordingly.*/

// Code for Height and Conversion to Left Child-Right Sibling Representation

// Function to find the height of the binary tree
int findHeight(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to convert a general tree to left child-right sibling representation
struct Node *convertToLCRS(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left) {
        root->left = convertToLCRS(root->left);
    }

    if (root->right) {
        root->right = convertToLCRS(root->right);
    }

    // Combine left child and right sibling into LCRS format
    if (root->left) {
        struct Node *temp = root->left;
        while (temp->right) {
            temp = temp->right;
        }
        temp->right = root->right;
        root->right = NULL;
    }
    return root;
}

// Function to print the LCRS representation of the tree
void printLCRS(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%c -> ", root->data);
    if (root->left) {
        printf("Left Child: %c, ", root->left->data);
    } else {
        printf("Left Child: NULL, ");
    }
    if (root->right) {
        printf("Right Sibling: %c\n", root->right->data);
    } else {
        printf("Right Sibling: NULL\n");
    }
    printLCRS(root->left);
    printLCRS(root->right);
}

