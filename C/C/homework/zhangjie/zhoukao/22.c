#include<stdio.h>
#include<string.h>

int judge_str(char str[])
{
	char str2[100]={0};
	int i,n,j;
	n=strlen(str);
	//printf("0:%s\n",str);
	//printf("%d",n);
	j=0;
	for(i=n-2;i>=0;i--)
	{
		str2[j]=str[i];
		j++;
	}
//	printf("1:%d",j);
//	printf("2:%s\n",str2);
	for(i=0;i<n-1;i++)
	{
		if(str[i]!=str2[i])
		return -1;
	}
	return 0;
}

int main()
{
	char str1[100]={0};
	int i,j;
	printf("输入一个字符串\n");
	for(i=0;;i++)
	{
		scanf("%c",&str1[i]);
		if(str1[i]==10)
		{
			//str1[i]='0';
			break;
		}
	}
//	printf("4:%d\n",n);
	j=judge_str(str1);
	printf("%d\n",j);
}
