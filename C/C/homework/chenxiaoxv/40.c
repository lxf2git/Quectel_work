#include<stdio.h>
#include<stdlib.h>


void creat_memory(void **p,int size)
{

	*p=malloc(size);
	if(NULL==p)
	{
		printf("p:malloc error");
		exit(-1);
	}
}
void fan(int **p,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&p[i][j]);
		}
		
	}

}
void min(int **p,int r,int c)
{
	int i,j,min=**p,max=**p,m=0,n=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(min>=*(*(p+i)+j))
			{
				min=*(*(p+i)+j);
				m=i;
				n=j;
			}
		}
	}
	printf("min:%d\n",min);
 
 for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			
			
				if(max<=*(*(p+i)+j))
				{
					max=*(*(p+i)+j);
					
				}
			
		}	
	}

	int min2=max;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(*(*(p+m)+n)<*(*(p+i)+j))
			{
				if(min2>=*(*(p+i)+j))
				{
					min2=*(*(p+i)+j);
				}
			}
		}														
	}

	printf("%d",min2);
}	
int main()
{	
	int **p=NULL;
	int r,c,i,j;
	printf("input:");
	scanf("%d%d",&r,&c);
	creat_memory((void**)&p,r*sizeof(int));
	for(i=0;i<r;i++)
	{
		creat_memory((void**)(p+i),c*sizeof(int));
	}
	printf("inputnumber:");
	fan(p,r,c);
	min(p,r,c);
    return 0;
}





