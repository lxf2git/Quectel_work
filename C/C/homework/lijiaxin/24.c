#include<stdio.h>
#include<string.h>
int main()
{
		char str[20]={'0'};
		int i,j,length;
		printf("请输入一串字符(长度小于19):\n");
		gets(str);
		length = strlen(str);
		for(i=0;i<length;i++)
		{
				if(str[i]=='c')
				{
						for(j=i;j<length;j++)
						{	
							str[j] = str[j+1];
						}
				         i--;
				}
			/*	if(str[i]!='c')
				{
					printf("%c",str[i]);
				}*/
		}
		puts(str);
		//printf("\n");


}
