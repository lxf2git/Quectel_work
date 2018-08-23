#include"main.h"

int password()
{
	static int a=0;
	printf("a:%d,id:%d\n",a,id);
	static int b,c;
	if(a!=id)
	{		
		a++;
		do
		{
		printf("请输入密码\n");
		scanf("%d",&b);
		printf("请重复您的密码\n");
		scanf("%d",&c);
		}while(b!=c);
		printf("a:%d\n",a);
	}
	else if(a==id)
	{
			return b;
	}
}
	/*if(a>1)
	{
		printf("请输入id\n");
			if(id==x);
			{
				if(p==i[x-10000])
						;
				else
						exit(0);
			}
	}*/
