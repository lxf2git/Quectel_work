#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20
void output(char *p);
void input(char *p);
char *judge(char *p_1,char *p_2,int f);
void Memory(char **p,int size)
{
	*p=(char *)malloc(size);
	if(*p==NULL)
	{
		printf("ERROR!");
		exit(-1);
	}
}

int main()
{
	int flog;
	char *str_1=NULL;
	char *str_2=NULL;
	char *str_3=NULL;
	Memory(&str_1,30*sizeof(char));
	Memory(&str_2,30*sizeof(char));
//	Memory(&str_3,30*sizeof(char));
	input(str_1);
//	output(str_1);
	input(str_2);
	scanf("%d",&flog);
	str_3= judge(str_1,str_2,flog);
	printf("adrr:%p\n",judge(str_1,str_2,flog));
	printf("%s\n",str_3);

	return 0;

}
void input(char *p)
{
	printf("请输入字符串：\n");
	scanf("%s",p);
}
void output(char *p)
{
	printf("%s",p);
}
char *judge(char *p_1,char *p_2,int f)
{
	if(f==0)
	{char *pt;
		strcat(p_1,p_2);
		printf("字符串%s\n",p_1);
		pt = p_1;
		printf("pt地址%x\n",pt);
		return pt;
	}
	else if(f==1)
	{
		strcat(p_2,p_1);
		//return p_2;
	}
	else
	{	
		//	return NULL;
	}

}
