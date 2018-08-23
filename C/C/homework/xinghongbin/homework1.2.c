#include<stdio.h>
int deal_year(int y);                      //声明
int deal_mon(int a,int m);
void display(int i,int y,int m,int day,int d);

int main()
{
		int year,mon,day;
		int d,m,t;
	    
		printf("input year mon day\n");
		scanf("%d%d%d",&year,&mon,&day);
		t=day;
		if(mon>13)                             //月份检测不出现 13往上的月份
		{
				printf("error");
				return 2;
		}
		switch(deal_mon(year,mon))             // 日期检测不出现 不存在的日期                      
		{				
                case 0:
				      	if(day>30) { printf("error"); return 1;}break;
          		case 1:
                		if(day>31) { printf("error"); return 1;}break;
          		case 2:
                	    if(day>28) { printf("error"); return 1;}break;
                case 3:
                		if(day>29) { printf("error"); return 1;}break;
		}

		for(m=0;m<=mon-1;m++)
		{
			
			if(0==m)
				d=0;

				else 
						switch(deal_mon(year,m))       //用返回值确定一月天数   
						{
								case 0:
										d=30;break;
								case 1:
										d=31;break;
								case 2:
										d=28;break;
								case 3:
										d=29;break;		
						}
			day=day+d;
		}

	//	printf("%d-%d-%d is %d(闰年为1 非闰年为0) %ddays\n",year,mon,t,deal_year(year),day);
		display(deal_year(year),year,mon,day,t);
		return 0;
}

int deal_year(int y)                                  //闰年返回1 非闰年返回0
{
		if(y%4==0&&y%100!=0||y%400==0)     
				return 1;
		return 0;
}
int deal_mon(int a,int m)                            //28天返回2  29天返回3  30天返回1   31天返回0
{		int i;
		if(2==m)
				switch(deal_year(a))
				{
						case 0:
								return 2;           //28
						case 1:
								return 3;	    //29
				}

		else
		{
				int a[]={1,3,5,7,8,10,12};
				for(i=0;i<7;i++)
						if(m==a[i])         
								return 1;          //31
				return 0;              		                   //30  
		}
}
void display(int i,int y,int m,int day,int d)
{
		char *a="闰年";
		char *b="非闰年";
		if(0==i)
			a=b;	
		printf("%d-%d-%d is%s  第%d天",y,m,d,a,day);
		



}
