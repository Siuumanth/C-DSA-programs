 
#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 

struct node 
{ 
 int data; 
 struct node *link; 
}; 
typedef struct node *NODE; 
 
NODE insert_rear(NODE); 
NODE insert_front(NODE); 
NODE delete_rear(NODE); 
NODE delete_front(NODE); 
NODE getnode(); 
void display(NODE); 
 
void main() 
{ 
 NODE first=NULL; 
 int option; 
 while(1) 
 { 
  printf("\nDouble ended queue operations\n"); 
  printf("1.Entry restricted queue\n2.Exit restricted queue\n3.Display\n4.Exit\n"); 
  printf("Enter your choice: "); 
  scanf("%d",&option); 
  switch(option) 
  { 
   case 1: printf("\nEntry restricted operations\n"); 
   printf("1.Insert rear \n2.Delete from front\n3.Delete from rear\n"); 
   printf("Enter your choice: "); 
   scanf("%d",&option); 
   switch(option) 
   { 
    case 1: first=insert_rear(first); 
    break; 
    case 2: first=delete_front(first); 
    break; 
    case 3: first=delete_rear(first); 
    break; 
    default: printf("Invalid choice\n"); 
   } 
   break; 
   case 2: printf("\nExit restricted operations\n"); 
   printf("1.Delete front \n2.Insert from front\n3.Insert from rear\n"); 
   printf("Enter your choice: "); 
   scanf("%d",&option); 
   switch(option) 
   { 
    case 1: first=delete_front(first); 
    break; 
    case 2: first=insert_front(first); 
    break; 
    case 3: first=insert_rear(first); 
    break; 
    default: printf("Invalid choice\n"); 
   } 
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
 temp->link=NULL;
 return temp; 
} 


NODE insert_rear(NODE start){
   NODE cur= getnode();
   NODE temp = start;
   int item;
   printf("Enter element ");
   scanf("%d",&item);
   cur->data = item;
   if( start == NULL){ 
         return cur;
   }
   while(temp->link!=NULL){
    temp=temp->link;
   }
   temp->link=cur;
   printf("Inserted rear");
   return start;
}



NODE insert_front(NODE start){
   NODE cur = getnode();
   int item = 23;
   printf("inserted front ");
   cur->data = item;
   cur->link = start;
   return cur;
}


NODE delete_rear(NODE start){
   NODE cur= getnode(),prev= getnode();
   int item;
   while(cur->link!=NULL){
    cur=cur->link;
    prev = cur;
   }
   prev->link=NULL;
   printf("deleted rear");
   free(cur);
   return start;
}


NODE delete_front(NODE start){
    NODE cur;
    cur=start;
   start = start->link;
   free(cur);
   return start;
}


void display(NODE start){
    while(start!=NULL){
        printf("%d<=>",start->data);
        start = start->link;

    }
}