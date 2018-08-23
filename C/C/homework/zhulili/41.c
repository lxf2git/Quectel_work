#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define r 2

void create_memory(char **p,int size)
{
	*p = (char *)malloc(size);
	if(NULL==*p)
	{
		printf("malloc error");
		exit(-1);
	}
}

void input(char **str)
{
	int i;
	int flag;
	printf("请输入字符串：\n");
	for(i=0;i<r;i++)
	scanf("%s",*(str+i));
	printf("请输入flag：\n");
	printf("0----------b接在a后\n");
	printf("1----------a接在b后\n");
	printf("其他-------返回空指针\n");
	scanf("%d",&flag);
	switch(flag)
	{
		case 0:
				printf("%s",strcat(*(str+0),*(str+1)));
				break;
		case 1:
				printf("%s",strcat(*(str+1),*(str+0)));
				break;
		default: 
				printf("NULL");
				break;
	}
	for(i=0;i<r;i++)
	{
		free(*(str+i));
		*(str+i) = NULL;
	}
	
}

void fun(char *p[r]) 
{
	int size,i;
	printf("请输入开空间大小：\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&size);
		create_memory(&p[i],size);
	}
	input(p);

}

int main()
{
	char *p[r];
	fun(p);
	return 0;
}
