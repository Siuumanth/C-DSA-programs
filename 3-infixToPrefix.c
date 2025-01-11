#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h>
#include<string.h>

void infixtopostfix();
int precedance(char);
void push(char);
char pop();

char infix[20] ="A+B*(C-D)";
char postfix[20],stack[20];
int top = -1;
int j = 0;

void main(){
    printf("Original expression : %s\n", infix);
    int n = strlen(infix) - 1;
    int i;
    char temp;
    for(i =0; i <=n/2 ; i++){
        temp = infix[i] ;
        infix[i] = infix[n-i];
        infix[n-i] = temp;
    }
    for(i =0; i <=n ; i++){
        int ch = infix[i];
        if(ch == '(') infix[i] = ')';
        else if( ch == ')') infix[i] = '(';
    }
    printf("reversed expression : %s\n", infix);
    infixtopostfix();
    printf("prefix is  %s\n",postfix);
}

void infixtopostfix(){
    int n = strlen(infix) - 1;
    char temp;
    for(int i =0; i <=n ; i++){
        char ch = infix[i];
        switch(ch){
            case '(': push(ch);break;
            case ')' : 
                temp = pop();
                while(temp!='('){
                    postfix[j++] = temp;
                    temp = pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(precedance(stack[top]) >= precedance(ch)){
                    temp = pop();
                    postfix[j++] = temp;
                }
                push(ch);
                break;

            default: 
            postfix[j++] = ch;
            break;
        }
    }
    while(top!=-1){
            postfix[j++]=pop(); 
    }
}

void push(char ch){
    top++;
    stack[top] = ch;
}

char pop() 
{ 
   char temp; 
   temp=stack[top--]; 
   return temp; 
} 

int precedance(char ch){
    switch(ch){
        case '^': return 3;
        case '/':
        case'*': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case ')': return 0;
    }
}