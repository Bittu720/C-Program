#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertbegin(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertend(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertatposition(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;

    if (position < 1) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    if (position == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deletebegin() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted: %d\n", temp->info);
    free(temp);
}

void deleteend() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        printf("Deleted: %d\n", temp->info);
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    printf("Deleted: %d\n", temp->info);
    free(temp);
}

void deleteatposition(int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        printf("Deleted: %d\n", temp->info);
        free(temp);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted: %d\n", temp->info);
    free(temp);
}
void display(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (node != NULL) {
        printf("%d <-> ", node->info);
        node = node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    int data, choice, position;
    char ch;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at any position\n");
        printf("7. Display linked list\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            insertbegin(data);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &data);
            insertend(data);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertatposition(data, position);
            break;
        case 4:
            deletebegin();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteatposition(position);
            break;
        case 7:
            display(head);
            break;
        default:
            printf("Wrong choice\n");
        }

        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    freeList(head);
    return 0;
}