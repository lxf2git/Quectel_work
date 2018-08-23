#include<stdio.h> 
#include<stdlib.h>
int main() 
{
		int r,c,i,j,labi,labj,min=99999;
		scanf("%d%d",&r,&c);
		int **p = NULL;
		p = (int **)malloc(r*sizeof(int **));
		for(i=0;i<r;i++)
		{
				*(p+i) = (int *)malloc(c*sizeof(int *));
		}
		for(i=0;i<r;i++)
		{
				for(j=0;j<c;j++)
				{
						scanf("%d",*(p+i)+j);
						if(min>*(*(p+i)+j))
						{
								min=*(*(p+i)+j);
								labi = i;
								labj = j;
						}
				}
		}
		*(*(p+labi)+labj)=999999;
		printf("%d %d\n",labi,labj);
		for(i=0;i<r;i++)
		{
				for(j=0;j<c;j++)
				{
						**p=**p<*(*(p+i)+j)?**p:*(*(p+i)+j);
				}
		}
		printf("第二小值：%d\n",**p);
}
