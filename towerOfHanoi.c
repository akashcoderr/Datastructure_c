#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Thr Robust Coder 
//Tower Of Hanoi Problem
void towerOfHanoi(int n,char BEG,char AUX,char END){
	if(n>=1){
		towerOfHanoi(n-1,BEG,END,AUX);
		printf("%c to %c\n",BEG,END);
		towerOfHanoi(n-1,AUX,BEG,END);
	}
}
int totalMove(int n){
	int res=1,i;
	for(i=0;i<n;i++){
		res=res*2;
	}
	return res;
}
int main(){
	int disks;
	printf("Enter Number Of Disks\n");
	scanf("%d",&disks);
	printf("Tower Of Hanoi\n");
	towerOfHanoi(disks,'A','B','C');
	printf("Total Moves %d",totalMove(disks));
	return 0;
}
