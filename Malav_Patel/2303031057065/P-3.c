#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Structure to represent a stack
struct Stack {
char data;
struct Stack* next;
};
typedef struct Stack Stack;
// Function to initialize a new stack
Stack* createStack() {
return NULL;
}
// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
return stack == NULL;
}
// Function to push an element onto the stack
Stack* push(Stack* stack, char item) {
Stack* newNode = (Stack*)malloc(sizeof(Stack));
newNode->data = item;
newNode->next = stack;
return newNode;
}
// Function to pop an element from the stack
Stack* pop(Stack* stack) {
if (isEmpty(stack)) {

printf("Error: Trying to pop from an empty stack.\n");
exit(1);
}
Stack* temp = stack;
stack = stack->next;
free(temp);
return stack;
}
// Function to check if two characters are a matching pair
bool isMatchingPair(char char1, char char2) {
return (char1 == '(' && char2 == ')') ||
(char1 == '{' && char2 == '}') ||
(char1 == '[' && char2 == ']');
}
// Function to check if an expression has balanced pairs
bool isBalancedExpression(const char* expression) {
Stack* stack = createStack();
for (int i = 0; expression[i]; i++) {
if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
stack = push(stack, expression[i]);
} else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
if (isEmpty(stack)) {
return false;
}
if (!isMatchingPair(stack->data, expression[i])) {
return false;
}
stack = pop(stack);

}
}
return isEmpty(stack);
}
int main() {
char expression[100];
printf("Enter an expression: ");
scanf("%s", expression);
if (isBalancedExpression(expression)) {
printf("The expression is balanced.\n");
 printf("Malav Patel\n");
printf("230301057065");
} else {
printf("The expression is not balanced.\n");
}
return 0;
}
