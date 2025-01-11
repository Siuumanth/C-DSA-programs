#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};

typedef struct node* node_ptr;

node_ptr create_node(int data){
    node_ptr temp;
    temp = (struct node*)malloc(sizeof(struct node));  //getting a pointerof struct node malloc returns a null pointer but we type caste it to a struct node
    if(temp==NULL){
    printf("NO memory");
    return NULL;
    }  
    else{
        temp->data=data;
        temp->link=NULL;
        return temp;
    }
}

node_ptr insert_rear(node_ptr start,int data){
   node_ptr prev,cur;
   if(start==NULL){
   printf("%d has been successfully inserted into the empty list \n ", data);
   return create_node(data);
   }
   cur = create_node(data);
   prev = start;
   while(prev->link!=NULL){
    prev = prev->link;
   }
   if(prev->link == NULL){
    prev->link = cur;
    printf("%d has been successfully inserted \n ", data);
    return start;
   }
}

void display(node_ptr start){
    node_ptr cur = start;
    printf("The values are : \n");
    while(cur!=NULL){
    printf("%d=>",cur->data);
    cur = cur->link;
    }
    printf("NULL \n");
}

int main(){
    node_ptr start= NULL;
    while(1){
    printf("Enter 1 to add element or 2 to display list  ");
    int ch;
    scanf("%d",&ch);
 
    switch(ch){
    case 1 : 
        printf("enter the element  ");
        int num;
        scanf("%d",&num);
        start = insert_rear(start,num);
        break;
    case 2:
    display(start);
    default:
        break;
    }
    }
    return 0;
}