#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void main(){
	int i,n=5,check,j;
	int set_1[5]={2,4,7,6,3};
	int set_2[5]={3,6,4,8,9};
	int result[10];
	//first set
	printf("A={");
	for(i=0;i<5;i++){
		printf("%d",set_1[i]);
		if(i<4)
		printf(",");
	}
	printf("}\n");
	//second set
	printf("B={");
	for(i=0;i<5;i++){
		printf("%d",set_2[i]);
		if(i<4)
		printf(",");
	}
	printf("}\n");
	//union of sets
	for(i=0;i<5;i++){
		result[i]=set_1[i];
	}
	for(i=0;i<5;i++){
		check=0;
		for(j=0;j<5&&!check;j++){
			if(set_2[i]==set_1[j]){
				check=1;
			}	
		}
		if(!check){
				result[n++]=set_2[i];
			}
	}
	printf("AUB={");
	for(i=0;i<n;i++){
		printf("%d",result[i]);
		if(i<n-1)
		printf(",");
	}
	printf("}");
}
