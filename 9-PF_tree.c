#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct node {
    char data;  // Store as character since operands are variables
    struct node *lchild, *rchild;
};

typedef struct node *NODE;

NODE create_tree(char postfix[]);
float eval(NODE root);

int main() {
    char postfix[50];  // Increased size for longer expressions
    float result;
    
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    NODE root = create_tree(postfix);
    result = eval(root);
    
    printf("Result = %f\n", result);
    
    return 0;
}

NODE create_tree(char postfix[]) {
    NODE stack[20];
    int i = 0, j = 0;
    char symbol;

    for (i = 0; (symbol = postfix[i]) != '\0'; i++) {
        NODE temp = (NODE)malloc(sizeof(struct node));
        temp->lchild = temp->rchild = NULL;
        temp->data = symbol;

        if (isalnum(symbol)) {  // If it's an operand (variable)
            stack[j++] = temp;
        } else {  // If it's an operator
            temp->rchild = stack[--j];
            temp->lchild = stack[--j];
            stack[j++] = temp;
        }
    }
    return stack[--j];
}

float eval(NODE root) {
    float num;

    switch (root->data) {
        case '+': return eval(root->lchild) + eval(root->rchild);
        case '-': return eval(root->lchild) - eval(root->rchild);
        case '*': return eval(root->lchild) * eval(root->rchild);
        case '/': return eval(root->lchild) / eval(root->rchild);
        case '^': return pow(eval(root->lchild), eval(root->rchild));
        default:
            printf("Enter the value of %c: ", root->data);
            scanf("%f", &num);
            return num;  // Return the entered operand value
    }
}

