#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define R 3
#define C 2
void creat_memory(void **q,int size)
{
		*q = malloc(size);
		if(NULL==*q)
		{
				printf("malloc err!");
				exit(-1);
		}
}
int main()
{
		int i,j,temp;
		int **pp;
		creat_memory((void **)&pp,3*sizeof(int *));
		for(i=0;i<R;i++)
		{
				creat_memory((void **)(pp+i),3*sizeof(int));
		}
		for(i=0;i<R;i++)
				for(j=0;j<C;j++)
						scanf("%d",*(pp+i)+j);
		for(i=0;i<R;i++)
		{
				for(j=0;j<C-1;j++)
				{
						if(pp[i][j]>pp[i][j+1])
						{
								temp = pp[i][j];
								pp[i][j] = pp[i][j+1];
								pp[i][j+1] = temp;
						}
				}
		}
		if(pp[0][0]==pp[R-1][C-1])
						printf("无第二小的值。\n");
		else
		{
				for(i=0;i<R;i++)
				{
						for(j=0;j<C-1;j++)
						{
								if(pp[0][0]!=pp[i][j+1])
								{		
										printf("第二小的值:%2d\n",pp[i][j+1]);
												i = R-1;
											break;	
								}
						}
				}
		}
		
		for(i=0;i<3;i++)
			if((pp+i)!=NULL)
			{
					free(*(pp+i));
					*(pp+i) = NULL;
			}
		if(pp!=NULL)
		{
				free(pp);
				pp = NULL;
		}
		return 0;
}


				

