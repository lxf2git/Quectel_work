//输入一个字符串，计算数字有多少个字母有多少个空格有多少个其他有多少个

#include<stdio.h>

int main()
{
	char zifu;
	int	zimu = 0, kongge = 0, shuzi = 0, qita = 0;
	printf("请输入字符串");
	for(;;)
	{
		scanf("%c",&zifu);
		if(zifu >= 'A' && zifu <= 'Z' || zifu >= 'a' && zifu <= 'z')
			{
				zimu++;
			}
		else if(zifu == ' ')
			{
				kongge++;
			}
		else if(zifu >= '0' && zifu <= '9')
			{
				shuzi++;
			}
		else 
			{
				qita++;
			}
		if(zifu == 10)
			{
				break;
			}
	}
	
	printf("字母%d\n数字%d\n空格%d\n其他%d\n",zimu,shuzi,kongge,qita);
	return 0;
}
