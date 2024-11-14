/* Write a function to add two polynomials, polynomial A, and polynomial B,
 * represented as singly linked lists. The function should accept pointers to
 * linked lists representing two polynomials and return a pointer to the linked
 * list representing the sum.*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term node
struct Node {
  int coeff;         // Coefficient of the term
  int exp;           // Exponent of the term
  struct Node *next; // Pointer to the next term in the polynomial
};

// Function to create a new node with a given coefficient and exponent
struct Node *createNode(int coeff, int exp) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->coeff = coeff;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

// Function to add two polynomials represented as linked lists
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
  struct Node *sum = NULL;  // Resulting polynomial
  struct Node *last = NULL; // Pointer to the last node in the result list

  // Traverse both polynomials and add terms with the same exponent
  while (poly1 != NULL || poly2 != NULL) {
    int coeff, exp;

    if (poly1 == NULL) { // poly1 is exhausted, take terms from poly2
      coeff = poly2->coeff;
      exp = poly2->exp;
      poly2 = poly2->next;
    } else if (poly2 == NULL) { // poly2 is exhausted, take terms from poly1
      coeff = poly1->coeff;
      exp = poly1->exp;
      poly1 = poly1->next;
    } else if (poly1->exp > poly2->exp) { // Higher exponent term in poly1
      coeff = poly1->coeff;
      exp = poly1->exp;
      poly1 = poly1->next;
    } else if (poly2->exp > poly1->exp) { // Higher exponent term in poly2
      coeff = poly2->coeff;
      exp = poly2->exp;
      poly2 = poly2->next;
    } else { // Exponents are the same, add coefficients
      coeff = poly1->coeff + poly2->coeff;
      exp = poly1->exp;
      poly1 = poly1->next;
      poly2 = poly2->next;
    }

    // Skip zero coefficients in the result
    if (coeff != 0) {
      struct Node *newNode = createNode(coeff, exp);

      if (sum == NULL) { // Initialize sum list if empty
        sum = newNode;
        last = sum;
      } else { // Append new node to the result
        last->next = newNode;
        last = newNode;
      }
    }
  }
  return sum;
}

// Function to display a polynomial
void displayPolynomial(struct Node *poly) {
  struct Node *ptr = poly;
  while (ptr != NULL) {
    printf("%dx^%d", ptr->coeff, ptr->exp);
    ptr = ptr->next;
    if (ptr != NULL)
      printf(" + ");
  }
  printf("\n");
}

int main() {
  // Creating Polynomial A: 3x^4 + 5x^2 + 6
  struct Node *poly1 = createNode(3, 4);
  poly1->next = createNode(5, 2);
  poly1->next->next = createNode(6, 0);

  // Creating Polynomial B: 4x^3 + 2x^2 + 7
  struct Node *poly2 = createNode(4, 3);
  poly2->next = createNode(2, 2);
  poly2->next->next = createNode(7, 0);

  // Display polynomials A and B
  printf("Polynomial A: ");
  displayPolynomial(poly1);

  printf("Polynomial B: ");
  displayPolynomial(poly2);

  // Add polynomials A and B
  struct Node *sum = addPolynomials(poly1, poly2);

  // Display the resulting polynomial sum
  printf("Sum: ");
  displayPolynomial(sum);

  return 0;
}

/*SAMPLE OUTPUT
Polynomial A: 3x^4 + 5x^2 + 6
Polynomial B: 4x^3 + 2x^2 + 7
Sum: 3x^4 + 4x^3 + 7x^2 + 13
*/