#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100


int stack[MAX];
int top = -1;


void push(int value) {
    if (top >= MAX - 1) {
        printf("\n Stack Overflow");
        return ;
    }
    stack[++top] = value;
}


int pop() {
    if (top < 0) {
        printf("\nStack Underflow");
        return 0;
    }
    return stack[top--];
}


int evaluatePostfix(char* exp) {
    int i = 0;
    
    while (exp[i] != '\0') {
        
        if (exp[i] == ' ' || exp[i] == '\t') {
            i++;
            continue;
        }

       
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); 
        } 
       
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int val1 = pop(); 
            int val2 = pop(); 
            
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': 
                    if (val1 == 0) {
                        printf("\nError: Division by zero\n");
                        return 0;
                    }
                    push(val2 / val1); 
                    break;
            }
        } else {
            printf("\nError: Invalid character '%c' encountered\n", exp[i]);
            return 0;
        }
        i++;
    }
    
    int finalResult = pop();

   
    if (top != -1) {
        printf("\nError: Invalid Postfix Expression (Too many operands)\n");
        exit(1);
    }

    return finalResult;
}

int main() {
    char exp[MAX];   
    printf("Enter a postfix expression (e.g., 231*+9-): ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Evaluation Result: %d\n", result);
    
    return 0;
}