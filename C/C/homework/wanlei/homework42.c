#include<stdio.h>
#include<stdlib.h>
#define N 100

void input(char *p);
int count(char *p);
void i_p(char *p,int x);

int main()
{
	char *p=NULL;
	int max;
	p = (char *)malloc(N*sizeof(char));
	input(p);
	max=count(p);
	printf("%d\n",max);
	i_p(p,max);
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}
	return 0;
}

void input(char *p)
{
	printf("请输入一个字符串\n");
	//scanf("%s",p);
	gets(p);
}

int count(char *p)
{
	int i,n=0;
	int max=1;
	for(i=0;p[i]!='\0';i++)
	{
		n++;
		if((p[i]==' ')||(p[i]=='.'))
		{
			printf("i:%d ",i);
			if(max<n)
			{
				max=n-1;	
				printf("max:%d ",max);
				n=0;
			}
			else
			{
				n=0;
			}
		}
	}
	printf("\n");
	return max;
}

void i_p(char *p,int x)
{
	int i,j,n=0,max=1;
	for(i=0;p[i]!='\0';i++)
	{
		n++;
		if(p[i]==' '||p[i]=='.')
		{
			max=n-1;
			n=0;
			if(max==x)
			{
				for(j=i-max;j<i;j++)
				{
					printf("%c",p[j]);
				}
				printf("\n");
			}
		}
	}

}
