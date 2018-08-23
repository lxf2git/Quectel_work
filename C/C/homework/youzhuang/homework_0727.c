#include<stdio.h>

int main()
{
//-------------------------------第1、2题--------------------------------
/*
		int year,month,day;
		int run,n=0; 				//run：是否是润年  n：一年中的第n天
		int i;						//循环变量
		printf("请输入年:\n");
		scanf("%d",&year);
		printf("请输入月:\n");
		scanf("%d",&month);
		printf("请输入日:\n");
		scanf("%d",&day);
		if(year%400==0||(year%4==0&&year%100!=0))
		{
				run=1;
		}
		else
		{
				run=0;
		}
		if(((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day<=31)
		||((month==4||month==6||month==9||month==11)&&day<=30)
		||(run==1&&month==2&&day<=29)||(run==0&&month==2&&day<=28))
		{
				if(run==1)
				{
					printf("%d年是润年!\n",year); 
				}
				if(run==0)
				{
					printf("%d年不是润年!\n",year);
				}
				for(i=1;i<month;i++)
				{
						n=n+31;
						if(i==2&&run==1)
						{
								n=n-2;
						}
						if(i==2&&run==0)
						{
								n=n-3;
						}

						if(i==4||i==6||i==9||i==11)
						{
							n--;
						}
				}
				printf("%d月%d日是%d年中的第%d天\n",month,day,year,n+day);
		}
		else
		{
				printf("请输入正确的年月日！\n");
		}
*/
//---------------------------------第3题-----------------------------------
/*
		int i;
		printf("请输入星期：\n");
		scanf("%d",&i);
		switch(i)
		{
				case 1:
						printf("monday\n");
						break;
				case 2:
						printf("tuesday\n");
						break;
				case 3:
						printf("wednesday\n");
						break;
				case 4:
						printf("thursday\n");
						break;
				case 5:
						printf("friday\n");
						break;
				case 6:
						printf("Saturday\n");
						break;
				case 7:
						printf("sunday\n");
						break;
				default:
						printf("请输入正确信息！\n");
						break;
		}
*/
//---------------------------------第4题------------------------------
		float data1,data2;
		char op;
		printf("请输入表达式:\n");
		scanf("%f%c%f",&data1,&op,&data2);
		switch(op)
		{
				case '+':
						printf("%.0f+%.0f=%.0f\n",data1,data2,data1+data2);
						break;
				case '-':
						printf("%.0f-%.0f=%.0f\n",data1,data2,data1-data2);
						break;
				case '*':
						printf("%.0f*%.0f=%.0f\n",data1,data2,data1*data2);
						break;
				case '/':
						printf("%.0f/%.0f=%.2f\n",data1,data2,data1/data2);
						break;
				default:
						printf("请输入正确表达式!");
						break;
		}

		return 0;
}

