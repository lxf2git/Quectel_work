#include<stdio.h>

int main()
{
	int a,b,c,d;
	printf("请输入一个年月日\n");
	scanf("%d%d%d",&a,&b,&c);
	if(a%4==0&&a%100!=0||a%400==0)
	{
			printf("%d是润年\n",a);
			switch(b)
			{
				case 1:
					d=c;
					printf("该天一年中的%d天\n",d);
					break;
				case 2:
					d=c+31;
					printf("该天一年中的%d天\n",d);
					break;
				case 3:
					d=c+60;
					printf("该天一年中的%d天\n",d);
					break;
				case 4:
					d=c+91;
					printf("该天一年中的%d天\n",d);
					break;
				case 5:
					d=c+121;
					printf("该天一年中的%d天\n",d);
					break;
				case 6:
					d=c+152;
					printf("该天一年中的%d天\n",d);
					break;
				case 7:
					d=c+182;
					printf("该天一年中的%d天\n",d);
					break;
				case 8:
					d=c+213;
					printf("该天一年中的%d天\n",d);
					break;
				case 9:
					d=c+244;
					printf("该天一年中的%d天\n",d);
					break;
				case 10:
					d=c+274;
					printf("该天一年中的%d天\n",d);
					break;
				case 11:
					d=c+305;
					printf("该天一年中的%d天\n",d);
					break;
				default:
					d=c+335;
					printf("该天一年中的%d天\n",d);
					break;
			}
		}
	else
		{
			printf("%d不是润年\n",a);
			switch(b)
			{
				case 1:
					d=c;
					printf("该天一年中的%d天\n",d);
					break;
				case 2:
					d=c+31;
					printf("该天一年中的%d天\n",d);
					break;
				case 3:
					d=c+59;
					printf("该天一年中的%d天\n",d);
					break;
				case 4:
					d=c+90;
					printf("该天一年中的%d天\n",d);
					break;
				case 5:
					d=c+120;
					printf("该天一年中的%d天\n",d);
					break;
				case 6:
					d=c+151;
					printf("该天一年中的%d天\n",d);
					break;
				case 7:
					d=c+181;
					printf("该天一年中的%d天\n",d);
					break;
				case 8:
					d=c+212;
					printf("该天一年中的%d天\n",d);
					break;
				case 9:
					d=c+243;
					printf("该天一年中的%d天\n",d);
					break;
				case 10:
					d=c+273;
					printf("该天一年中的%d天\n",d);
					break;
				case 11:
					d=c+304;
					printf("该天一年中的%d天\n",d);
					break;
				default:
					d=c+334;
					printf("该天一年中的%d天\n",d);
					break;
			}
		}
	return 0;
}
