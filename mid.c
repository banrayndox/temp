#include <stdio.h> // input, output library
#include <stdlib.h> // for structure data type

struct Node{              // create structure data type 
int value;                // int value;
struct Node* next;        // for storing next node list
};


struct Node* Head = NULL;  // declare first node as null;

struct Node* createNode(int x){ 
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // dynamically node creating and stored into newNode;
newNode->value = x;                                                // then accessing newNode and assigning our value of newNode;
newNode->next = NULL;                                              // assigning NULL to newNode->next
return newNode;                                                    // returning newNode address
}


void insert_before(int x){              
struct Node* newNode = createNode(x);   // creating newNode;

if(Head==NULL) {                        // if there is no Node in our Linked List, our newNode become automatically first node;
    Head = newNode;
}
else{
newNode->next = Head;               // head become second , and newNode become first
Head = newNode;                     // updating our first node in global variable
}
}


void print(){
struct Node* temp = Head;                      // assigning first node to temporary variable
if(!temp) printf("There is no node\n");
while(temp){                                   // loop will run until the node exists
    printf("%d", temp->value);                 // print current node value
    
    if(temp->next) printf("->");               // if there Node->next true print '->' else print endline
    else printf("\n");
    
    temp = temp->next;                         // for(int i=0; i<n; i = i+1 ) ; == [     temp=temp->next ]      ] 

}
}

int main(){
print();  // NO node                                       
insert_before(5);
print();   // 5
insert_before(10);
insert_before(20);    
insert_before(40);
print(); // 40 -> 20 -> 10 -> 5 
return 0;
}
