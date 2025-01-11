#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h>
#define SIZE 3 
int rear=-1,front=-1,q[20]; 


void qinsert();
void qdelete();
void qdisplay();


void main() 
{ 
 int ch=1,option; 
 while(1) 
 { 
    printf("Queue operations\n"); 
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n"); 
    printf("Enter your choice:"); 
    scanf("%d",&option); 
    switch(option) 
    { 
 case 1:qinsert(); 
        getch(); 
        break; 
 case 2:qdelete(); 
        getch(); 
        break; 
 case 3:qdisplay(); 
        getch(); 
        break; 
 case 4:exit(0); 
 default:printf("invalid choice\n"); 
 break; 
   } 
 } 
} 

void qinsert(){
    if(front == SIZE -1 ){
       printf("The queue is full");
       return;
    }
    int item;
    front++;
    printf("Enter the number ");
    scanf("%d",&item);
    q[front] = item;
    printf("Inserted");
    return;
}


void qdelete(){
    rear++;
    printf("Deleted");
}

void qdisplay(){
    for(int i = rear; i <= front ; i++){
        printf("%d \n",q[i]);
    }
    return;
}