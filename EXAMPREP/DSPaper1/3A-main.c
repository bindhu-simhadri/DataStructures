int main() {
    // Construct the tree
    struct Node *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('E');
    root->left->right = createNode('F');
    root->left->left->left = createNode('K');
    root->left->left->right = createNode('L');
    root->right->left = createNode('G');
    root->right->right = createNode('H');
    root->right->right->left = createNode('I');
    root->right->right->right = createNode('J');
    root->right->right->left->left = createNode('M');

    // Find the largest node in the tree
    int largest = findLargest(root);
    printf("Largest Node Value: %c\n", largest);

    // Find the height of the tree
    int height = findHeight(root);
    printf("Height of the Tree: %d\n", height);

    // Convert to Left Child-Right Sibling Representation
    convertToLCRS(root);
    printf("\nLeft Child-Right Sibling Representation:\n");
    printLCRS(root);

    return 0;
}


/* SAMPLE OUTPUT

EXAMPLE TREE:

       A
     / | \
    B  C  D
   / \ |  /|\
  E  F G H I J
 / \       |
K   L      M

EXAMPLE OUTPUT:
Largest Node Value: M
Height of the Tree: 4

Left Child-Right Sibling Representation:
A -> Left Child: B, Right Sibling: NULL
B -> Left Child: E, Right Sibling: C
E -> Left Child: K, Right Sibling: F
K -> Left Child: NULL, Right Sibling: L
L -> Left Child: NULL, Right Sibling: NULL
F -> Left Child: NULL, Right Sibling: NULL
C -> Left Child: G, Right Sibling: D
G -> Left Child: NULL, Right Sibling: NULL
D -> Left Child: H, Right Sibling: NULL
H -> Left Child: I, Right Sibling: NULL
I -> Left Child: M, Right Sibling: NULL
M -> Left Child: NULL, Right Sibling: NULL

*/