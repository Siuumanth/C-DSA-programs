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
NODE delete_front(NODE); 
NODE delete_rear(NODE); 
NODE getnode(); 
void display(NODE); 
 
 
void main() 
{ 
 NODE head; 
 int option; 
 head=getnode(); 
 head->link=head; 
 while(1) 
 { 
  printf("\nCircular linked list operations\n"); 
  printf("1.Insert to rear\n2.Insert to front\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n"); 
  printf("Enter your choice: "); 
  scanf("%d",&option); 
  switch(option) 
  { 
   case 1: head=insert_rear(head); 
    break; 
   case 2: head=insert_front(head); 
    break; 
   case 3: head=delete_front(head); 
    break; 
   case 4: head=delete_rear(head); 
    break; 
   case 5: display(head); 
    break; 
   case 6: exit(0); 
   default: printf("Invalid choice\n"); 
  } 
 } 
} 
 
NODE getnode() 
{ 
 NODE temp; 
 temp=(NODE)malloc(sizeof(struct node));
 temp->link=temp; 
 return temp; 
}

NODE insert_rear(NODE head){
   NODE cur = getnode();
   printf("enter element");
   scanf("%d",&cur->data);
   if(head == NULL){
      cur->link = cur;
      return cur ;
   }
   NODE temp = head;
   while(temp->link!=head){
    temp = temp -> link;
   }
   temp->link = cur;
   cur->link = head;
   printf("inserted");
   return head;
}

NODE insert_front(NODE head) 
{ 
 NODE temp; 
 temp=getnode(); 
 printf("Enter the data: "); 
 scanf("%d",&temp->data); 
 printf("%d is successfully inserted\n",temp->data); 
 temp->link=head->link; 
 head->link=temp; 
 return head; 
} 
NODE delete_front(NODE head){

} 

NODE delete_rear(NODE head){

}

void display(NODE head){

}