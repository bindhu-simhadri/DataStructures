/* Solve the following problem of sorting the elements in a ragged array using a C program. Write a function called Create that accepts an integer pointer to pointer and an integer 'n' and creates a ragged array consisting of 'n' rows using dynamic memory allocation functions.
Write a recursive function called Sort which accepts an integer pointer and an integer 'm' to sort each row of the ragged array. Write the main function to test the above two functions and to display the ragged array before and after sorting.*/

#include <stdio.h>
#include <stdlib.h>

// Recursive binary search function
int BinSearch(int *arr, int low, int high, int target) {
    if (low > high) {
        return 0; // Element not found
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return 1; // Element found
    } else if (arr[mid] > target) {
        return BinSearch(arr, low, mid - 1, target);
    } else {
        return BinSearch(arr, mid + 1, high, target);
    }
}

// Recursive function to calculate the sum of array elements
int AddArray(int *arr, int n) {
    if (n == 0) {
        return 0; // Base case
    }
    return arr[n - 1] + AddArray(arr, n - 1);
}

int main() {
    int n, target, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input elements
    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target element to search
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Call BinSearch function
    if (BinSearch(arr, 0, n - 1, target)) {
        printf("Element %d found in the array.\n", target);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Call AddArray function
    int sum = AddArray(arr, n);
    printf("Sum of array elements: %d\n", sum);

    // Free allocated memory
    free(arr);

    return 0;
}

/*SAMPLE OUTPUT

Input:
Enter the number of elements: 5
Enter 5 sorted elements: 1 3 5 7 9
Enter the element to search: 5

Output:
Element 5 found in the array.
Sum of array elements: 25
*/