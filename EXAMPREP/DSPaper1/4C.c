/* 4C. Suggest a suitable data structure to handle I/O operations in the computer systems and implement  the code.
Note- While interrupt operations are not allowed.*/

/* Suitable Data Structure for I/O Operations Without Interrupts
A queue is the most suitable data structure to handle I/O operations in computer systems, especially when interrupt operations are not allowed. This is because:

First-In-First-Out (FIFO) Behavior: Queues process tasks in the order they are added, ensuring fairness.
Buffering: Queues can act as buffers between processes or devices to handle varying speeds.
Continuous Processing: Tasks can be enqueued (added) by producers and dequeued (processed) by consumers without requiring interrupts.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum size of the queue

// Structure to represent an I/O task
typedef struct {
    int taskID;           // Unique ID for the task
    char description[50]; // Description of the task
} Task;

// Queue structure
typedef struct {
    Task tasks[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to enqueue a task
void enqueue(Queue *q, int taskID, const char *description) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue task %d.\n", taskID);
        return;
    }

    // Add task to the queue
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->tasks[q->rear].taskID = taskID;
    strcpy(q->tasks[q->rear].description, description);

    printf("Task %d added: %s\n", taskID, description);
}

// Function to dequeue a task
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No task to process.\n");
        return;
    }

    // Process the task at the front
    printf("Processing Task %d: %s\n", q->tasks[q->front].taskID, q->tasks[q->front].description);

    // Remove the task from the queue
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset the queue if empty
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Function to display the tasks in the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Current Tasks in Queue:\n");
    int i = q->front;
    while (1) {
        printf("Task %d: %s\n", q->tasks[i].taskID, q->tasks[i].description);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
}

int main() {
    Queue q;
    initializeQueue(&q);

    // Add tasks to the queue
    enqueue(&q, 1, "Read data from disk");
    enqueue(&q, 2, "Write data to disk");
    enqueue(&q, 3, "Send data to printer");

    // Display the queue
    displayQueue(&q);

    // Process tasks
    dequeue(&q);
    dequeue(&q);

    // Add another task
    enqueue(&q, 4, "Save data to database");

    // Display the queue again
    displayQueue(&q);

    // Process remaining tasks
    dequeue(&q);
    dequeue(&q);

    return 0;
}

/* Sample Output 
Task 1 added: Read data from disk
Task 2 added: Write data to disk
Task 3 added: Send data to printer
Current Tasks in Queue:
Task 1: Read data from disk
Task 2: Write data to disk
Task 3: Send data to printer
Processing Task 1: Read data from disk
Processing Task 2: Write data to disk
Task 4 added: Save data to database
Current Tasks in Queue:
Task 3: Send data to printer
Task 4: Save data to database
Processing Task 3: Send data to printer
Processing Task 4: Save data to database
*/