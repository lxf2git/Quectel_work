#include<stdio.h>
#define N 10
int main()
{
	int i,flag=0;	
	int a[N],max;

	printf("please input integer:\n");
	
	scanf("%d",&a[0]);
	max = a[0]; 

	for(i=1;i<N;i++)
	{
		scanf("%d",&a[i]);
		if(max<a[i])
		{
			max = a[i];
			flag = i;
		}
	}
	printf("max:%d flag:%d\n",max,flag);

/*
	for(i=0;i<N;i++)
	{
		printf("*%d\n",a[i]);
	}	

*/
	return 0;
}
