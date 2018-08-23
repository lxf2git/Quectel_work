#include<stdio.h>
#include<stdlib.h>
void memory(void **p,int size);
void input(int *p,int a);
void output(int *p,int a);
void max(int *p,int a);
int main()
{
	int row,col,i;
	int **p=NULL;
	printf("输入数组行和列：\n");
	scanf("%d%d",&row,&col);
	memory((void **)&p,row*sizeof(int *)); 
	if(p==NULL)
	{
		printf("ERROR!\n");
		exit(-1);
	}
	for(i=0;i<row;i++)
	{
		memory((void **)p+i,col*sizeof(int));
		if(*p+i==NULL)
		{
			printf("error!\n");
			exit(-1);
		}
	}
	printf("输入%d个数\n",row*col);
	input(&**p,row*col);
//	output(&**p,row*col);
	max(*p,row*col);
	return 0;
}
void memory(void **p,int size)
{
	*p=malloc(size);
}
void input(int *p,int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		scanf("%d",&*(p+i));
	}
}
void output(int *p,int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		printf("SHU:%d ",*(p+i));
	}
	printf("\n");
}
void max(int *p,int a)
{
	int i,j;
	int max=0;
	int *p_data=NULL;
	memory((void **)&p_data,a*sizeof(int));
	for(i=1;i<a;i++)
	{	
		for(j=0;j<a;j++)
		{
			if(*(p+j+1)>*(p+j))
			{
				max=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=max;
			}
		}
	}
	printf("第二大的数是:%d\n",*(p+1));
}
