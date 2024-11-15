#include<stdio.h>
void percentage(int num,int i){
	if (i>100){
		return;
	}
	else{
		int j=num*i/100;
		printf("%d percent of %d is : %d \n", i,num,j);
	}
percentage(num,i+1);
}
int main(void){
	printf("Enter a value to split in percentage:");
		int num;
	scanf("%d",&num);
	percentage(num,1);
	
}