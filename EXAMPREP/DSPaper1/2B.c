/* 2B. Design a simple task priority queue in C without using any specific data structure. Each task has a  priority, and the goal is to execute tasks in order of their priority, with higher priority tasks being executed first.
a) Define a structure Task with attributes priority (an integer) and description (a string).
b) Implement functions to manage the following.
i) void enqueueTaskWithPriority(int priority, const char *description): Adds a task with a given priority to the priority queue.
ii) void executeHighestPriorityTask() : Executes and removes the task with the highest priority from the queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define DESCRIPTION_SIZE 100

// Task structure
typedef struct {
    int priority;
    char description[DESCRIPTION_SIZE];
} Task;

// Task queue
Task taskQueue[MAX_TASKS];
int taskCount = 0;

// Function to add a task to the queue
void enqueueTaskWithPriority(int priority, const char *description) {
    if (taskCount >= MAX_TASKS) {
        printf("Task queue is full. Cannot add more tasks.\n");
        return;
    }
    taskQueue[taskCount].priority = priority;
    strncpy(taskQueue[taskCount].description, description, DESCRIPTION_SIZE - 1);
    taskQueue[taskCount].description[DESCRIPTION_SIZE - 1] = '\0'; // Ensure null-termination
    taskCount++;
    printf("Task added: [%d] %s\n", priority, description);
}

// Function to execute and remove the task with the highest priority
void executeHighestPriorityTask() {
    if (taskCount == 0) {
        printf("No tasks in the queue.\n");
        return;
    }

    // Find the highest priority task
    int highestPriorityIndex = 0;
    for (int i = 1; i < taskCount; i++) {
        if (taskQueue[i].priority > taskQueue[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    // Execute the task
    printf("Executing task: [%d] %s\n", taskQueue[highestPriorityIndex].priority, taskQueue[highestPriorityIndex].description);

    // Remove the task by shifting remaining tasks
    for (int i = highestPriorityIndex; i < taskCount - 1; i++) {
        taskQueue[i] = taskQueue[i + 1];
    }
    taskCount--;
}

int main() {
    int choice, priority;
    char description[DESCRIPTION_SIZE];

    while (1) {
        printf("\nTask Priority Queue Menu:\n");
        printf("1. Add Task\n");
        printf("2. Execute Highest Priority Task\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task priority: ");
                scanf("%d", &priority);
                getchar(); // Clear newline character
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove newline character
                enqueueTaskWithPriority(priority, description);
                break;
            case 2:
                executeHighestPriorityTask();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


/* SAMPLE OUTPUT 
Task Priority Queue Menu:
1. Add Task
2. Execute Highest Priority Task
3. Exit
Enter your choice: 1
Enter task priority: 5
Enter task description: Complete homework
Task added: [5] Complete homework

Task Priority Queue Menu:
1. Add Task
2. Execute Highest Priority Task
3. Exit
Enter your choice: 1
Enter task priority: 10
Enter task description: Prepare presentation
Task added: [10] Prepare presentation

Task Priority Queue Menu:
1. Add Task
2. Execute Highest Priority Task
3. Exit
Enter your choice: 2
Executing task: [10] Prepare presentation

Task Priority Queue Menu:
1. Add Task
2. Execute Highest Priority Task
3. Exit
Enter your choice: 2
Executing task: [5] Complete homework

Task Priority Queue Menu:
1. Add Task
2. Execute Highest Priority Task
3. Exit
Enter your choice: 2
No tasks in the queue.

Task Priority Queue Menu:
1. Add Task
2. Execute Highest Priority Task
3. Exit
Enter your choice: 3
Exiting program.
*/

