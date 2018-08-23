#include"main.h"
int main()
{
		sStackn stn;
		sStackx stx;//stn:存数字 stx:存运算符
		init_stackn(&stn);
		init_stackx(&stx);
		char a;//输入的数字运算符
		int a1;//存入的数字
		int b;//取出的数字
		char c,c2;//取出的运算符
		int a3;//存提取出来的'+''-'左右的数
		int i;
		printf("please input:\n");
		while(1)
		{
				a1=0;
				i=0;
				while(1)
				{
					scanf("%c",&a);
					if(a==' ')
						getchar();
					if(a>='0'&&a<='9')
					{
						if(i==0)
							a1+=a-'0';
						else
						{
								a1=a1*10;
								a1+=a-'0';
						}
							
						i++;
					}
					else
					{
							//printf("%d ",a1);
							pushn(&stn,a1);
							break;
					}
					if(a=='\n')
						break;
				}
				if(a=='\n')
						break;
				pushx(&stx,a);

		}
		popn(&stn,&b);
		a3=b;
		popx(&stx,&c);
		c2=c;
		a3=circle(&stn,&stx,&a3,&c2);
		printf("%d\n",a3);
		return 0;
}
