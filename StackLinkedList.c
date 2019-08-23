#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node {
	int info;
	struct node *next;
};

struct node* create_node(){
	struct node *n=malloc(sizeof(struct node));
	return n;
}

void push(struct node **s,int item){
	struct node *n=create_node();
	if(n!=NULL){
		n->info=item;
		n->next=*s;
		*s=n;
	}
}

int peek(struct node **s){
	if(*s==NULL){
		printf("Stack Is Empty\n");
		return;
	}else{
		return ((*s)->info);
	}
}

int pop(struct node **s){
	int item;
	struct node *r;
	if(*s==NULL){
		printf("Stack UnderFlow\n");
		return;
	}else{
		item=(*s)->info;
		r=*s;
		*s=r->next;
		free(r);
	}
	return item;
}

void remove_stack(struct node **s){
	while(*s!=NULL){
		pop(s);
	}
}


main(){
	struct node *stack;
	push(&stack,19);
	push(&stack,49);
	push(&stack,69);
	push(&stack,39);
	push(&stack,59);
	push(&stack,29);
	printf(" %d \n",pop(&stack));
	printf(" %d \n",peek(&stack));
	printf(" %d \n",peek(&stack));
	remove_stack(&stack);
	
}


