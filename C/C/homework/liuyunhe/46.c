#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char getmemory(char **p,int size)
{
		*p=malloc(size);
}

void cir(char *p1,char *p2,int n)
{
		int N,i;
		//printf("%s\n",p1);
		N=strlen(p1);
		for(i=0;i<n;i++)
		{
				*(p2+i)=*(p1+N-n+i);
		}
		for(i=n;i<N;i++)
		{
				*(p2+i) = *(p1+i-n);
		}
}
int main()
{

		int n;
		char *str1;
		char *str2;
		getmemory(&str1,100*sizeof(char));
		getmemory(&str2,100*sizeof(char));
		printf("输入右移个数:\n");
		scanf("%d",&n);
		printf("输入一个字符串\n");
		getchar();
		gets(str1);
		cir(str1,str2,n);

		printf("%s\n",str2);

		free(str1);
		str1=NULL;
		free(str2);
		str2=NULL;
		return 0;
}
