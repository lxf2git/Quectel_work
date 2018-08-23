#include<stdio.h>
#include<stdlib.h>
#define N 4

int main()
{
	int i,j,input[N],flog=20,aim;
	printf("输入十个数：\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&input[i]);
	}
	printf("输入要找的数：\n");
	scanf("%d",&aim);
	for(j=0;j<N;j++)
	{
		if(input[j]==aim)
		{
			if(flog>j)
			{
				flog=j;
			}		
		
		}
	
	}
	printf("I LOVE%d %d\n",flog,j);
	if(flog==20)
	{
		printf("SORRY,not found!Vim\n");
		exit(0);
	}
	printf("你要找数的最小下标：%d\n",flog);
	return 0;
}
