#include <stdio.h>
#include <stdlib.h>

/*-----------------------------
        Singly Linked List
------------------------------*/
struct SNode {
    int data;
    struct SNode* next;
};

struct SNode* sHead = NULL;

// Insert
void sInsertBegin(int val) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = val;
    newNode->next = sHead;
    sHead = newNode;
}

void sInsertEnd(int val) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = val;
    newNode->next = NULL;

    if (!sHead) {
        sHead = newNode;
        return;
    }

    struct SNode* temp = sHead;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void sInsertPos(int val, int pos) {
    if (pos == 1) { 
        sInsertBegin(val); 
        return; 
    }

    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = val;

    struct SNode* temp = sHead;
    for (int i = 1; i < pos - 1 && temp; i++) 
        temp = temp->next;

    if (!temp) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete
void sDeleteBegin() {
    if (!sHead) return;
    struct SNode* temp = sHead;
    sHead = sHead->next;
    free(temp);
}

void sDeleteEnd() {
    if (!sHead) return;
    if (!sHead->next) { 
        free(sHead); 
        sHead = NULL; 
        return; 
    }

    struct SNode* temp = sHead;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void sDeletePos(int pos) {
    if (!sHead) return;
    if (pos == 1) { 
        sDeleteBegin(); 
        return; 
    }

    struct SNode* temp = sHead;
    for (int i = 1; i < pos - 1 && temp->next; i++) 
        temp = temp->next;

    if (!temp->next) return;

    struct SNode* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Search & Update
struct SNode* sSearch(int val) {
    struct SNode* temp = sHead;
    while (temp) {
        if (temp->data == val) return temp;
        temp = temp->next;
    }
    return NULL;
}

void sUpdate(int oldVal, int newVal) {
    struct SNode* node = sSearch(oldVal);
    if (node) node->data = newVal;
}

// Reverse
void sReverse() {
    struct SNode *prev = NULL, *curr = sHead, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    sHead = prev;
}

// Sort
void sSort() {
    if (!sHead) return;

    struct SNode *i, *j;
    for (i = sHead; i->next; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

// Display
void sDisplay() {
    struct SNode* temp = sHead;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*-----------------------------
        Stack (Singly LL)
------------------------------*/
void push(int val) { sInsertBegin(val); }
void pop() { sDeleteBegin(); }
int peek() { return sHead ? sHead->data : -1; }

/*-----------------------------
        Queue (Singly LL)
------------------------------*/
void enqueue(int val) { sInsertEnd(val); }
void dequeue() { sDeleteBegin(); }
int front() { return sHead ? sHead->data : -1; }

/*-----------------------------
        Doubly Linked List
------------------------------*/
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

struct DNode* dHead = NULL;

// Insert
void dInsertBegin(int val) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dHead;

    if (dHead) dHead->prev = newNode;
    dHead = newNode;
}

void dInsertEnd(int val) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = val;
    newNode->next = NULL;

    if (!dHead) { 
        newNode->prev = NULL; 
        dHead = newNode; 
        return;
    }

    struct DNode* temp = dHead;
    while (temp->next) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void dInsertPos(int val, int pos) {
    if (pos == 1) { 
        dInsertBegin(val); 
        return; 
    }

    struct DNode* temp = dHead;
    for (int i = 1; i < pos - 1 && temp; i++) 
        temp = temp->next;

    if (!temp) return;

    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete
void dDeleteBegin() {
    if (!dHead) return;
    struct DNode* temp = dHead;
    dHead = dHead->next;
    if (dHead) dHead->prev = NULL;
    free(temp);
}

void dDeleteEnd() {
    if (!dHead) return;
    if (!dHead->next) { free(dHead); dHead = NULL; return; }

    struct DNode* temp = dHead;
    while (temp->next) temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void dDeletePos(int pos) {
    if (!dHead) return;
    if (pos == 1) { dDeleteBegin(); return; }

    struct DNode* temp = dHead;
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (!temp) return;

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

// Search & Update
struct DNode* dSearch(int val) {
    struct DNode* temp = dHead;
    while (temp) {
        if (temp->data == val) return temp;
        temp = temp->next;
    }
    return NULL;
}

void dUpdate(int oldVal, int newVal) {
    struct DNode* node = dSearch(oldVal);
    if (node) node->data = newVal;
}

// Reverse
void dReverse() {
    struct DNode* temp = NULL;
    struct DNode* curr = dHead;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp) dHead = temp->prev;
}

// Sort
void dSort() {
    if (!dHead) return;

    struct DNode *i, *j;
    for (i = dHead; i->next; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}

// Display
void dDisplay() {
    struct DNode* temp = dHead;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*-----------------------------
            Main
------------------------------*/
int main() {

    // Singly LL Example
    sInsertBegin(20); 
    sInsertBegin(10); 
    sInsertEnd(30); 
    sInsertPos(25, 3);
    sDisplay();

    sUpdate(25, 22); 
    sDisplay();

    sReverse(); 
    sDisplay();

    sSort(); 
    sDisplay();

    // Stack
    push(5); 
    sDisplay();
    pop(); 
    sDisplay();
    printf("Stack top: %d\n", peek());

    // Queue
    enqueue(35); 
    sDisplay();
    dequeue(); 
    sDisplay();
    printf("Queue front: %d\n", front());

    // Doubly LL Example
    dInsertBegin(10); 
    dInsertEnd(30); 
    dInsertPos(20, 2);
    dDisplay();

    dUpdate(20, 25); 
    dDisplay();

    dReverse(); 
    dDisplay();

    dSort(); 
    dDisplay();

    dDeleteBegin(); 
    dDeleteEnd(); 
    dDisplay();

    return 0;
}
