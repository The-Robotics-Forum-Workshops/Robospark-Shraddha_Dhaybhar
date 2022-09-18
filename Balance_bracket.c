#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX 100


struct Stack { 
    int top; 
    int maxSize; 
    char* array; 
}; 

struct Stack* create(char max) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->maxSize = max; 
    stack->top = -1; 
    stack->array = (char*)malloc(stack->maxSize * sizeof(char));
    
    return stack; 
}

 
int isFull(struct Stack* stack) 
{ 
    if(stack->top == stack->maxSize - 1){
        printf("Will not be able to push maxSize reached\n");
    }
    
    return stack->top == stack->maxSize - 1; 
}


int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
}


void push(struct Stack* stack, char item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
}

 
void pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return; 
    
    stack->array[stack->top--]; 
} 


int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 

bool checkPair(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

bool checkBalanced(struct Stack* stack, char expr[], int len){
      
    for (int i = 0; i < len; i++)  
    { 
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')  
        {  
          push(stack, expr[i]); 
        } 
        else
        {
    
        if (isEmpty(stack)) 
            return false;
        else if(checkPair(peek(stack),expr[i]))
        {
            pop(stack);
            continue;
        }
        
        return false;
        }
    }    
    return true; 
}
int main() {
  char exp[MAX] = "({})[]";

  int len = strlen(exp);
  struct Stack* stack = create(len); 
  checkBalanced(stack, exp, len)?printf("Balanced"): printf("Not Balanced"); 

  return 0;
}