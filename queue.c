#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct ArrayQueue{
	int front,rear;
	int capacity;
	int *array;
};

struct ArrayQueue* createQueue(int cap){
	struct ArrayQueue* Q=malloc(sizeof(struct ArrayQueue));
	if(!Q){
		return NULL;
	}
	Q->capacity=cap;
	Q->front=Q->rear=-1;
	Q->array=malloc(Q->capacity*sizeof(int));
	if(!Q->array){
		return NULL;
	}
	return Q;
}

int isEmptyQueue(struct ArrayQueue *Q){
	return (Q->front==-1);
}

int isFullQueue(struct ArrayQueue *Q){
	return((Q->rear+1)%Q->capacity==Q->front);
}

int queueSize(struct ArrayQueue *Q){
	return((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}

void enQueue(struct ArrayQueue *Q,int data){
	if(isFullQueue(Q)){
		printf("Overflow\n");
	}else{
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=data;
		if(Q->front==-1){
			Q->front=Q->rear;
		}
	}
}


int deQueue(struct ArrayQueue *Q){
	int data=-1;
	if(isEmptyQueue(Q)){
		printf("Queue Is Empty");
		return -1;
	}else{
		data=Q->array[Q->front];
		if(Q->front==Q->rear){
			Q->front=Q->rear=-1;
		}else{
			Q->front=(Q->front+1)%Q->capacity;
		}
	}
	return data;
}




void deleteQueue(struct ArrayQueue *Q){
	if(Q){
		if(Q->array){
			free(Q->array);
		}
		free(Q);
	}
}

void displayQueue(struct ArrayQueue *Q){
	int i;
	if(Q->front==-1){
		printf("Queue Is Empty\n");
	}else{
		printf("Queue Is :");
		for(i=Q->front;i<=Q->rear;i++){
			printf(" %d ",Q->array[i]);
		}
	}
	printf("\n");
}
void main(){
	struct ArrayQueue *Q=createQueue(5);
	enQueue(Q,78);
	enQueue(Q,23);
	enQueue(Q,43);
	enQueue(Q,73);
	enQueue(Q,53);
	displayQueue(Q);
	printf("deleted element %d \n",deQueue(Q));
	displayQueue(Q);
}

















