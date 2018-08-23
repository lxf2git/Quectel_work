#include<stdio.h>
int main()
{
	int i,j,k,m;
	printf("输入年月日\n");
	scanf("%d%d%d",&i,&j,&k);
 	if((i%4==0&&i%100!=0)||i%400==0)
{
	printf("该年是润年\n");
	switch(j)
		{
			case 1:
			m=k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 2:
			m=31+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 3:
			m=31+29+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 4:
			m=31+29+31+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 5:
			m=31+29+31+30+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 6:
			m=31+29+31+30+31+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 7:
			m=31*3+2*30+29+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 8:
			m=31*4+2*30+29+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 9:
			m=31*5+2*30+29+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 10:
			m=31*5+3*30+29+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 11:
			m=31*6+3*30+29+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			default:
			m=31*6+4*30+29+k;
			printf("该天是一年中的第%d天\n",m);
}
		}
		else
{		
		printf("该年不是润年\n");
	   switch(j)
		{
			case 1:
			m=k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 2:
			m=31+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 3:
			m=31+28+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 4:
			m=31+28+31+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 5:
			m=31+28+31+30+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 6:
			m=31+28+31+30+31+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 7:
			m=31*3+2*30+28+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 8:
			m=31*4+2*30+28+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 9:
			m=31*5+2*30+28+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 10:
			m=31*5+3*30+28+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			case 11:
			m=31*6+3*30+28+k;
			printf("该天是一年中的第%d天\n",m);
			break;
			default:
			m=31*6+4*30+28+k;
			printf("该天是一年中的%d天\n",m);
			break;
	}
}
	return 0;
}
