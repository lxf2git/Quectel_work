#include<stdio.h>
int main()
{
	char c;
	int letter,space,num,other;
	letter=0;
	space=0;
	num=0;
	other=0;
	for(;;)
	{
		scanf("%c",&c);
		if(c!='\n')
		{
		if(c>=65&&c<=90||c>=97&&c<=122)
		{
			letter+=1;
		}
		if(c>=48&&c<=57)
		{
			num+=1;
		}
		if(c==32)
		{
			space+=1;
		}
		if(c>=0&&c<32||c>32&&c<48||c>57&&c<65||c>90&&c<97||c>122)
		{
			other+=1;
		}
		}
		else 
				break;
	}
	printf("输入字母的个数为:%d\n",letter);
	printf("输入数字的个数为:%d\n",num);
	printf("输入空格的个数为:%d\n",space);
	printf("输入其他的个数为:%d\n",other);
	return 0;
}
