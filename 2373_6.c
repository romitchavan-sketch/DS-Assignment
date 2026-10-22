#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow");
        return ;
    }
    stack[++top] = item;
}
char pop() {
    if (top == -1) {
       printf("Stack Underflow");
        return 0;
    }
    return stack[top--];
}
char peek() {
    if (top == -1) {
        printf("Stack Underflow");
        return 0;}
    return stack[top];
}
int Operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int precedence(char ch){
      if ( ch=='+' || ch=='-'){
          return 1; }
      else if(ch=='*'|| ch == '/'){
           return 2;}
       else if(ch=='^'){
            return 3;}
       return 0;
      }
void infixToPostfix(char infix[], char postfix[]){
    int i, j = 0;
    char c;
    top = -1;
    for(i = 0; infix[i] != '\0' ;i++){
           c = infix[i];
           if( isalnum(c)){
              c = postfix[j++];}
           else if( c == '(' ){
               push(c);}
           else if(c == ')' ){
                while(peek() != '(' ){
                       postfix[j++] = pop();}
                 pop();
            }
            else if(Operator(c)){
                   while(peek() != '(' && precedence(peek()) >= precedence(c)){
                           postfix[j++] = pop(); }
                   push(c);
                   }
       }
  }
void reverse(char str[]){
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void infixToPrefix(char infix[], char prefix[]){
    int i, j = 0;
    char c;
    reverse(infix);
    for(i = 0; infix[i] != '\0' ; i++){
           if(infix[i] =='(' ){
               infix[i] = ')';}
           else if(infix[i] == ')' ){
                infix[i] = '(' ;}
     }
     top = -1;
     for (i = 0; infix[i] != '\0'; i++){
        c = infix[i];
        if (isalnum(c)) {
            c=prefix[j++] ;
        }
        else if (c == '(' ){
            push(c);}
        else if(c == ')' ){
             while(peek() != '(' ){
                      prefix[j++] = pop();}
                 pop();
            }
        else if(Operator(c)){
                   while(peek() != '(' && precedence(peek()) >= precedence(c)){
                           prefix[j++] = pop(); }
                   push(c);
                   }
         }
          reverse(prefix);
 }
char strStack[MAX][MAX];
int strTop = -1;

void pushStr(char item[]) {
    if (strTop >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(strStack[++strTop], item);
}

void popStr(char result[]) {
    if (strTop == -1) {
        printf("Stack Underflow\n");
        result[0] = '\0';
        return;
    }
    strcpy(result, strStack[strTop--]);        
}
void postfixToInfix(char postfix[], char infix[]) {
    int i;
    char c;
    strTop = -1;
    char op1[MAX], op2[MAX], temp[MAX];
    
    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if (isalnum(c)) {
            char str[2] = {c, '\0'};
            pushStr(str);
        } else if (Operator(c)) {
            popStr(op2);
            popStr(op1);
            sprintf(temp, "(%s%c%s)", op1, c, op2);
            pushStr(temp);
        }
    }
    popStr(infix);
}


void prefixToInfix(char prefix[], char infix[]) {
    int i;
    char c;
    strTop = -1;
    char op1[MAX], op2[MAX], temp[MAX];
    int length = strlen(prefix);
    
   
    for (i = length - 1; i >= 0; i--) {
        c = prefix[i];
        if (isalnum(c)) {
            char str[2] = {c, '\0'};
            pushStr(str);
        } else if (Operator(c)) {
            popStr(op1);
            popStr(op2);
            sprintf(temp, "(%s%c%s)", op1, c, op2);
            pushStr(temp);
        }
    }
    popStr(infix);
}

void prefixToPostfix(char prefix[], char postfix[]) {
    int i;
    char c;
    strTop = -1;
    char op1[MAX], op2[MAX], temp[MAX];
    int length = strlen(prefix);
    for (i = length - 1; i >= 0; i--) {
        c = prefix[i];
        if (isalnum(c)) {
            char str[2] = {c, '\0'};
            pushStr(str);
        }

        else if (Operator(c)) {
            popStr(op1);
            popStr(op2);
            sprintf(temp, "%s%s%c", op1, op2, c);
            pushStr(temp);
        }
    }

    popStr(postfix);
}
void postfixToPrefix(char postfix[], char prefix[]) {
    int i;
    char c;
    strTop = -1;
    char op1[MAX], op2[MAX], temp[MAX];
    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if (isalnum(c)) {
            char str[2] = {c, '\0'};
            pushStr(str);
        }

        else if (Operator(c)) {
            popStr(op2);
            popStr(op1);
            sprintf(temp, "%c%s%s", c, op1, op2);
            pushStr(temp);
        }
    }

    popStr(prefix);
    }
int main(){
    int choice;
    char expression[MAX];
    char result[MAX];

    do
    {
        
        printf(" EXPRESSION CONVERSION\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Postfix to Infix\n");
        printf("4. Prefix to Infix\n");
       printf("5. Prefix to Postfix\n");
        printf("6. Postfix to Prefix\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nEnter Infix Expression: ");
                scanf("%s", expression);
                infixToPostfix(expression, result);
                printf("Postfix Expression: %s\n", result);
                break;

            case 2:
                printf("\nEnter Infix Expression: ");
                scanf("%s", expression);
                infixToPrefix(expression, result);
                printf("Prefix Expression: %s\n", result);
                break;

            case 3:
                printf("\nEnter Postfix Expression: ");
                scanf("%s", expression);
                postfixToInfix(expression, result);
                printf("Infix Expression: %s\n", result);
                break;

            case 4:
                printf("\nEnter Prefix Expression: ");
                scanf("%s", expression);
                prefixToInfix(expression, result);
                printf("Infix Expression: %s\n", result);
                break;

            case 5:
                printf("\nEnter Prefix Expression: ");
                scanf("%s", expression);
                prefixToPostfix(expression, result);
                printf("Postfix Expression: %s\n", result);
                break;

            case 6:
                printf("\nEnter Postfix Expression: ");
                scanf("%s", expression);
                postfixToPrefix(expression, result);
                printf("Prefix Expression: %s\n", result);
                break;

            case 7:
                printf("\nExiting program\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 7);

    return 0;}

