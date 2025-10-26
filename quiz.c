#include <stdio.h>
#include <stdlib.h>

/// ==========================================
/// SINGLY LINKED LIST
/// ==========================================
struct SNode {
    int data;
    struct SNode *next;
};
struct SNode *shead = NULL;

void s_insert_end(int value) {
    struct SNode *newNode = malloc(sizeof(struct SNode));
    newNode->data = value;
    newNode->next = NULL;
    if (shead == NULL) shead = newNode;
    else {
        struct SNode *temp = shead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void s_insert_pos(int value, int pos) {
    struct SNode *newNode = malloc(sizeof(struct SNode));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = shead;
        shead = newNode;
        return;
    }
    struct SNode *temp = shead;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void s_delete(int value) {
    struct SNode *temp = shead, *prev = NULL;
    if (temp != NULL && temp->data == value) {
        shead = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void s_search(int value) {
    struct SNode *temp = shead;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found!\n", value);
}

void s_reverse() {
    struct SNode *prev = NULL, *curr = shead, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    shead = prev;
}

void s_display() {
    struct SNode *temp = shead;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// ==========================================
/// DOUBLY LINKED LIST
/// ==========================================
struct DNode {
    int data;
    struct DNode *next, *prev;
};
struct DNode *dhead = NULL;

void d_insert_end(int value) {
    struct DNode *newNode = malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    if (dhead == NULL) dhead = newNode;
    else {
        struct DNode *temp = dhead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void d_insert_pos(int value, int pos) {
    struct DNode *newNode = malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    if (pos == 1) {
        newNode->next = dhead;
        if (dhead) dhead->prev = newNode;
        dhead = newNode;
        return;
    }
    struct DNode *temp = dhead;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void d_delete(int value) {
    struct DNode *temp = dhead;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else dhead = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void d_search(int value) {
    struct DNode *temp = dhead;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found!\n", value);
}

void d_reverse() {
    struct DNode *temp = NULL, *curr = dhead;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        dhead = temp->prev;
}

void d_display_forward() {
    struct DNode *temp = dhead;
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void d_display_backward() {
    if (dhead == NULL) return;
    struct DNode *temp = dhead;
    while (temp->next != NULL) temp = temp->next;
    printf("Doubly Linked List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/// ==========================================
/// STACK (Linked List)
/// ==========================================
struct Stack {
    int data;
    struct Stack *next;
};
struct Stack *top = NULL;

void push(int value) {
    struct Stack *newNode = malloc(sizeof(struct Stack));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Stack *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void display_stack() {
    struct Stack *temp = top;
    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// ==========================================
/// QUEUE (Linked List)
/// ==========================================
struct Queue {
    int data;
    struct Queue *next;
};
struct Queue *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Queue *newNode = malloc(sizeof(struct Queue));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Queue *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display_queue() {
    struct Queue *temp = front;
    printf("Queue (Front to Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// ==========================================
/// MAIN FUNCTION (Demo)
/// ==========================================
int main() {
    // Singly Linked List demo
    s_insert_end(10);
    s_insert_end(20);
    s_insert_end(30);
    s_insert_pos(15, 2);
    s_display();
    s_search(20);
    s_delete(15);
    s_display();
    s_reverse();
    printf("After reverse: ");
    s_display();

    printf("\n");

    // Doubly Linked List demo
    d_insert_end(1);
    d_insert_end(2);
    d_insert_end(3);
    d_insert_pos(10, 2);
    d_display_forward();
    d_display_backward();
    d_delete(10);
    d_display_forward();
    d_reverse();
    printf("After reverse: ");
    d_display_forward();

    printf("\n");

    // Stack demo
    push(100);
    push(200);
    push(300);
    display_stack();
    pop();
    display_stack();

    printf("\n");

    // Queue demo
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display_queue();
    dequeue();
    display_queue();

    return 0;
}
