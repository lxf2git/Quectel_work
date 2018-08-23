#include<stdio.h>
#include<string.h>
int main()
{
		char string[30]={'\0'};
		char a[1],t;
		int i,n;
		printf("请输入从小到大的字符串\n");
		gets(string);
		printf("输入一个字符\n");
		scanf("%c",&a[0]);
		for(i=0;i<20;i++)
		{
				if(string[i]>a[0])
				{
						t=string[i];
						string[i]=a[0];
						a[0]=t;
				}
		}
		n=strlen(string);
		string[n]=a[0];
		puts(string);
		

		return 0;
}
