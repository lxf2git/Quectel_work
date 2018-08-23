#include<stdio.h>
int main()
{
	char b;
	int j=0,c=0,d=0,e=0;
	
	printf("请输入字符串：\n");
	//getchar();
	for(;;)
	{

		scanf("%c",&b);
		if(b!='\n')
	{
		if((b>=65&&b<=90)||(b>=97&&b<=122))
		{
			
			
				j+=1;
			
		}
		
		else if(b>=48||b<=57)
		{
			
			
				c+=1;
		
		}
		else if(b=32)
		{
			
			
				d+=1;
			
		}

		else
		{
			
			
				e+=1;
							
		}

	
	}
		
		else
		{ 
			break;
		}
	}
		printf("字母:%d\n数字:%d\n空格:%d\n其他:%d\n",j,c,d,e);
		return 0;
}
