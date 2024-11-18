/* Define a Student structure having 
members name (which is char array), 
cgpa (which is float type), 
birthdate (which is a pointer to a structure date having 3 integer members for storing day, month, and year), 
admission_date (which is pointer to a structure date having 3 integer members for storing day, month, and year), address (which is character array). 
Write a C program to Create an array of structure of type Student to store details of 'n' students. 
Read the details of 'n' students and display the same in the main function. 
Define a function Age which takes a pointer to the structure Student and calculates the age of the student during admission time and displays the same.Test this function from the main.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a date
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Structure to store student details
typedef struct {
    char name[50];
    float cgpa;
    Date *birthdate;
    Date *admission_date;
    char address[100];
} Student;

// Function to calculate age during admission
void Age(Student *student) {
    int age_years = student->admission_date->year - student->birthdate->year;
    int age_months = student->admission_date->month - student->birthdate->month;
    int age_days = student->admission_date->day - student->birthdate->day;

    if (age_months < 0 || (age_months == 0 && age_days < 0)) {
        age_years--; // Adjust age if admission is before the birth date in the same year
    }

    printf("Age during admission: %d years\n", age_years);
}

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for 'n' students
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input details of each student
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        getchar(); // Clear newline character from buffer
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline

        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);

        // Allocate memory for birthdate
        students[i].birthdate = (Date *)malloc(sizeof(Date));
        printf("Birthdate (DD MM YYYY): ");
        scanf("%d %d %d", &students[i].birthdate->day, &students[i].birthdate->month, &students[i].birthdate->year);

        // Allocate memory for admission_date
        students[i].admission_date = (Date *)malloc(sizeof(Date));
        printf("Admission Date (DD MM YYYY): ");
        scanf("%d %d %d", &students[i].admission_date->day, &students[i].admission_date->month, &students[i].admission_date->year);

        printf("Address: ");
        getchar(); // Clear newline character from buffer
        fgets(students[i].address, sizeof(students[i].address), stdin);
        students[i].address[strcspn(students[i].address, "\n")] = '\0'; // Remove newline
    }

    // Display details of each student and calculate age
    printf("\nStudent Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("CGPA: %.2f\n", students[i].cgpa);
        printf("Birthdate: %02d-%02d-%04d\n", students[i].birthdate->day, students[i].birthdate->month, students[i].birthdate->year);
        printf("Admission Date: %02d-%02d-%04d\n", students[i].admission_date->day, students[i].admission_date->month, students[i].admission_date->year);
        printf("Address: %s\n", students[i].address);

        // Calculate and display age
        Age(&students[i]);

        // Free allocated memory for dates
        free(students[i].birthdate);
        free(students[i].admission_date);
    }

    // Free allocated memory for students
    free(students);

    return 0;
}

/* SAMPLE OUTPUT 

INPUT:
Enter the number of students: 2

Enter details for student 1:
Name: John Doe
CGPA: 8.5
Birthdate (DD MM YYYY): 15 8 2000
Admission Date (DD MM YYYY): 1 7 2020
Address: 123 Main Street

Enter details for student 2:
Name: Jane Smith
CGPA: 9.2
Birthdate (DD MM YYYY): 20 5 2001
Admission Date (DD MM YYYY): 15 8 2019
Address: 456 Elm Avenue

OUTPUT:
Student Details:

Student 1:
Name: John Doe
CGPA: 8.50
Birthdate: 15-08-2000
Admission Date: 01-07-2020
Address: 123 Main Street
Age during admission: 19 years

Student 2:
Name: Jane Smith
CGPA: 9.20
Birthdate: 20-05-2001
Admission Date: 15-08-2019
Address: 456 Elm Avenue
Age during admission: 18 years
*/



