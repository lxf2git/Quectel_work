#include<stdio.h>
#include<string.h>
int judge_str(char str[]);
int main()
{
	char string[100];
	gets(string);
	printf("%d",judge_str(string));
	return 0;
}

int judge_str(char str[])
{
	int n,i,flag;
	n=strlen(str);
	n=n-1;
	for(i=0;i<=n;i++,n--)
	{	
		if(str[i]!=str[n])
		{
			flag=0;
			break;
		}
	 else
		{
			flag=1;
		}
	}
  return (flag);
}

