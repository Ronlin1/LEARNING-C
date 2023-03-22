#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
    Node *head = NULL;
    Node *temp = NULL;

    // Read marks from input until the end of file is reached
    int mark;
    while (scanf("%d", &mark) != EOF) {
        // Allocate memory for a new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = mark;
        newNode->next = NULL;

        // Add the new node to the end of the list
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Compute the minimum, maximum, and average marks
    int min = head->data;
    int max = head->data;
    int sum = 0;
    int count = 0;
    temp = head;
    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        if (temp->data > max) {
            max = temp->data;
        }
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    float average = (float)sum / count;

    // Print the results
    printf("Minimum mark: %d\n", min);
    printf("Maximum mark: %d\n", max);
    printf("Average mark: %.2f\n", average);

    // Free memory used by the linked list
    temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
