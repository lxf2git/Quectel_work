#include<stdio.h>
#include<string.h>

int main()
{
	char string[50]={'0'};
	int i,j,k,s;
	printf("请输入字符串\n");
	for(i=0;;i++)
		{
		scanf("%c",&string[i]);
		if(string[i]==10)
		break;
		}
	s=strlen(string);
	for(i=0;i<s;i++)
	{
		if(string[i]=='c')
		{
			for(k=i;k<s;k++)
			{
				string[k]=string[k+1];
			}
				i--;
		}
	}
	puts(string);
	return 0;
}
