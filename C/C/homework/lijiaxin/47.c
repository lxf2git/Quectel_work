#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
void input(char **q);
void create_room(char **p);
void create_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}
void compare(char **h1,char **str1)
{
		static int i=0;
		int result,j;
		char *temp;
		for(i=0;i<N;i++)
				for(j=i;j<N;j++)
				{
						result = strcmp(*(h1+i),*(h1+j));
						if(result>0)
						{
										temp = *(str1+i);
										*(str1+i) = *(str1+j);
										*(str1+j) = temp;
										temp = *(h1+i);
										*(h1+i) = *(h1+j);
										*(h1+j) = temp;
						}
				}
		for(i=0;i<N;i++)
		{
				printf("%s  ",*(str1+i));
		}
		for(i=0;i<N;i++)
		{
				if(*(h1+i)!=NULL)
				{
						free(*(h1+i));
						*(h1+i) = NULL;
				}
		}
}
void deal(char **str)
{
		int i,j,n,count,k;
		char *h[N];
		char **temp;
		temp = h;
		create_room(h);
		for(i=0;i<N;i++)
		{
			n = strlen(*(str+i));
			count = n % 2;
			if(count == 1)
			{
					for(j=n-1,k=0;j>=n-n/2-1;j--,k++)
					{
							*(*(h+i)+k) = str[i][j];
					}
			}
			if(count==0)
			{
					for(j=n-1,k=0;j>=n-n/2;j--,k++)
							*(*(h+i)+k) = str[i][j];
			}
		}
		compare(temp,str);
}
void create_room(char **p)
{
		int i,length=0;
		for(i=0;i<N;i++)
		{
				printf("请输入需要的空间:\n");
				scanf("%d",&length);
				create_memory((void **)p+i,length*sizeof(char *));
		}
		getchar();
}
void input(char **q)
{
		int length=0,i;
		for(i = 0;i < N;i++)
		{
				printf("请输入需要比较的字符串:\n");
				gets(*(q+i));
		}
		deal(q);
}
int  main()
{
		int i;
		char *p[N];
		create_room(p);
		input(p);
		for(i=0;i<N;i++)
		{
				if(*(p+i)!=NULL)
				{
						free(*(p+i));
						*(p+i) = NULL;
				}
		}
		return 0;
}
