#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//structure of node
struct node{
	int data;
	struct node *next;
};

//structure of list
struct linked_list{
	struct node *head;
};

struct node *start=NULL;
int count=0;

//insert at end
void insert_at_end(){
	struct node *temp,*last;
	int value;
	last=start;
	temp=malloc(sizeof(struct node));
	printf("Enter Value Of Node: ");
	scanf("%d",&value);
	temp->data=value;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
		count++;
	}else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=temp;
		count++;
	}
	
}

//insert at begining
void insert_at_beg(){
	struct node *temp;
	int value;
	temp=malloc(sizeof(struct node));
	printf("Enter Value Of Node: ");
	scanf("%d",&value);
	temp->data=value;
	if(start==NULL){
		start=temp;
		temp->next=NULL;
		count++;
	}else{
		temp->next=start;
		start=temp;
		count++;
	}
	
}
//insert at position
void insert_at_pos(){
	struct node *temp=start,*n,*l;
	n=malloc(sizeof(struct node));
	int i,pos,value;
	if(start==NULL){
		printf("List Is Empty");
	}
	else{
		printf("Enter Position:");
		scanf("%d",&pos);
		printf("\nEnter Value To Insert:");
		scanf("%d",&value);
		n->data=value;
		if(pos==1){
			n->next=temp;
			start=n;
			count++;
		}else{
			for(i=1;i<pos&&pos<=count+1;i++){
			l=temp;
			temp=temp->next;
		}
		l->next=n;
		n->next=temp;
		count++;
		}
		
	}
	
	
}
//delete at end
void delete_at_end(){
	struct node *last,*p;
	if(start==NULL){
		printf("\nList Is Empty\n");
	}else{
		last=start;
		while(last->next!=NULL){
			p=last;
			last=last->next;
		}
		printf("Deleted Element %d\n",last->data);
		p->next=NULL;
		free(last);
		count--;
	}

}
//delete at beg
void delete_at_beg(){
	struct node *temp;
	temp=start;
	if(start==NULL){
		printf("List Is Empty..\n");
	}else{
		start=temp->next;
		printf("Deletd Elment %d \n",temp->data);
		free(temp);
		count--;
	}

}
//delete at position
void delete_at_pos(){
	struct node *temp=start,*l;
	int pos,i;
	if(start==NULL){
		printf("List Is Empty\n");
	}else{
		printf("Enter Position To Delete:");
		scanf("%d",&pos);
		if(pos==1){
			start=temp->next;
			printf("Deleted Element %d\n",temp->data);
			free(temp);
			count--;
		}else{
			for(i=1;i<pos&&pos<=count;i++){
			l=temp;
			temp=temp->next;
		}
		l->next=temp->next;
		printf("Deleted Element %d\n",temp->data);
		free(temp);
		count--;
		}
		
	}
	
}
//display all Nodes
void traverse(){
	struct node *temp;
	temp=start;
	if(start==NULL){
		printf("List Is Empty\n");
	}
	else{
		while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
		}
	}
}
//find maximum
void find_max(){
	struct node *temp=start;
	int max=0;
	if(start==NULL){
		printf("List Is Empty..\n");
	}else{
		while(temp!=NULL){
			if(temp->data>max){
				max=temp->data;
			}
			temp=temp->next;
		}
		printf("Largest Elemet Is %d \n",max);
	}
}
//find minimum
void find_min(){
	struct node *temp=start;
	if(start==NULL){
		printf("List Is Empty..\n");
	}else{
		int min=start->data;
		while(temp!=NULL){
			if(temp->data<min){
				min=temp->data;
			}
			temp=temp->next;
		}
		printf("Smallest Elemet Is %d \n",min);
	}
}
//find specific value
void find_val(){
	int val,posi=0,check=0;;
	struct node *temp=start;
	if(start==NULL){
		printf("List Is Empty..\n");
	}else{
		printf("Enter Value For Search:");
		scanf("%d",&val);
		while(temp!=NULL){
			posi++;
			if(temp->data==val){
				printf("Value Find At %d Position..\n",posi);
				check=1;
			}
			temp=temp->next;
		}
		if(!check){
			printf("Element Not Found In List..\n");
		}
	}
}
//add two list
void count_node(){
	printf(" Number Of Nodes Is %d ",count);
}
//main method




void main(){
	int choice,check=1;
	printf("\n\n\n\t\t\t************************Singly Linked List Operation****************************\n");
	printf("\t\t\t1: Insert At End\n");
	printf("\t\t\t2: Insert At Begining\n");
	printf("\t\t\t3: Insert At Position\n");
	printf("\t\t\t4: Delete At End\n");
	printf("\t\t\t5: Delete At Begining\n");
	printf("\t\t\t6: Delete At position\n");
	printf("\t\t\t7: Show All Elements In List\n");
	printf("\t\t\t8: Find Maximum Value In List\n");
	printf("\t\t\t9: Find Minimum Value In List\n");
	printf("\t\t\t10: Find Specific Value In List \n");
	printf("\t\t\t11: Count Nodes In LIst..\n");
	printf("\t\t\t12: Exit\n");
	printf("\t\t\t**********************************************************************************\n");
	do{
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert_at_end();
				break;
			case 2:
				insert_at_beg();
				break;
			case 3:
				insert_at_pos();
				break;
			case 4:
				delete_at_end();
				break;
			case 5:
				delete_at_beg();
				break;
			case 6:
				delete_at_pos();
				break;
			case 7:
				traverse();
				break;
			case 8:
				find_max();
				break;
			case 9:
				find_min();
				break;
			case 10:
				find_val();
				break;
			case 11:
				count_node();
				break;
			case 12:
				exit(0);
			default:
				printf("Invalid Choice..\n");
			}
		}while(check);
	
}
