
#include <stdio.h>
#define MAX 10

typedef struct {
    int jobID;
    char title[30];
} PrintJob;

PrintJob queue[MAX];
int front = -1, rear = -1;


void enqueue() {
    PrintJob job;

    if (rear == MAX - 1) {
        printf("\nQueue Full!\n");
        return;
    }

    printf("\nEnter Job ID: ");
    scanf("%d", &job.jobID);

    printf("Enter File Name: ");
    scanf("%s", job.title);

    if (front == -1)
        front = 0;

    queue[++rear] = job;

    printf("Job %d added successfully.\n", job.jobID);
}


void dequeue() {
    if (front == -1) {
        printf("\nQueue Empty!\n");
        return;
    }

    printf("\nProcessing Job %d: %s\n",
           queue[front].jobID,
           queue[front].title);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}


void display() {
    if (front == -1) {
        printf("\nNo jobs in queue.\n");
        return;
    }

    printf("\nPending Jobs:\n");

    for (int i = front; i <= rear; i++) {
        printf("Job %d: %s\n",
               queue[i].jobID,
               queue[i].title);
    }
}

int main() {
    int choice;

    do {
       
        printf("1. Add Print Job (Enqueue)\n");
        printf("2. Process Print Job (Dequeue)\n");
        printf("3. Display Pending Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
```