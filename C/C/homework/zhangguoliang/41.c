#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main()
{
	char *a;
	char *b;
	char *c=NULL;
	int flag;
	printf("输入字符串a:\n");
	a=malloc(N*sizeof(void));
	scanf("%s",a);
	printf("输入字符串b:\n");
	b=malloc(N*sizeof(void));
	scanf("%s",b);
	printf("输入标志flag:\n");
	scanf("%d",&flag);
//	connect((void *)&a,(void *)&b,flag);
//	return 0;
//}

//void connect(void *p,void *q,int f)
//{
	switch(flag)
	{
		case 0:
		strcat(a,b);
		printf("%s\n",a);
		break;
		case 1:
		strcat(b,a);
		printf("%s\n",b);
		break;
		default :
		printf("%p\n",c);
		break;
	}
}
