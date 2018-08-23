#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 2
void find_min(int **p);
void input(int **p);
void create_memory(void **p,int n);
void myfree(int **p);

int main()
{
	int i;
    int **p=NULL;
	create_memory((void**)&p,ROW);
	for(i=0;i < ROW;i++)
	{
		create_memory((void **)(p+i),COL);
	}

	input(p);
	find_min(p);
	myfree(p);

	return 0;
}

void create_memory(void **p,int n)
{
	*p=malloc(n*sizeof(int *));
	if(NULL == *p)
	{
		printf("malloc err\n");
		exit(-1);
	}
}

void find_min(int **p)
{
	int min,max,i,k,tempi=0,tempk=0;
	min=**p;
	max=**p;
	for(i = 0;i < ROW;i++)
	{
		for(k = 0;k < COL;k++)
		{
			if( min > *(*(p+i)+k) )
			{
				tempi = i;
				tempk = k;
				min = *(*(p+i)+k); 
			}
			if( max < *(*(p+i)+k) )
			{
				max = *(*(p+i)+k); 
			}
		}
	}
	*(*(p+tempi)+tempk) = max;
	min = **p;
	for(i = 0;i < ROW;i++)
	{
		for(k = 0;k < COL;k++)
		{
			if( min > *(*(p+i)+k) )
			{
				min = *(*(p+i)+k); 
			}
		}
	}	
	printf("2rd min is:%d\n",min);
}



void input(int **p)
{
	int i,k;
	for (i=0;i < ROW;i++)
	{
		for (k=0;k < COL;k++)
		{
			if(NULL == p)
			{
				printf("error !");
				exit(-1);
			}else
			{
				scanf("%d",*(p+i)+k);
			}
		}
	}
}

void myfree(int **p)
{
	int i;
	if(NULL != p)
	{
	
		for(i=0;i < COL;i++)
		{
			
			if(NULL == *(p+i))
			{
				free(*(p+i));
			}
		
		}
		free(p);
	}
}
