#include<stdio.h>
int main()
{
		int y,m,d;
		scanf("%d%d%d",&y,&m,&d);
		if(y%4==0||y%400==0&&y%100!=0)
		{
				printf("是润年\n");
				switch(m)
				{
				case 1:
						printf("该日期是本年的第%d天\n",d);
						break;
				case 2:
						printf("该日期是本年的第%d天\n",d+31);
						break;
				case 3:
						printf("该日期是本年的第%d天\n",d+60);
						break;
				case 4:
						printf("该日期是本年的第%d天\n",d+91);
						break;
				case 5:
						printf("该日期是本年的第%d天\n",d+121);
						break;
				case 6:
						printf("该日期是本年的第%d天\n",d+152);
						break;
				case 7:
						printf("该日期是本年的第%d天\n",d+182);
						break;
				case 8:
						printf("该日期是本年的第%d天\n",d+213);
						break;
				case 9:
						printf("该日期是本年的第%d天\n",d+244);
						break;
				case 10:
						printf("该日期是本年的第%d天\n",d+274);
						break;
				case 11:
						printf("该日期是本年的第%d天\n",d+305);
						break;
				case 12:
						printf("该日期是本年的第%d天\n",d+335);
						break;
				}		
		}
		else
		{
					printf("不是润年\n");
				switch(m)
				{
				case 1:
						printf("该日期是本年的第%d天\n",d);
						break;
				case 2:
						printf("该日期是本年的第%d天\n",d+31);
						break;
				case 3:
						printf("该日期是本年的第%d天\n",d+59);
						break;
				case 4:
						printf("该日期是本年的第%d天\n",d+90);
						break;
				case 5:
						printf("该日期是本年的第%d天\n",d+120);
						break;
				case 6:
						printf("该日期是本年的第%d天\n",d+151);
						break;
				case 7:
						printf("该日期是本年的第%d天\n",d+181);
						break;
				case 8:
						printf("该日期是本年的第%d天\n",d+212);
						break;
				case 9:
						printf("该日期是本年的第%d天\n",d+243);
						break;
				case 10:
						printf("该日期是本年的第%d天\n",d+273);
						break;
				case 11:
						printf("该日期是本年的第%d天\n",d+304);
						break;
				case 12:
						printf("该日期是本年的第%d天\n",d+334);
						break;
				}		
		}
}
