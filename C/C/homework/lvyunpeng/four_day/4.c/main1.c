#include<stdio.h>
int year();
int main()
{
	year();


}

int year()
{
	int date,y,yt,m,mt,i,j=0;
	printf("请输入年份\n");
	scanf("%d",&y);
	yt=(y-1900)/4*1461+(y-1900)%4*365;  //当前年份与1900年之间的相差天数
	
	if(y%4==0&&y%100!=0||y%400==0)
	{
		printf("这是润年！\n");
		printf("请输入月份：\n");
		scanf("%d",&m);
		if(m==1)
		{
			mt=yt-1;  //一月份之前的天数
			printf("mt:%d\n",mt);
			date=mt%7+1;
			printf("date:%d \n",date);
			printf("MO    TU    WE    TH    FR    SA    SU   \n");
			for(i=1;;i++)
			{
				j++;
				if(i<date)
				printf("      ");	
				else
				{
					
					if((j>=date)&&((j-date+1)<=31))
					{
						printf("%2d    ",j-date+1);
					}
					else
					{	
						printf("\n");
						return 0;
					}
					if(i%7==0)
					printf("\n");
				}

			}

				printf("\n");			
		}
		if(m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(m<8)
			{
				mt=yt+60+(m-3)*61/2-1;
			}
			else
			{
				mt=yt+91+(m/2-2)*61-1;
			}
			printf("mt:%d\n",mt);
			date=mt%7+1;
			printf("date:%d \n",date);
			printf("MO    TU    WE    TH    FR    SA    SU   \n");
			for(i=1;;i++)
			{
				j++;
				if(i<date)
				printf("      ");	
				else
				{
					
					if((j>=date)&&((j-date+1)<=31))
					{
						printf("%2d    ",j-date+1);
					}
					else
					{
						printf("\n");
						return 0;
					}
					if(i%7==0)
					printf("\n");
				}
			}
				
				printf("\n");			

		}
		if(m==4||m==6||m==9||m==11)
		{
				if(m<9)
				{
					mt=yt+91+(m-4)*61/2-1;

				}
				else
				{
					mt=yt+244+(m-9)*61/2-1;
				}
				printf("mt:%d\n",mt);
				date=mt%7+1;
				printf("date:%d \n",date);
				printf("MO    TU    WE    TH    FR    SA    SU\n");
				for(i=1;;i++)
				{
					j++;
					if(i<date)
					printf("      ");	
					else
					{
						
						if((j>=date)&&((j-date+1)<=30))
						{
							printf("%2d    ",j-date+1);
						}
						else
						{
							printf("\n");
							return 0;
						}
						if(i%7==0)
						printf("\n");
					}
				}

				printf("\n");			
		}
		if(m==2)
		{
			mt=yt+31-1;
		}
			printf("mt:%d\n",mt);
			date=mt%7+1;
			printf("date:%d \n",date);
			printf("MO    TU    WE    TH    FR    SA    SU   \n");
			for(i=1;;i++)
			{
				j++;
				if(i<date)
				printf("      ");	
				else
				{			
					
					if((j>=date)&&((j-date+1)<=29))
					{
						printf("%2d    ",j-date+1);
					}
					else
					{
						printf("\n");
						return 0;
					}
					if(i%7==0)
					printf("\n");
				}
			}
		

				printf("\n");			
	}
	else
	{


		printf("这是不润年！\n");
		printf("请输入月份：\n");
		scanf("%d",&m);
		if(m==1)
		{
			mt=yt;  //一月份之前的天数
			printf("mt:%d\n",mt);
			date=mt%7+1;
			printf("date:%d \n",date);
			printf("MO    TU    WE    TH    FR    SA    SU   \n");
			for(i=1;;i++)
			{
				j++;
				if(i<date)
				printf("      ");	
				else
				{
					
					if((j>=date)&&((j-date+1)<=31))
					{
						printf("%2d    ",j-date+1);
					}
					else
					{
						printf("\n");
						return 0;
					}
					if(i%7==0)
					printf("\n");
				}

			}

				printf("\n");			
		}
		if(m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(m<8)
			{
				mt=yt+59+(m-3)*61/2;
			}
			else
			{
				mt=yt+90+(m/2-2)*61;
			}
			printf("mt:%d\n",mt);
			date=mt%7+1;
			printf("date:%d \n",date);
			printf("MO    TU    WE    TH    FR    SA    SU\n");
			for(i=1;;i++)
			{
				j++;
				if(i<date)
				printf("      ");	
				else
				{
					if((j>=date)&&((j-date+1)<=31))
					{
						printf("%2d    ",j-date+1);
					}
					else
					{
						printf("\n");
						return 0;
					}
					if(i%7==0)
					printf("\n");
				}
			}

				printf("\n");			
		}
		if(m==4||m==6||m==9||m==11)
		{
				if(m<9)
				{
					mt=yt+90+(m-4)*61/2;

				}
				else
				{
					mt=yt+243+(m-9)*61/2;
				}
				printf("mt:%d\n",mt);
				date=mt%7+1;
				printf("date:%d \n",date);
				printf("MO    TU    WE    TH    FR    SA    SU   \n");
				for(i=1;;i++)
				{
					j++;
					if(i<date)
					printf("      ");
					else
					{	
						if((j>=date)&&((j-date+1)<=30))
						{
							printf("%2d    ",j-date+1);
						}
						else
						{
							printf("\n");
							return 0;
						}
							if(i%7==0)
							printf("\n");
					}
				}

				printf("\n");			
		}
		if(m==2)
		{
			{
				mt=yt+31;
			}
			printf("mt:%d\n",mt);
			date=mt%7+1;
			printf("date:%d \n",date);
			printf("MO    TU    WE    TH    FR    SA    SU    \n");
			for(i=1;;i++)
			{
				j++;
				if(i<date)
				printf("      ");	
				else
				{
					if((j>=date)&&((j-date+1)<=28))
					{
						printf("%2d    ",j-date+1);
					}
					else
					{
						printf("\n");
						return 0;
					}
					if(i%7==0)
					printf("\n");
				}
			}

				printf("\n");			
		}






	}






	return 0;



}
