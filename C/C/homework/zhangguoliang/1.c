#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,x,y;
	printf("输入年月日\n");
	scanf("%d%d%d",&a,&b,&c);
	d=a%4;
	e=a%100;
	f=a%400;
	if(d==0&e!=0||f==0)
		{
			printf("润年\n");
	
		
		if(b>=1&&b<=12)
		{	switch(b)
			{
				case 1:
						x=0;
						break;
				case 2:
						x=31;
						break;
				case 3:
						x=60;
						break;
				case 4:
						x=91;
						break;
				case 5:
						x=121;
						break;
				case 6:
						x=152;
						break;
				case 7:
						x=182;
						break;
				case 8:
						x=213;
						break;
				case 9:
						x=244;
						break;
				case 10:
						x=274;
						break;
				case 11:
						x=305;
						break;
				default:
						x=335;
						break;
			}
			y=x+c;
			printf("这是第%d天\n",y);
			}
			else
				printf("月份错误\n");
		
		}
	else
	{
			printf("普通年\n");
		
		if(b>=1&&b<=12)
			{switch(b)
			{
				case 1:
						x=0;
						break;
				case 2:
						x=31;
						break;
				case 3:
						x=59;
						break;
				case 4:
						x=90;
						break;
				case 5:
						x=120;
						break;
				case 6:
						x=151;
						break;
				case 7:
						x=181;
						break;
				case 8:
						x=212;
						break;
				case 9:
						x=243;
						break;
				case 10:
						x=273;
						break;
				case 11:
						x=304;
						break;
				default:
						x=334;
						break;
			}
			y=x+c;
			printf("这是第%d天\n",y);
			}	
			else
				printf("月份错误\n");
	}

	return 0;

}
