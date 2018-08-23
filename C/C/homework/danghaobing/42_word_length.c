#include<stdio.h> 
#include<stdlib.h>
#define N 30
int main() 
{
		char *p=NULL;
		int coun=0,i,flag,count=0,j,count1=0;
		p = (char *)malloc(N*sizeof(char));
		if(NULL==p)
		{
				printf("malloc error!\n");
				exit(-1);
		}
		printf("请输入英文句子\n");
		for(j=0;j<2;j++)
		{
				for(i=0;;i++)
				{
					if(j==0)
					{scanf("%c",(p+i));}
					if(*(p+i)=='.')
					{
						break;
					}
					if(*(p+i)==' ')
					{
						count=0;
						count1=0;
					}	
					if(*(p+i)!=' '&&j==0)
					{
						count++;
						if(coun<count)
						{
							coun=count;
						}
					}
					if(*(p+i)!=' '&&j==1)
					{
						count1++;
						if(coun==count1)
						{	flag=i;
							int x=flag-count1+1;
							for(;x<=flag;x++)
							{
								printf("%c",*(p+x));
							}
							printf("\n");
						}
					}
				}
		}
		if(p!=NULL)
		{
				free(p);
				p = NULL;
		}
}
