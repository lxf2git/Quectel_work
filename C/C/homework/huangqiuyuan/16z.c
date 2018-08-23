#include<stdio.h>

	int a[2][13]={0,31,29,31,30,31,30,31,31,30,31,30,31,0,31,28,31,30,31,30,31,31,30,31,30,31};
	int judje_year(int year)      //判断平年润年
	{
	 if(!(year%4)&&year%100||!(year%400))
	  return 1;
	   else return 0;
	}

	int judge_today(int year,int month,int day)  //判断某一天是星期几
	 {
	   int i,sum=0,today;
	     printf("%d",a[1][2]);
	   if(judge_year(year))   //润年到情况
	
	{
	  for(i=1;i<=month-1;i++)
	  sum=sum+a[0][i];
  	  sum=sum+day;
	 }

	else       //平年的情况
	{
		for(i=1;i<=month-1;i++)
		sum=sum+a[1][i];
		sum+sum+day;
	}
	today=(year-1)+(year-1)/4-(year-1)/100+(year-1)/400+sum;
	today%=7;
	return today;
	}

	void main()
{
	int year,month,i;
	char key;
	while(1)
	{
	  	printf("请输入日期：年，月，日、\n");
		scanf("%d %d",&year,&month);
		if(month>12||month<1)
		{
			printf("请输入正确时间格式！\n\n");
			continue;
		}
		printf("%d年%d月 日历:\n\n",year,month);
		printf("日 一 二 三 四 五 六\n");
		for(i=1;i<=4*judge_today(year,month,1);i++)
			printf(" ");
			for(i=1;i<=a[judge_year(year)][month];i++)
					{
						if(judge_today(year,month,i)==0)
						printf("\n");
						printf("%-4d",i);
					}
	printf("\n\n");
	printf("是否继续查询：(Y/N)");
	getchar();
	printf("\n");
	scanf("%c",&key);
	if(key=='n'||key=='N')
	  break;
	}
}






























	/*int a,m,d,x;
	printf("输入一个年月日");
	scanf("%d%d%d",&a,&m,&d);

	if(a%400==0||a%4==0&&a%100!=0)
  
          
	switch(m)	
{ 
      case 1:
                x=d;
		break;
	case 2:
		x=d+31;
		break;
	case 3:
		x=d+60;
		break;
	case 4:
  		x=d+91;
		break;
	case 5:
                 x=d+122;	 
		break;
	case 6:  
		x=d+152;
		break;
	case 7: 
		x=d+182;
		break;
	case 8:
		x=d+213;
		break;
	case 9:
		x=d+244;
		break;
	case 10:
		x=d+274;
		break;
	case 11:
		x=d+305;
		break;
	case 12:
		x=d+335;
		break;
}
          else
	switch(m)	
{       case 1:
                x=d;
		break;
	case 2:
		x=d+31;
		break;
	case 3:
		x=d+59;
		break;
	case 4:
  		x=d+90;
		break;
	case 5:
                 x=d+121;	 
		break;
	case 6:  
		x=d+151;
		break;
	case 7: 
		x=d+181;
		break;
	case 8:
		x=d+212;
		break;
	case 9:
		x=d+243;
		break;
	case 10:
		x=d+273;
		break;
	case 11:
		x=d+304;
		break;
	case 12:
		x=d+334;
		break;

}

           printf("这是这一年的第%d天\n",x);
	return 0;*/

