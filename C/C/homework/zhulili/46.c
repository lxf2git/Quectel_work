#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void create_memory(char **q,int size)
{
	*q = (char *)malloc(size);
	if(NULL==*q)
	{
		printf("malloc error");
		exit(-1);
	}
}

void move_right(char *q)
{
	int i,j,m,length;
	int n;
	char *w;
	create_memory(&w,50);
	printf("请输入移动的位数：\n");
	scanf("%d",&n);
	length = strlen(q);
	for(i=0;i<length-n;i++)
	{
		*(w+i)=*(q+i);
	}
	printf("%s\n",strcat((q+length-n),w));

	if(w!=NULL)
	{
		free(w);
		w=NULL;
	}

	if(q!=NULL)
	{
		free(q);
		q=NULL;
	}

}
int main()
{
	char *p;
	int size;
	printf("请输入空间大小：\n");
	scanf("%d",&size);
	create_memory(&p,size);
	printf("请输入字符串:\n");
	scanf("%s",p);
	move_right(p);
	return 0;
}
