#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int creat_memory(void **str,int size)
{
		*str = (void *)malloc(size);
}

char *delete(char *p1,char *p2)
{
		int i,j=0,n=0;
		for(i=0;i<strlen(p1);i++)
		{
				if(*(p1+i)=='#')
				{
						n++;
				}

				if(n%2==0&&(*(p1+i)!='#'))
				{
						*(p2+j)=*(p1+i);
						j++;
				}

		}
		return p2;
}

int main()
{
		char *str;
		char *str1;
		char *str2;
		int n=100;
		int m=100;
		creat_memory((void **)&str,n*sizeof(char));
		creat_memory((void **)&str1,m*sizeof(char));

		printf("输入一个带#字符串\n");
		scanf("%s",str);
		str2=delete(str,str1);
		
		printf("%s\n",str2);
		free(str);
		str=NULL;
		free(str1);
		str1=NULL;
		return 0;
}
