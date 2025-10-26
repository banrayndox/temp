#include <stdio.h>
#include <stdlib.h>

/// =============================================
/// SINGLY LINKED LIST
/// =============================================
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
}

void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void displayList() {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// =============================================
/// STACK USING LINKED LIST
/// =============================================
struct StackNode {
    int data;
    struct StackNode *next;
};
struct StackNode *top = NULL;

void pushLL(int value) {
    struct StackNode *newNode = malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void popLL() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct StackNode *temp = top;
    printf("Popped (LL Stack): %d\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStackLL() {
    struct StackNode *temp = top;
    printf("Stack (Linked List): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// =============================================
/// STACK USING ARRAY
/// =============================================
#define MAX 5
int stack[MAX];
int topIndex = -1;

void pushArr(int value) {
    if (topIndex == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++topIndex] = value;
}

void popArr() {
    if (topIndex == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped (Array Stack): %d\n", stack[topIndex--]);
}

void displayStackArr() {
    printf("Stack (Array): ");
    for (int i = topIndex; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

/// =============================================
/// QUEUE USING LINKED LIST
/// =============================================
struct QueueNode {
    int data;
    struct QueueNode *next;
};
struct QueueNode *front = NULL, *rear = NULL;

void enqueueLL(int value) {
    struct QueueNode *newNode = malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeueLL() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct QueueNode *temp = front;
    printf("Dequeued (LL Queue): %d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void displayQueueLL() {
    struct QueueNode *temp = front;
    printf("Queue (Linked List): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// =============================================
/// QUEUE USING ARRAY (Circular)
/// =============================================
int queue[MAX];
int frontIndex = 0, rearIndex = -1, size = 0;

void enqueueArr(int value) {
    if (size == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    rearIndex = (rearIndex + 1) % MAX;
    queue[rearIndex] = value;
    size++;
}

void dequeueArr() {
    if (size == 0) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued (Array Queue): %d\n", queue[frontIndex]);
    frontIndex = (frontIndex + 1) % MAX;
    size--;
}

void displayQueueArr() {
    printf("Queue (Array): ");
    for (int i = 0; i < size; i++)
        printf("%d ", queue[(frontIndex + i) % MAX]);
    printf("\n");
}

/// =============================================
/// MAIN FUNCTION — Function Calls Only
/// =============================================
int main() {
    // Singly Linked List
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    displayList();
    deleteNode(20);
    displayList();
    reverseList();
    displayList();

    printf("\n");

    // Stack using Linked List
    pushLL(100);
    pushLL(200);
    pushLL(300);
    displayStackLL();
    popLL();
    displayStackLL();

    printf("\n");

    // Stack using Array
    pushArr(5);
    pushArr(10);
    pushArr(15);
    displayStackArr();
    popArr();
    displayStackArr();

    printf("\n");

    // Queue using Linked List
    enqueueLL(11);
    enqueueLL(22);
    enqueueLL(33);
    displayQueueLL();
    dequeueLL();
    displayQueueLL();

    printf("\n");

    // Queue using Array
    enqueueArr(7);
    enqueueArr(14);
    enqueueArr(21);
    displayQueueArr();
    dequeueArr();
    displayQueueArr();

    return 0;
}
