#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

#if 1
void exchange(char *src, int m)
{
	int length = strlen(src);
	char test[N]={};
	int i,a=0;
	for(i=(length -m);i<length;i++)
	{
		test[a] = src[i];
		a++;
	}
	src[length-m] = '\0';

	strcat(test,src);
	printf("the result:");
	puts(test);
	

}

void _after(void (*p1)(char *,int), char *src,  int m)
{
//	char * p2=NULL;
	p1(src,m);
//	printf("%s\n",*p2);
}
#endif
void create_memory(char ** pa,int size)
{
	*pa =(char*) malloc(size);
	if(NULL == *pa)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

int main()
{
	char ch[N]={};
	char *ptr=NULL;
	char *p2=NULL;
	int len=0,m=0;
	printf("please input your string:");
	scanf("%s",ch);
	printf("put in circule num:");
	scanf("%d",&m);
	len = strlen(ch);

	printf("len:%d\n",len);
	printf("ptr:%s\n",ptr);

	create_memory(&ptr,(len+m)*sizeof(char));
	ptr = ch;
	printf("ptr:%s\n",ptr);

	_after(exchange,ptr,m);
//	printf("%s",*p2);
	return 0;
}
