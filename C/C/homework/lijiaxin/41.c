#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void  creat_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q==NULL)
		{
				printf("malloc err!\n");
				exit(-1);
		}
}
int main()
{
		char *a=NULL,*b=NULL,*temp=NULL;
		int length1,length2,flag;
		printf("请输入你要操作的两个字符串长度:\n");
		scanf("%d%d",&length1,&length2);
		getchar();
		printf("请输入你要操作的两个字符串:\n");
		creat_memory((void **)&a,length1*sizeof(char));
		creat_memory((void **)&b,length2*sizeof(char));
		gets(a);
		gets(b);
		printf("请选择功能:\n");
		printf("0:b接a后:\n");
		printf("1:a接b后:\n");
		printf("其它无效:\n");
		scanf("%d",&flag);
		switch(flag)
		{
				case 0:puts(strcat(a,b));break;
				case 1:puts(strcat(b,a));break;
				default;printf("NULL\n");break;
		}
		if(a!=NULL)
		{
				free(a);
				a = NULL;
		}
		if(b!=NULL)
		{
				free(b);
				b = NULL;
		}
		return 0;
}
