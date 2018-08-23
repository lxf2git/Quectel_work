#include<stdio.h>
#include<stdlib.h>

#define N 100

void input (char *p);
void print (char *p);
char * find (char *p);

int main()
{
		char *p;
		p=(char *)malloc(N*sizeof(char));
		printf("请输入:\n");
		input (p);
		printf("最长单词:%s\n",find(p));
		return 0;
}

void input (char *p)
{
		gets(p);
}

char * find (char *p)
{
		char *p2;
		p2=(char *)malloc(N*sizeof(char));
		int i,k=0,count=0,max=0,x=0;
		int mi=0,mj=0;
		for	(i=0;i<N;i++)
		{
				if(*(p+i)==' '||*(p+i)=='.')
				{
						if(mi!=0)
						{
								mi++;
						}
						if(count>max)
						{
								x=0;
								max=count;
								for(k=0;k<count;k++)
								{
										*(p2+x)=*(p+mi+k);
										x++;
								}
								*(p2+x)=' ';
								x++;
						}
						else
						{
								if(count==max)
								{
										for(k=0;k<count;k++)
										{
												*(p2+x)=*(p+mi+k);
												x++;
										}
										*(p2+x)=' ';
										x++;
								}
						}
						mi=i;
						count=0;
						if (*(p+i) == '.')
						{
								break;
						}
				}
				else
				{
						count++;
				}
		}
		*(p2+x)='\0';
		return p2;
}
