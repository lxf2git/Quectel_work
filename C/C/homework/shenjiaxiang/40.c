#include<stdio.h>
#include<stdlib.h>

void get_memory(void **p,int size)
{
	*p=malloc(size);
}
int sort(int **p,int r,int c)
{
	int i,j,*arry,temp;
	get_memory((void **)&arry,r*c*sizeof(int));
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			*(arry+i*c+j)=*(*(p+i)+j);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=i;j<r*c-1;j++)
		{
			if(*(arry+j)<*(arry+j+1))
			{
				temp = *(arry+j+1);
				*(arry+j+1) = *(arry+j);
				*(arry+j) = temp;
			}
		}
	}
	for(i=0;i<r*c;i++)
	{
		printf("%d ",*(arry+i));
	}
	return *(arry+r*c-1-1);
//	return 0;
}
int main()
{
	int i,j,r,c;
	int **p=NULL;
	printf("input hang and lie\n");
	scanf("%d%d",&r,&c);
	get_memory((void **)&p,r*sizeof(int *));
	if(NULL==p)
	{
			printf("p:error");
			exit(-1);
	}
	for(i=0;i<r;i++)
	{
		get_memory((void **)(p+i),c*sizeof(int));
		if(NULL==*(p+i))
		{
			printf("*p:error");
			exit(-1);
		}
	}
	for(i=0;i<r;i++)
	{	
		for(j=0;j<c;j++)
		{
			scanf("%d",*(p+i)+j);
		}
	}
	printf("min=%d\n",sort(p,r,c));

	for(i=0;i<r;i++)
	{
		free(*(p+i));
		*(p+i)=NULL;
	}
	free(p);
	p=NULL;
}
