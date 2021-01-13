#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

struct node {
	int data;
	struct node* next;
};
typedef struct node node;

typedef struct{
	int cnt;
	node* top;
} stack;

void push(stack*, int);
int pop(stack*);
void print_stack(stack*);
void initialize(stack*);

int main(){
	stack s;
	initialize(&s);

	push(&s, 1);
	push(&s, 3);
	push(&s, 5);
	push(&s, 7);

	print_stack(&s);

	return 0;
}

void push(stack* stk, int data){
	node* p;
	p = malloc(sizeof(node));
	p -> data = data;
	p -> next = stk -> top;
	stk -> top = p;
	(stk -> cnt)++;
}

int pop(stack* stk){
	node* p = stk -> top;
	int retValue = p -> data;
	stk -> top = p -> next;
	(stk -> cnt)--;
	free(p);
	return retValue;
}

void print_stack(stack* stk){
	while(stk -> cnt != 0){
		printf("%d\n", pop(stk));
	}
}

void initialize(stack* stk){
	stk -> cnt = 0;
	stk -> top = NULL;
}