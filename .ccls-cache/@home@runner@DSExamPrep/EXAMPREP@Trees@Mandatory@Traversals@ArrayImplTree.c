/* Array Implementation of trees */

#include <stdio.h>

#define MAX 15 // Maximum size of the array

void printTree(char tree[], int size) {
    printf("Binary Tree Array Representation:\n");
    for (int i = 1; i < size; i++) {
        printf("Index %d: %c\n", i, tree[i]);
    }
}

int main() {
    char tree[MAX] = {0}; // Initialize all elements to 0
    int n = 7; // Number of nodes in the tree

    // Populate tree using the given example
    tree[1] = 'A'; // Root
    tree[2] = 'B'; // Left child of A
    tree[3] = 'C'; // Right child of A
    tree[4] = 'D'; // Left child of B
    tree[5] = 'E'; // Right child of B
    tree[6] = 'F'; // Right child of C

    printTree(tree, n + 1);
    return 0;
}

/* SAMPLE OUTPUT
Binary Tree Array Representation:
Index 1: A
Index 2: B
Index 3: C
Index 4: D
Index 5: E
Index 6: F
Index 7: NULL
*/