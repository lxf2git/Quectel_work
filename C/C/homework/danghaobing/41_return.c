#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
int main() 
{
	int flag,i,c;
	char p[30]={},p1[30]={};
	printf("请输入第一个字符串!\n");
	scanf("%s",p);
	printf("请输入第二个字符串!\n");
	scanf("%s",p1);
	printf("请输入flag\n");
	scanf("%d",&flag);
	switch(flag)
	{
			case 0:
					strcat(p,p1);
					puts(p);
					break;
			case 1:
					strcat(p1,p);
					puts(p1);
					break;
			default:
					printf("0\n");
					break;
	}
}
