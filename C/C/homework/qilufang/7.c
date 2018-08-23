#include<stdio.h>

int main()
{
	int eng=0,spa=0,qi=0,shu=0;
	char zifu;
	printf("输入字符串：\n");
	for(;zifu<=177;)
	{
		scanf("%c",&zifu);
		if(zifu==10)
		{
			break;
		}
		else if(zifu>=65&&zifu<=90||zifu>=97&&zifu<=122)
		{
			eng+=1;
	
		}
		else if(zifu>=48&&zifu<=57)
		{
			shu+=1;
		}
		else if(zifu==32)
		{
			spa+=1;
		}
		else
		{
			qi+=1;
		}
	}
	printf("英文字母个数：%d  空格个数：%d  数字个数：%d  其他个数：%d\n",eng,spa,shu,qi);

	return 0;
}
