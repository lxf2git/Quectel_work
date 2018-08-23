#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3
void getmemary(char **p,int size)
{
		*p=(char *)malloc(size);
}

void min_max(char *pp[N])
{ 
//		printf("%s\n",pp[0]);
		int i,j,n=0;
		char *str[N];
		char *t;
		for(i=0;i<N;i++)
		{
				getmemary(&str[i],30*sizeof(char));
		}

				getmemary(&t,30*sizeof(char));

		for(i=0;i<N;i++)
		{
					n=	strlen(pp[i]);
//					printf("%d=%d\n",i,n);
					for(j=0;j<(n/2+n%2);j++)
					{
							str[i][j]=pp[i][n-1-j];
					}
				printf("%d=%s\n",i,str[i]);
		}		

		for(j=0;j<N;j++)
		{
				for(i=0;i<N-1;i++)
				{
						if(strcmp(str[i],str[i+1])>0)
						{
								
								strcpy(t,pp[i]);
								strcpy(pp[i],pp[i+1]);
								strcpy(pp[i+1],t);

								strcpy(t,str[i]);
								strcpy(str[i],str[i+1]);
								strcpy(str[i+1],t);
						}
				}
		}
}


int main()
{
		int i;
		char *p[N];
		for(i=0;i<N;i++)
		{
				getmemary(&p[i],30*sizeof(char));
		}
		for(i=0;i<N;i++)
		{
				printf("输入字符串%d：\n",i);
				gets(p[i]);
			//	printf("%d",sizeof(p[i]));
			//	printf("%s\n",p[i]);
		}

		min_max(p);

		for(i=0;i<N;i++)
		{
				printf("%d=%s\n",i,p[i]);
		}

		for(i=0;i<N;i++)
		{
				free(p[i]);
				p[i]=NULL;
		}
		return 0;

}
