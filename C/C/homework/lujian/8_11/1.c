#include<stdio.h> 
#include<stdlib.h>
  
void creat(void**p, int size);
int input(int **p);
int count_sec_min(int** p);
//int myfree(int**p);
int r, c;
int main() 
{
	int** p=NULL;
	int i=0;
	printf("please input  r c\n");
   	scanf("%d%d",&r, &c);

	creat((void**)&p, r*sizeof(*p));
	
	for (i=0; i<r; i++)
	{
	creat((void**)p+i, c*sizeof(**p));
		if (NULL == *(p+i))
		{
				i--;
				continue ;
				
		}
		
	}
	
	input(p);

	count_sec_min(p);

//	my_free(p);
for (i=0; i<r; i++)
{	
	if (NULL !=p)
	{
	free(*(p+i));
	*(p+i) = NULL;
	}
}
	free(p);
 	return 0; 
}

void creat(void**p, int size)
{
	*p = malloc(size);
	if (NULL == *p)
	{
		printf("malloc error!");  
		
	}
}
int input(int **p)
{
	int i=0, j=0; 
	printf("please input %d *%d \n", r, c); 
	for (i=0; i<r; i++)
	{
	
		for (j=0; j<c; j++)
		{
		
			scanf("%d",(*(p+i)+j)); 
		
		}
	
	}
		return 0; 
}

int count_sec_min(int** p)
{
	 int i= 0, j= 0, k =0, m=0,temp=0, tmp;

	 	temp = **p;

		for (i = 0; i<r; i++)
		{

			for (j =0; j<c; j++)
			{	
				if (**p >*(*(p+i)+j))
				{
					**p = *(*(p+i)+j);
					k=i;
					m=j;					
				}
			}
		}
		**p = temp;
		tmp = *(*(p+k)+m);
		 *(*(p+k)+m) = *(*(p+r-1)+c-1);
		*(*(p+r-1)+c-1) = tmp;
	
		for (i = 0; i<r; i++)
		{

			for (j =0; j<c; j++)
			{	
				if(i==r-1 && j==c-1)
						continue;
				if (**p >*(*(p+i)+j))
				{
					**p = *(*(p+i)+j);	
				}
				
			}
		}
		
		printf("min_second = %d \n", **p); 

}
/*
int my_free(int**p)
{	
	int i =0; 
	for (i=0;i<r; i++)
	{
		if (*(p+i) !=NULL)
		{
			free(*(p+i));
			*(p+i) =NULL;
		}
	
	}
	if (p!=NULL)
	{
	free(p);
	p = NULL;
	}
	return 0; 
}
*/


























