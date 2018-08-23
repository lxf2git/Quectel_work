#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getmm(void **p,int size)
{
	*p=malloc(size);
}

char *cat(char*str1,char *str2,int flag)
{
	char *string;
	if(flag==0)
	string=strcat(str1,str2);
	else if(flag==1)
	string=strcat(str2,str1);
	else
	string=NULL;
	return string;
}
int main()
{
	int n1,n2,flag;
	char *str1,*str2;
	printf("输入两个字符串长度\n");
	scanf("%d%d",&str1,&str2);
	getmm((void **)&str1,n1*sizeof(char));	
	getmm((void **)&str2,n2*sizeof(char));
	printf("输入两个字符串\n");
	scanf("%s%s",str1,str2);
	printf("输入flag\n");
	scanf("%d",&flag);
	printf("%s",cat(str1,str2,flag));
				return 0;
}
