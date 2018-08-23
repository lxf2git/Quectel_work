#include<stdio.h>
void rearrange(int a[]);

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	
	rearrange(a);
	return 0;
}

void rearrange(int a[])
{
	int begin,num;
	int acp[10]={0};
	int i,j=1;
	for(i=0;i<10;i++)
	{
		acp[i]=a[i];
	}
	printf("input 2 numbers(begin count)");
	scanf("%d%d",&begin,&num);
	if(begin+num>10)
	{
		printf("err!\n");
	}else 
	{
		for (i=begin-1;i<begin-1+num;i++,j++)
		{
			
			a[i]=acp[begin-1+num-j];
		}
		
		for(i=0;i<10;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return ;
	}
}


	

