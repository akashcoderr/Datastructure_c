#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
insert_pos(int a[],int *i){
	int pos,value,j,again;
	do{
		if(*i==9){
			printf("\nList Is Already Full\n");
		}else{
			printf("\nEnetr The Position To Insert:\n");
			scanf("%d",&pos);
			if(pos-1<=*i+1){
				printf("Enter Element:\n");
				scanf("%d",&value);
				for(j=*i;j>=pos-1;j--){
					a[j+1]=a[j];
				}
				a[pos-1]=value;
				++*i;
				again=0;
			}else{
				printf("Enter Specific Position ..");
				again=1;
			}
			
			
		}
	}while(again);
}
delete_pos(int a[],int *i){
	int j,pos,check=1,again;
	do{
		if(*i==-1){
			printf("Under Flow Error:");
		}else{
			printf("\nEnter Position For Delete:");
			scanf("%d",&pos);
		if(pos<=*i){
			printf("\nDeleted Element Is:%d \n",a[pos-1]);
			for(j=pos;j<=*i;j++){
			a[j-1]=a[j];
			check=0;
			
		}
		if(!check)
			--*i;
		again=0;
		}else{
			printf("Enter Specific Position ..");
			again=1;
		}
		
		}
	}while(again);
	
}
void travers(int a[],int *i){
	int j;
	if(*i==-1){
		printf("\nList Is Empty..\n");
	}else{
		printf("\nList Is:\n");
		for(j=0;j<=*i;j++){
			printf("%d ",a[j]);
		}
	}
}
void main(){
	int a[10],i=-1,choice,check=1;
	printf("\t\t\t\t****************************************\n");
	printf("\t\t\t\t1:Insert At Position\n");
	printf("\t\t\t\t2:Delete At Position\n");
	printf("\t\t\t\t3:Display List\n");
	printf("\t\t\t\t4:Exit\n");
	printf("\t\t\t\t****************************************\n");
	do{
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert_pos(a,&i);
				break;
			case 2:
				delete_pos(a,&i);
				break;
			case 3:
				travers(a,&i);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice..\n");
			}
		}while(check);
}






















