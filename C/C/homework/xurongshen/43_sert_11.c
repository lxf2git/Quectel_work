#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 9

void create_memory(void **str, int size)
{
	*str = malloc(size);
	if(NULL == *str)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

int count(int m)
{
	int i,c=0,size=0;
	for(i=0;i<m;i++)
	{
		c =c+ (i*2+1);
		printf("C:%d\n",c);
	}
	if(m>1)
	{
		size = m+c-(m-1)*2-1;
	}
	else
	{
		size =1;
	}
	return size;
}

void deal(char * ptr, char *src, int len)
{
	int i,j,a=0,m,n;
	for(i=0;i<len;i++)
	{
		ptr[a]=src[i];
		a++;
		if(i == len-1)
		{
			puts(ptr);
			break;
		}
		for(j=0;j<(i)*2+1;j++)
		{
			ptr[a]='#';
			a++;
		}
	}

	/*
	puts(ptr);
	n = (i)*2+1;
	m = strlen(ptr);
	ptr[m-n]='\0';
	puts(ptr);
	*/
}

int main()
{
	char * p=NULL;
	int m,len=0;
	char ch[M];
	printf("please input your string:");
	gets(ch);
	m = strlen(ch);
	len = count(m);
	create_memory((void **)&p, len*sizeof(char));

	deal(p,ch,m);
	p = ch;
	printf("len:%d\n",len);
	puts(p);
	return 0;

}
