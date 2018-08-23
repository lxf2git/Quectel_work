#include<stdio.h>

int main()
{
		int x,y,a,b,c,i,j;
		printf("please input a year month\n");
		scanf("%d%d",&x,&y);
		a=x-1900;
		b=x*365+a/4-a/100;
		if(x%4==0&&x%100!=0||x%400==0)
		{
		switch(y)
		{
				case 1:
					c=b%7;
					printf("mon tue web thu fri sat san\n");
					for(i=1;i<c;i++)
						printf("    ");
					for(j=1;j<=31;j++)
					{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
					}
					break;
					case 2:
						c=(b+31)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=29;j++)
						{
							printf("%2d",j);
							if((i+j)%7==0)
							printf("\n");
						}
						break;
				case 3:
						c=(b+60)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
							printf(" %2d  ",j);
							if((i+j)%7==0)
							printf("\n");
						}
					case 4:
						c=(b+91)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 5:
						c=(b+121)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 6:
						c=(b+152)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 7:
						c=(b+182)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 8:
						c=(b+214)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 9:
						c=(b+244)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 10:
						c=(b+274)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 11:
						c=(b+305)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 12:
						c=(b+335)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
			}
		}
		else		
		{
			switch(y)
			{
				case 1:
					c=b%7;
					printf("mon tue web thu fri sat san\n");
					for(i=1;i<c;i++)
						printf("    ");
					for(j=1;j<=31;j++)
					{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
					}
						break;
					case 2:
						c=(b+31)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=28;j++)
						{
							printf(" %2d  ",j);
							if((i+j)%7==0)
							printf("\n");
						}
						break;
				case 3:
						c=(b+59)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
							printf(" %2d  ",j);
							if((i+j)%7==0)
							printf("\n");
						}
					case 4:
						c=(b+90)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 5:
						c=(b+120)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 6:
						c=(b+151)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %2d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 7:
						c=(b+181)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %d  ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 8:
						c=(b+212)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %d   ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 9:
						c=(b+243)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %d   ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 10:
						c=(b+273)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %d   ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 11:
						c=(b+304)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=30;j++)
						{
						printf(" %d   ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
					case 12:
						c=(b+334)%7;
						printf("mon tue web thu fri sat san\n");
						for(i=1;i<c;i++)
							printf("    ");
						for(j=1;j<=31;j++)
						{
						printf(" %d   ",j);
						if((i+j)%7==0)
							printf("\n");
						}
						break;
			}
		}
			return 0;
}
