#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next; 
           };

struct Node* head = NULL;

struct Node* createNode(int x){
struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));       
newNode->value = x;
newNode->next = NULL;
return newNode;
};


void insertion_at_begining(int x){
     struct Node* newNode = createNode(x); 
    
     newNode->next = head;
     head = newNode;
};
void delete_at_head(){
  if(!head){
      printf("Node faka madachod\n");
 
  }else{  
  struct Node* temp = head;
  head = head->next;
  free(temp);
  }
};

void display(){
struct Node* current = head;
while(current){
printf("%d ->", current->value);
current = current->next;
}
printf("\n");

};

void insert_at_end(int x){
 struct Node* newNode = createNode(x); 
if(!head) { head  = newNode; return; }
struct Node* current = head;
while(current->next){
current = current->next;
}
current->next = newNode;

};



int main(){
insertion_at_begining(5);
insertion_at_begining(10);
insertion_at_begining(15);
display();
insert_at_end(15);
insert_at_end(10);
insert_at_end(5);
display();
return 0;
};

