#include<stdio.h>
int main()
{
		char t;
		int e=0,k=0,s=0,q=0;
		printf("请输入一串字符：\n");
		for(;t<=177;)
		{
			scanf("%c",&t);
			if(t=='\n')
			break;
			else
			{
				if(t<=122&&t>=97||t<=90&&t>=65)
				{
						e++;
				}
				else if(t==32)
				{
						k++;
				}
				else if(t<=57&&t>=48)
				{
						s++;
				}
				else
						q++;	
			}
		}
		printf("字母个数:%d\n空格个数:%d\n数字个数:%d\n其他字符个数:%d\n",e,k,s,q);

}
