#include"main.h"

long create(double balance,int passord)
{
int passord1;
int i;
for(i=3;i>0;i--)
{
		printf("请再次输入密码：\n");
		scanf("%d",&passord1);
		if(passord1==passord)
		{
				printf("密码正确\n");
				break;
		}
		else
		{
				printf("你还有%d 次机会",i);
		}
}
}
