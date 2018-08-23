#include<stdio.h>
int main()
{
	int i=0,j=0,k=0,l=0;
	char a;
	
	printf("输入字符串：\n");

	while(1)
	{
		scanf("%c",&a);
		if(a==10)
	
				break;

		else if(a>=65&&a<=90||a>=97&&a<=122)
		{	
				i++;
		}
		else if(a>=48&&a<=57)
		{	
				j++;
		}
		else if(a==32)
		{	
				k++;		
		}
		else
		{	
				l++;
				
		}
	}
			printf("字母个数%d\n",i);
			printf("数字个数%d\n",j);	
			printf("空格个数%d\n",k);
			printf("其他个数%d\n",l);
	return 0;
}
