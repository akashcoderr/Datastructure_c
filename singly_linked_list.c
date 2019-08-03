#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;


typedef struct linked_list{
	struct node *head;
}linked_list;

node* new_node(int data){
	node *z;
	z=malloc(sizeof(struct node));
	z->data=data;
	z->next=NULL;
	return z;
}

linked_list* new_linked_list(int data){
	node *a;
	a=new_node(data);
	linked_list *l=malloc(sizeof(struct linked_list));
	l->head=a;
	return l;
}

void traversal (linked_list *l){
	node *temp=l->head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void insert_at_beginning(linked_list *l,node *n){
	n->next=l->head;
	l->head=n;
}

void insert_at_last(linked_list *l,node *n){
	node *temp=l->head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}

void insert_node_after(node *n,node *a){
	n->next=a->next;
	a->next=n;
}

void delete_node(linked_list *l,node *n){
	node *temp=l->head;
	if(temp==n){
		l->head=n->next;
		free(n);
	}else{
		while(temp!=NULL){
			if(temp->next==n){
				temp->next=n->next;
				free(n);
				break;
			}
			temp=temp->next;
		}
	}
}

int main(){
	linked_list *l=new_linked_list(10);
	node *a, *b, *c; 
	a = new_node(20);
  	b = new_node(50);
  	c = new_node(60);
  	l->head->next = a;
  	a->next = b;
  	b->next = c;
  	traversal(l);
  	node *z;
  	z = new_node(0);
  	insert_at_beginning(l, z);
  	z = new_node(-10);
  	insert_at_beginning(l, z);

  	z = new_node(100);
  	insert_at_last(l, z);

  	z = new_node(30);
  	insert_node_after(z, a);
  	z = new_node(40);
  	insert_node_after(z, a->next);
  	z = new_node(500);
  	insert_node_after(z, a->next->next);

  	traversal(l);

  	delete_node(l, l->head);
  	delete_node(l, z);
  	traversal(l);
	
  	return 0;

}



























