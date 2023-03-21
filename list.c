#include <stdio.h>
#include <stdlib.h>

struct Student {
    int marks;
    struct Student* next;
};

void addStudent(struct Student** head) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter marks (-1 to end): ");
    scanf("%d", &newStudent->marks);
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }

    if (newStudent->marks != -1) {
        addStudent(head);
    }
}

void printList(struct Student* head) {
    printf("Marks: ");
    while (head != NULL) {
        printf("%d ", head->marks);
        head = head->next;
    }
    printf("\n");
}

void findMinMaxAverage(struct Student* head) {
    int min = head->marks;
    int max = head->marks;
    int sum = 0;
    int count = 0;

    while (head != NULL) {
        if (head->marks < min) {
            min = head->marks;
        }
        if (head->marks > max) {
            max = head->marks;
        }
        sum += head->marks;
        count++;
        head = head->next;
    }

    float average = (float)sum / count;

    printf("Minimum marks: %d\n", min);
    printf("Maximum marks: %d\n", max);
    printf("Average marks: %.2f\n", average);
}

int main() {
    struct Student* head = NULL;

    addStudent(&head);
    printList(head);
    findMinMaxAverage(head);

    return 0;
}
