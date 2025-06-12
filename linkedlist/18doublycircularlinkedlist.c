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
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
}
void insertend(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
}
void insertatposition(int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertbegin(data);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head && position > 2) {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void deletebegin() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        printf("Deleted: %d\n", head->info);
        free(head);
        head = NULL;
        return;
    }
    struct Node* tail = head->prev;
    struct Node* temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    printf("Deleted: %d\n", temp->info);
    free(temp);
}
void deleteend() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        printf("Deleted: %d\n", head->info);
        free(head);
        head = NULL;
        return;
    }
    struct Node* tail = head->prev;
    struct Node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;
    printf("Deleted: %d\n", tail->info);
    free(tail);
}
void deleteatposition(int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }
    if (position == 1) {
        deletebegin();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp == head) {
        printf("Position out of bounds.\n");
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted: %d\n", temp->info);
    free(temp);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
void freeList() {
    if (head == NULL) return;
    struct Node* temp = head->next;
    while (temp != head) {
        struct Node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    free(head);
    head = NULL;
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
            display();
            break;
        default:
            printf("Wrong choice\n");
        }
        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    freeList();
    return 0;
}