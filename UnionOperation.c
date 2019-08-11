#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main(){
	int a[10],b[10],c[20],i,val,j,n1,n2,check,k;
	//first set
		printf("Enter Size Of First Set:\n",k);
		scanf("%d",&n1);
		printf("Enter Elements In First Set:\n");
		for(i=0;i<n1;i++){
			scanf("%d",&val);
			if(i==0){
				a[i]=val;
			}else{
				for(j=0;j<=i;j++){
					check=0;
					if(a[j]==val){
						printf("Already Exist,Enter Again:\n");
						check=1;
						i--;
						break;
					}else{
						continue;
					}
				}
				if(!check){
					a[i]=val;
				}
			}
		}
		printf("A={");
		for(i=0;i<n1;i++){
			printf("%d",a[i]);
			if(i<n1-1)
			printf(",");
		}
		printf("}\n");
		//second set
	printf("Enter Size Of Second Set:\n",k);
		scanf("%d",&n2);
		printf("Enter Elements In Second Set:\n");
		for(i=0;i<n2;i++){
			scanf("%d",&val);
			if(i==0){
				b[i]=val;
			}else{
				for(j=0;j<=i;j++){
					check=0;
					if(b[j]==val){
						printf("Already Exist,Enter Again:\n");
						check=1;
						i--;
						break;
					}else{
						continue;
					}
				}
				if(!check){
					b[i]=val;
				}
			}
		}
		printf("B={");
		for(i=0;i<n2;i++){
			printf("%d",b[i]);
			if(i<n2-1)
			printf(",");
		}
		printf("}\n");
		//union of sets
		for(i=0;i<n1;i++){
		c[i]=a[i];
	}
		for(i=0;i<n2;i++){
		check=0;
		for(j=0;j<n2&&!check;j++){
			if(b[i]==a[j]){
				check=1;
			}	
		}
		if(!check){
				c[n1++]=b[i];
			}
	}
	printf("AUB={");
	for(i=0;i<n1;i++){
		printf("%d",c[i]);
		if(i<n1-1)
		printf(",");
	}
	printf("}");
}
