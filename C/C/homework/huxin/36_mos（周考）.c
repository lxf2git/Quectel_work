#include<stdio.h>
#include<string.h>
int main()
{    
    int i;
	char str[100];
	gets(str);
	i=judge_str(str);
	printf("%d\n",i);
	return 0;
}
int judge_str(char str[])
{
	int i,j,n,k=0,l=0;
	n = strlen(str);    //字符的长度
	for(i = 0,j = n-1;i<(n/2);i++,j--)    //j一定要等于n-1.(str[0]开始) 
	{
		if(str[i]==str[j])
		{
			k++;
		}
		l++;
	}
    if(k==(n/2))
	{
		return (0);
	}
    else
	{
		return (-1);
    }
}
