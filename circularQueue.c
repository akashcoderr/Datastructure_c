#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10
int q[max],front=-1,rear=-1;
void insert(){
	char x;
	if((front==0&&rear==max-1)||(rear+1==front)){
		printf("Queue Is Overflow\n");
	}else{
		printf("Enter Element to be insert:");
		scanf("%d",&x);
		if(rear==-1){
			front=0,rear=0;
		}else if(rear==max-1){
			rear=0;
		}else{
			rear++;	
		}
		q[rear]=x;
	}
}
void deleteQ(){
	int a;
	if(front==-1){
		printf("Queue Is Full\n");
	}else{
		a=q[front];
		if(front==rear){
			front=-1;
			rear=-1;	
		}else if(front==max-1){
			front=0;
		}else{
			front++;
		}
		printf("Deleted Element Is %d\n",a);
	}
}
void display(){
	int i,j;
	if(front==-1&&rear==-1){
		printf("Queue Is Underflow\n");
	}if(front>rear){
		for(i=front;i<max;i++){
			printf(" %d ",q[i]);
		}
		for(j=0;j<=rear;j++){
			printf(" %d ",q[j]);
		}
	}else{
		for(i=front;i<=rear;i++){
			printf(" %d ",q[i]);
		}
	}
	printf("\n");
}
void main(){
	int ch;
	printf("Circular Queue Operation\n");
	printf("1:Insert\n2:Delete:\n3:Display\n4:exit\n");
	while(1){
		printf("Enter Your Choice \n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				deleteQ();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice \n");
		}
	}
}
