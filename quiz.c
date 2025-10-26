#include <stdio.h>
#include <stdlib.h>

///----------------------
/// Singly Linked List
///----------------------
struct SNode {
    int data;
    struct SNode *next;
};

struct SNode* insertS(struct SNode *head, int data) {
    struct SNode *newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void printS(struct SNode *head) {
    printf("Singly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

///----------------------
/// Doubly Linked List
///----------------------
struct DNode {
    int data;
    struct DNode *prev, *next;
};

struct DNode* insertD(struct DNode *head, int data) {
    struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

void printD(struct DNode *head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

///----------------------
/// Stack (using array)
///----------------------
#define MAX 5
struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s) { s->top = -1; }

void push(struct Stack *s, int val) {
    if (s->top == MAX - 1) printf("Stack Overflow\n");
    else s->arr[++s->top] = val;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void printStack(struct Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) printf("%d ", s->arr[i]);
    printf("\n");
}

///----------------------
/// Queue (using array)
///----------------------
struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue *q, int val) {
    if (q->rear == MAX - 1) printf("Queue Overflow\n");
    else q->arr[++q->rear] = val;
}

int dequeue(struct Queue *q) {
    if (q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->arr[q->front++];
}

void printQueue(struct Queue *q) {
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

///----------------------
/// Main Function
///----------------------
int main() {
    /// Singly Linked List
    struct SNode *shead = NULL;
    shead = insertS(shead, 10);
    shead = insertS(shead, 20);
    shead = insertS(shead, 30);
    printS(shead);

    /// Doubly Linked List
    struct DNode *dhead = NULL;
    dhead = insertD(dhead, 100);
    dhead = insertD(dhead, 200);
    dhead = insertD(dhead, 300);
    printD(dhead);

    /// Stack
    struct Stack s;
    initStack(&s);
    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    printStack(&s);
    pop(&s);
    printStack(&s);

    /// Queue
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printQueue(&q);
    dequeue(&q);
    printQueue(&q);

    return 0;
}
