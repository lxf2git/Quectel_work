#include<stdio.h>
#include<string.h>

int main()
{
		char ch[20]="";
		char c,t;
		int i,j,len;
		while(1)
		{
				len=strlen(ch);
				printf("请输入单个字符:\n");
				scanf("%c",&c);
				getchar();
				if(len<1)
				{
						ch[0]=c;
				}
				else
				{
						if(c>ch[len-1])
						{
								ch[len]=c;
						}
						else
						{
								for(i=0;i<len;i++)
								{
										if(c<=ch[i])
										{
												t=ch[i];
												ch[i]=c;
												c=t;
												ch[len]=c;
										}
								}
						}
				}
				ch[sizeof(ch)-1]='\0';
				printf("sizeof:%d\n",sizeof(ch));
				printf("strlen:%d\n",strlen(ch));
				printf("排序后的字符串:%s\n",ch);
		}
		return 0;
}
