#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define M 10//开空间大小
void create_memory(char **p)
{
	*p = (char *)malloc(M*sizeof(char));
}
int main() 
{
		int i;
		char *p[N];
		char *p1[N];
		int x,s,j;
		for(i=0;i<N;i++)
		{
			create_memory(&p[i]);
			create_memory(&p1[i]);
		}
		for(i=0;;i++)
		{
				scanf("%s",p[i]);
				printf("子字串%d:",i+1);
				x=strlen(p[i]);
				for(j=x-1,s=0;j>=(x/2);j--,s++)
				{
						*(p1[i]+s)=*(p[i]+j);
				}
				printf("%s ",p1[i]);//参照字串
				if(getchar()=='\n')
				{
						break;
				}

		}
		//printf("\n您输入了%d个字符串\n",i+1);
		//printf("%s",p[0]>p[1]?p[0]:p[1]);
		//printf("%d",strcmp(p1[0],p1[1]));
		//printf("%s",p1[0]>p1[1]?p1[0]:p1[1]);
		printf("\n排序后结果：\n");
		int o,u=0,y;
		for(y=0;y<i+1;y++)
		{
			for(o=0;o<i+1;o++)
			{
				for(j=0;j<i+1;j++)
				{
					if(strcmp(p1[j],p1[o])==1||strcmp(p1[j],p1[o])==0)
					{
							u++;
							//printf("%d",u);
							if(u==i+1&&p1[o]!="zzzzzz")
							{
									printf("%s ",p[o]);
									p1[o]="zzzzzz";
									u=0;
							}

					}
				}
				u=0;
							
			}
		}
		printf("\n");
}
