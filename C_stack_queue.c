#include <stdio.h>
#include <stdlib.h>

// ---------- Node Structure ----------
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// ---------- Stack using Linked List ----------
struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to Stack\n", value);
}

void pop() {
    if (top == NULL)
        printf("Stack is empty!\n");
    else {
        struct Node* temp = top;
        printf("Popped %d from Stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void displayStack() {
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ---------- Queue using Linked List ----------
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = createNode(value);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d to Queue\n", value);
}

void dequeue() {
    if (front == NULL)
        printf("Queue is empty!\n");
    else {
        struct Node* temp = front;
        printf("Dequeued %d from Queue\n", front->data);
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

void displayQueue() {
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ---------- Main Function ----------
int main() {
    // Stack demonstration
    printf("---- Stack (Linked List) ----\n");
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();

    // Queue demonstration
    printf("\n---- Queue (Linked List) ----\n");
    enqueue(5);
    enqueue(15);
    enqueue(25);
    displayQueue();
    dequeue();
    displayQueue();

    return 0;
}
