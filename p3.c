#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
	int data;
	struct node*next;
};
void pop(struct node **);
void traverse(struct node *);
int top(struct node *);
int isEmpty(struct node * );
void push(struct node **,int value);
int main(){
	struct node * stack = NULL;
	printf("isEmpty = %d\n",isEmpty(stack));

	push(&stack,10);
	push(&stack,22);
	push(&stack,298);
	push(&stack,23);

	printf("%d popped from stack\n", top(stack));
	pop(&stack);

	printf("isEmpty = %d\n",isEmpty(stack));

	printf("%d is at top of the stack\n",top(stack));
	printf("Elements in stack : ");
	traverse(stack);
	return 0;
}
void pop(struct node ** stack){
	if(isEmpty(*stack)){
		printf("Stack is empty\n");
		return;
	}
	struct node * temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
void traverse(struct node * top){
	while(top){
		printf("%d ",top->data);
		top = top->next;
	}
	printf("\n");
}
int top(struct node * top){
	if(top == NULL){
		printf("Stack is empty\n");
		return INT_MIN;
	}
	return top->data;
}
int isEmpty(struct node * top){
	return top == NULL;
}
void push(struct node ** stack, int value){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->next = *stack;
	*stack = newNode;
	printf("%d pushed to stack\n", value);
}
