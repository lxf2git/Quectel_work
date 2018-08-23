#include<stdio.h>
#include<string.h>
int smm(char *s1,char *s2);
int max(int *a,int *b,char *s1);
int main()
{
		char s1[100]={'\0'},s2[100]={'\0'};
		printf("输入字符串1\n");
		gets(s1);
		printf("输入字符串2\n");
		gets(s2);
		smm(s1,s2);
		return 0;
}



int smm(char *s1,char *s2)
{
		int a[100]={0},b[100]={0};
		int N=strlen(s1);
		int M=strlen(s2);
		int i,j,n,m=0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
					if(*(s1+i)==*(s2+j))
					{
							n=1;
						while(*(s1+i+n)==*(s2+j+n))
						{
							n++;
						}
						if(n>1)
						{
						a[m]=i;
						b[m]=n;
						//printf("b[m]=%d\n",b[m]);
						m++;
						}
					}
			}
		}
		max(a,b,s1);
}



int max(int *a,int *b,char *s1)
{
		int i;
		int max=*b;
		int p=0;
		for(i=0;i<100;i++)
		{

				if(*(b+i)>max)
				{
						max=*(b+i);
						p=i;
				}
		}
		for(i=*(a+p);i<(*(a+p)+max);i++)
		{
				printf("%c",*(s1+i));
		}
}
