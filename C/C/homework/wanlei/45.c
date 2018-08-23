#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fun(char **p);
void creat_memory(void **p, int size);
void input(char *p);
int count(char *p);
void change(char *p);

int main()
{
	char *p=NULL;
	fun(&p);
	input(p);
	//puts(p);
	//int s=count(p);
	change(p);
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}
	//printf("s:%d\n",s);
	return 0;
}

void fun(char **p)
{
	printf("请输入最多输入字符数\n");
	int a;
	scanf("%d",&a);
	creat_memory((void **)p,a*sizeof(char));
}

void creat_memory(void **p, int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void input(char *p)
{
	printf("请输入一个字符串\n");
	scanf("%s",p);
}

/*int count(char *p)
{
	int m=strlen(p);
	int n=0;
	int i;
	for(i=0;i<m;i++)
	{
		if(p[i]=='#')
		{
			n++;
		}
	}
	return n;
}*/

void change(char *p)
{
	//printf("x:%d ",x);
	int i,j,k,n=0;
	for(i=0;i<strlen(p);i++)
	{
		if(p[i]=='#')
		{
			n++;
			//printf("%d ",n);
			if(n%2==1)
			{
				j=i;
				while(1&&j<strlen(p))
				{
					j++;
					if(p[j]=='#'||p[j]=='\0')
					{
						//printf("p[j]:%c1 ",p[j]);
						n++;
						if(p[j]=='\0')
						{
							for(k=i;k<strlen(p);k++)
							{
								p[k]='\0';
							}
						}
						else
						{
							for(k=i;k<strlen(p);k++)
							{
								p[k]=p[k+j-i+1];
							}	
						}
						i--;
						break;	
					}
				}
			}
		}
		//printf("i:%d ",i);
	}
	puts(p);
}
