#include<stdio.h>
int i;
char str[100];
void judge_str(char str[])
{
	int a,b=i+1;
//	for(;b>b/2;b--)
//	{
		for(a=0;a<(b/2);a++,i--)
		{  
			if(str[i]!=str[a])
				break;
		}
//	}

		if(a+2==i&&b%2==1)
		printf("0是\n");
		else
		printf("1否\n");

}
int main()
{
	printf("输入一个字符串");
	for(i=0;;i++)
	{
		scanf("%c",&str[i]);
			if(str[i]=='\n')
			{
			//	getchar();
				i--;
				break;
			}
	}

		judge_str(str);
	return 0;
}

















