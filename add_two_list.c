/*
Program to add to linked list
#therobustcoder
robustgithub@gmail.com
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *first=NULL,*second=NULL;
// first list insertion
void insert_in_first(){
	struct node *temp,*last;
	int value;
	last=first;
	temp=malloc(sizeof(struct node));
	printf("Enter Value Of Node: ");
	scanf("%d",&value);
	temp->data=value;
	temp->next=NULL;
	if(first==NULL){
		first=temp;		
	}else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=temp;
	}
}
void display(){
	struct node *temp1=first,*temp2=second;
	printf("First List:");
	while(temp1!=NULL){
		printf("%d  ",temp1->data);
		temp1=temp1->next;
	}
	printf("\n\n");
	printf("Second list:");
	while(temp2!=NULL){
		printf("%d  ",temp2->data);
		temp2=temp2->next;
	}
}
//second list Insertion
void insert_in_second(){
	struct node *temp,*last;
	int value;
	last=second;
	temp=malloc(sizeof(struct node));
	printf("Enter Value Of Node: ");
	scanf("%d",&value);
	temp->data=value;
	temp->next=NULL;
	if(second==NULL){
		second=temp;		
	}else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=temp;
	}
}
//merge lists
void add_list(){
	struct node *temp,*print;
	temp=first;
	if(first==NULL){
		printf("First List Is Empty..\n");
		first=second;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=second;
		printf("After Murging List:");
		print=first;
		while(print!=NULL){
			printf("%d  ",print->data);
			print=print->next;
		}
	}
}
void main(){
	int choice;
	printf("\t\t\t\t\t*******************Add Two List************************\n\n\n\n");
	printf("\t\t\t\t\t1:Insert Node In First List\n");
	printf("\t\t\t\t\t2:Insert Node In Second List\n");
	printf("\t\t\t\t\t3:Add List\n");
	printf("\t\t\t\t\t4:Display Lists\n");
	printf("\t\t\t\t\t5:Exit\n");
	do{
		printf("\nEnter Your Choice :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert_in_first();
				break;
			case 2:
				insert_in_second();
				break;
			case 3:
				add_list();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Choice....\n");
		}
	}while(1);
}
