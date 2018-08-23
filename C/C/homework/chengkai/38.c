#include<stdio.h>
int main()
{
	int i,j,num,n;

	scanf("%d,%d",&num,&n);

	for(i=1;i<n;i++){
		
		num*=num;	
	}
			
	printf("%d\n",num = num%1000);	
		
	return 0;		
}
