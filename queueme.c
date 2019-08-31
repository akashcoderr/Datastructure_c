#include<stdio.h>
#include<conio.h>
int queue[10];
int front=-1;
int rear=-1;
int i;
void insert(int m){
	if(rear==9){
		printf("Queue Is Full\n");
	}else{
		if(front==-1){
			front=0;
			rear=0;
			queue[rear]=m;
		}else{
			rear++;
			queue[rear]=m;
		}
	}
}

int delete(){
	int m=-1;
	if(front==-1||front>rear){
		printf("Queue Is Empty\n");
	}else{
		m=queue[front];
		front++;
	}
	return m;
}
void print(){
	for(i=front;i<=rear;i++){
		printf(" %d ",queue[i]);
	}
}

void main(){
	insert(12);
	insert(15);
	insert(17);
	print();
	printf("deleted %d \n",delete());
	insert(42);
	insert(72);
	insert(22);
	print();
	printf("deleted %d \n",delete());
	print();
}
