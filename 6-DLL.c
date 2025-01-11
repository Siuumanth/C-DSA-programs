#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 

struct node 
{ 
int data; 
struct node *llink; 
struct node *rlink; 
}; 
typedef struct node *NODE;

NODE insert_pos(NODE); 
NODE delete_pos(NODE); 
NODE delete_front(NODE); 
NODE insert_rear(NODE); 
void display(NODE); 
NODE getnode(); 
 
void main() 
{ 
 NODE first=NULL; 
 int option; 
 while(1) 
 { 
  printf("\nDoubly linked list operations\n"); 
  printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n"); 
  printf("Enter your choice: "); 
  scanf("%d",&option); 
  switch(option) 
  { 
   case 1: printf("1.Insert rear\n2.Insert position\nEnter your choice: "); 
    scanf("%d",&option); 
    switch(option) 
    { 
     case 1: first=insert_rear(first); 
     break; 
     case 2: first=insert_pos(first); 
     break; 
     default:printf("Invalid choice\n"); 
    } 
    break; 
   case 2: first=delete_pos(first); 
    break; 
   case 3: display(first); 
    break; 
   case 4: exit(0); 
   default: printf("Invalid choice\n"); 
  } 
 } 
} 

NODE getnode() 
{ 
 NODE temp; 
 temp=(NODE)malloc(sizeof(struct node)); 
 return temp; 
} 
 

NODE insert_pos(NODE start){
    int loc = 1,pos;
    NODE cur = getnode();
    NODE next = start->rlink;
    NODE prev = start;
    printf("enter item ");
    scanf("%d",&cur->data);
    printf("Enter position ");
    scanf("%d",&pos);
    NODE temp = start;
    while(next->rlink!=NULL && loc!=pos){
        prev = next;
        next = next->rlink;
        loc++;
    }
    prev->rlink = cur;
    cur->llink = prev;
    cur->rlink = next;
    next->llink = cur;
}

NODE delete_pos(NODE start){
    int loc = 1,pos;
    NODE next = start->rlink;
    NODE prev = start;
    printf("Enter position ");
    scanf("%d",&pos);
    NODE temp = start;
    while(next->rlink!=NULL && loc!=pos){
        prev = next;
        next = next->rlink;
        loc++;
    }
    prev->rlink = next->rlink;
    next->rlink->llink = prev;
    free(next);
    return start;
}

NODE delete_front(NODE start){
    NODE next = start->rlink;
    next->llink = NULL;
    free(start);
    return next;
}


NODE insert_rear(NODE start){
    NODE cur = getnode();
    NODE prev = start;
    printf("enter item ");
    scanf("%d",&cur->data);
    if(start==NULL){
        return cur;
    }

    NODE temp = start;
    while(prev->rlink!=NULL ){
        prev = prev->rlink;
    }
    prev->rlink = cur;
    cur->llink = prev;
    return start;
}

void display(NODE start){
    NODE temp; 
 if(start==NULL) 
  printf("No nodes\n"); 
 else 
 { 
  for(temp=start;temp->rlink!=NULL;temp=temp->rlink) 
    printf("%d<=>",temp->data); 
  printf("%d",temp->data); 
 } 
}

 