#include<stdio.h>
#include<string.h>

int main()
{
	char a[100],b[100];
	int i,j,flag;
	printf("输入一串字符 ");
	scanf("%s",&a);
	printf("再输入一个字符串");
	scanf("%s",&b);
	printf("flag:");
	scanf("%d",&flag);
	if(flag==0)
		{
			strcat(a,b);
				printf("%s",a);
		}
	if(flag==1)
	{
		strcat(b,a);
			printf("%s",b);
	}
	else if(flag!=0&&flag!=1)
		printf("0");
	return 0;
}
