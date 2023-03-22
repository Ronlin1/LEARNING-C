#include <stdio.h>
#include <stdlib.h>

// ATUHAIRE RONALD - 22/U/3003/EVE -- 2200703003

// Define a structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};

int main() {
    // Initialize the linked list
    struct node* head = NULL;
    struct node* tail = NULL;

    // Read in marks from the user and add them to the linked list
    int mark;
    printf("Enter a mark (-1 to end): ");
    scanf("%d", &mark);
    while (mark != -1) {
        // Create a new node for the mark
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = mark;
        new_node->next = NULL;

        // Add the new node to the linked list
        if (tail == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        // Read in the next mark
        printf("Enter a mark (-1 to end): ");
        scanf("%d", &mark);
    }

    // Compute the minimum, maximum, and average marks
    int min_mark = head->data;
    int max_mark = head->data;
    int sum = 0;
    int count = 0;
    struct node* current_node = head;
    while (current_node != NULL) {
        if (current_node->data < min_mark) {
            min_mark = current_node->data;
        }
        if (current_node->data > max_mark) {
            max_mark = current_node->data;
        }
        sum += current_node->data;
        count++;
        current_node = current_node->next;
    }
    float avg_mark = (float) sum / count;

    // Print out the results
    printf("Minimum mark: %d\n", min_mark);
    printf("Maximum mark: %d\n", max_mark);
    printf("Average mark: %.2f\n", avg_mark);

    // Free the memory used by the linked list
    current_node = head;
    while (current_node != NULL) {
        struct node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}
