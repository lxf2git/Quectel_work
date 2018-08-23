#include<stdio.h>
int main()
{
	int year,yue,ri,a;
	printf("请输入年月日\n");
	scanf("%d/%d/%d",&year,&yue,&ri);
	if(year%4==0&&year%100!=0||year%400==0)
	{
			switch(yue)
			{		
				case 1: 
                       a=ri;
						printf("一年中第%d天\n",a);
						break;
				case 2:
					   
                       a=ri+31;
						printf("一年中第%d天\n",a);
						break;
				case 3:
					
                       a=ri+31+29;
						printf("一年中第%d天\n",a);
						break;
                case 4:
                       a=ri+31+29+31;
						printf("一年中第%d天\n",a);
						break;
				case 5:
                       a=ri+31+29+31+30;
						printf("一年中第%d天\n",a);
				        break;
				case 6:
                       a=ri+31+29+31+30+31;
						printf("一年中第%d天\n",a);
					   break;
				case 7:	   
                       a=ri+31+29+31+30+31+30;
						printf("一年中第%d天\n",a);
						break;
				case 8:
				      
                       a=ri+31+29+31+30+31+30+31;
						printf("一年中第%d天\n",a);
						break;
				case 9:
                       a=ri+31+29+31+30+31+30+31+30;
						printf("一年中第%d天\n",a);
						break;
				case 10:
                       a=ri+31+29+31+30+31+30+31+30+31;
						printf("一年中第%d天\n",a);
						break;
                case 11:
                       a=ri+31+29+31+30+31+30+31+30+31+30+31;
						printf("一年中第%d天\n",a);
						break;
				case 12:		
                       a=ri+31+29+31+30+31+30+31+30+31+30+31+30;
						printf("一年中第%d天\n",a);
						break;
   
				}

   }
  else 
    
	{
			switch(yue)
			{		
				case 1: 
                       a=ri;
						printf("一年中第%d天\n",a);
						break;
				case 2:
					   
                       a=ri+31;
						printf("一年中第%d天\n",a);
						break;
				case 3:
					
                       a=ri+31+28;
						printf("一年中第%d天\n",a);
						break;
                case 4:
                       a=ri+31+28+31;
						printf("一年中第%d天\n",a);
						break;
				case 5:
                       a=ri+31+28+31+30;
						printf("一年中第%d天\n",a);
				        break;
				case 6:
                       a=ri+31+28+31+30+31;
						printf("一年中第%d天\n",a);
					   break;
				case 7:	   
                       a=ri+31+28+31+30+31+30;
						printf("一年中第%d天\n",a);
						break;
				case 8:
				      
                       a=ri+31+28+31+30+31+30+31;
						printf("一年中第%d天\n",a);
						break;
				case 9:
                       a=ri+31+28+31+30+31+30+31+30;
						printf("一年中第%d天\n",a);
						break;
				case 10:
                       a=ri+31+28+31+30+31+30+31+30+31;
						printf("一年中第%d天\n",a);
						break;
                case 11:
                       a=ri+31+28+31+30+31+30+31+30+31+30+31;
						printf("一年中第%d天\n",a);
						break;
				case 12:		
                       a=ri+31+28+31+30+31+30+31+30+31+30+31+30;
						printf("一年中第%d天\n",a);
						break;
   
				}
	}
}
