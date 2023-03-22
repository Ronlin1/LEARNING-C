#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void compute(struct node* head, int* min, int* max, float* avg) {
    int sum = 0, count = 0;
    *min = head->data;
    *max = head->data;
    while (head != NULL) {
        if (head->data < *min) {
            *min = head->data;
        }
        if (head->data > *max) {
            *max = head->data;
        }
        sum += head->data;
        count++;
        head = head->next;
    }
    *avg = (float)sum / count;
}

int main() {
    struct node* head = NULL;
    int n, data, min, max;
    float avg;
    printf("Enter the number of marks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter mark #%d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }
    printf("The marks are: ");
    print(head);
    compute(head, &min, &max, &avg);
    printf("Min mark: %d\n", min);
    printf("Max mark: %d\n", max);
    printf("Average mark: %.2f\n", avg);
    return 0;
}
