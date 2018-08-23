#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **p=NULL;
	int r,c,i,j;
	printf("输入行和列");
	scanf("%d%d",&r,&c);
	p=(int**)malloc(r*sizeof(int*));
	if(NULL==p)
	{
		printf("p:malloc error");
		exit(0);
	}
	for(i=0;i<r;i++)
	{
		*(p+i)=(int*)malloc(c*sizeof(int));
		if(NULL==*(p+i))
		{
			printf("p+i:malloc error");
			exit(0);
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",*(p+i)+j);
			 **p=**p<*(*(p+i)+j)?**p:*(*(p+i)+j);
		}
	}
		**p=9999999999;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			 **p=**p<*(*(p+i)+j)?**p:*(*(p+i)+j);
		}
	}
		printf("第二小的数为：%d", **p);	
		








	return 0;
}
