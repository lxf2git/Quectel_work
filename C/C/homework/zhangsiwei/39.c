#include<stdio.h>
#include<stdlib.h>

int min_2min(int **p,int h,int l)
{
	int min,min2,i,j;
	min =min2=10000;
	for(i=0;i<h;i++)
	{
		for(j=0;j<l;j++)
		{
			if(min>*(*(p+i)+j))
					min=*(*(p+i)+j);
		}
	}
	printf("min=%d\n",min);
	for(i=0;i<h;i++)
	{
		for(j=0;j<l;j++)
		{
			if(min2>*(*(p+i)+j)&&*(*(p+i)+j)!=min)
					min2=*(*(p+i)+j);
					printf("min2=%d",min2);
			
		}
	}
	return min2;
}
int main()
{	
	int **p,i,j,h,l,min;
	printf("please input 行   列：\n");
	scanf("%d%d",&h,&l);
	printf("please input :\n");
	p = (int **)malloc(h*sizeof(int *));
	for(i=0;i<h;i++)
	{
		*(p+i) = (int *)malloc(h*sizeof(int));
	}	
	for(i=0;i<h;i++)
	{
		for(j=0;j<l;j++)
		{
			scanf("%d",*(p+i)+j);		
		}
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<l;j++)
		{
			printf("%d",*(*(p+i)+j));		
		}
		printf("\n");
	}
	
	min = min_2min(p,h,l);
	printf("the scoend min is:%d\n",min);
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}

	return 0;
}
