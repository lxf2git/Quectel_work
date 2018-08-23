#include<stdio.h>
#include<string.h>
#define N 50
int main()
{
	printf("请输入：");
	char num[N]={};
	char str[100]={"-"};
//	char aa[N]="hello";
	int i;
	int a=0,b;
	scanf("%d",&b);

	if(b < 0)
	{
		b = b*(-1);
		a=1;
	}

	for(i=1;b%i != b;i*=10)
	{
//		printf("i:%d\n",i);
		;
	}

	int k,j;
	k=0;

	for(j=i/10;j!=0;j=j/10)
	{
		num[k] = (b/j)+48;
//		printf("num%d:%c\n",k,num[k]);
		b =b -((b/j)*j);
		k = k+1;
//		printf("k-->%d\n",k);
	}

	num[k] = '\0';
//	puts(num);
//	puts(aa);
//	printf("num-->%s\n",num);
	if(a == 1)
	{
		strcat(str,num);
		printf("%s\n",str);
	}
	else
	{
		printf("%s\n",num);
	}
	return 0;
}
