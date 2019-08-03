#include<stdio.h>
#include<conio.h>
void insert_beg(int a[],int *i){
	int j,m;
	if(*i==9){
		printf("\nOverflow Error\n");
	}else{
		for(j=*i;j>=0;j--){
			a[j+1]=a[j];
		}
		printf("\nEnetr Element:\n");
		scanf("%d",&m);
		++*i;
		a[0]=m;
		
	}
	
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
void delete_beg(int a[],int *i){
	int j;
	if(*i==-1){
		printf("Under Flow Error:");
	}else{
		printf("\nDeleted Element Is:%d \n",a[0]);
		for(j=1;j<=*i;j++){
			a[j-1]=a[j];
		}
		--*i;
	}
}
void main(){
	int a[10],i=-1;
	insert_beg(a,&i);
	insert_beg(a,&i);
	insert_beg(a,&i);
	insert_beg(a,&i);
	insert_beg(a,&i);
	insert_beg(a,&i);
	travers(a,&i);
	delete_beg(a,&i);
	delete_beg(a,&i);
	travers(a,&i);
	
}
