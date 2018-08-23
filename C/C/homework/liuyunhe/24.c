#include<stdio.h>

int main()
{
		int i,j=0;
		char string[100];
		printf("请输入小于一百位的字符串\n");
		gets(string);
		for(i=0;i<100;i++)
		{
				if(string[i]=='c')
				{
				;
				}
				else
				{
						string[j]=string[i];
						j++;
				}
		}
		puts(string);

}
