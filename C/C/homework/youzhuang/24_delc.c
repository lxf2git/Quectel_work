#include<stdio.h>
#include<string.h>

int main()
{
		char ch[20];
		char t;
		int i,j;

		printf("请输入字符串:\n");
		scanf("%s",&ch);

		for(i=0;i<strlen(ch);i++)
		{
				if(ch[i]=='c')
				{
						for(j=i;j<strlen(ch);j++)
						{
								ch[j]=ch[j+1];
						}
				}
		}

		ch[strlen(ch)]='\0';

		printf("%s\n",ch);

		return 0;
}
