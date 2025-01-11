#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

int stack[10];
int push(int);
int pop(int);
void display(int);

void main()
{
    int top = -1;
    int option;
    while(1)
    {
        printf("\nStack operations\n");
        printf("1. Push 2. Pop 3.display 4. exit");
        printf("\nEnter your choice ");
        scanf("%d",&option);
        switch(option)
        {
            case 1 : top = push(top);
            break;
            case 2 : top = pop(top);
            break;
            case 3 : display(top);
            break;
            case 4 : exit(0);
            default: printf("Invalid choice ");
        }
    }
}

int push(int top)
{
    if(top == 9) 
    {
      printf("stack is full \n");
      return 0;
    }
    else{
        printf("enter item  ");
        int item;
        scanf("%d",&item);
        top++;
        stack[top] = item;
        printf("Item is succesfully inserted");
        return top;
    }
}


int pop(int top)
{
    if(top == -1) 
    {
        printf("Stack is empty ");
        return 0;
    }
    top --;
    return top;
}

void display(int top){
   printf(" Status of stack \n");
   for(int i = top; i!=-1; i--){
    printf("%d : ", stack[i]);
   }
}