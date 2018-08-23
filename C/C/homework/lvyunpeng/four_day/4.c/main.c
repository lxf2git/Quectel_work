#include<stdio.h>
int year();
int main()
{
	year();




}
int year()
{ 	 int i ,j=0 ,date,a,b,c,d,mt,yt;
	 printf("请输入年份：\n");
	 scanf("%d",&a);
	 yt=(a-1900)/4*1461+(a-1900)%4*365;
	 
	 
	if(a%4==0&&a%100!=0||a%400==0)
 {
          printf("这是润年！\n");
          printf("请输入月份：\n");
          scanf("%d",&b);
          d=b-1;
         switch(d)
 {
          case 11:
          c=335;
          break;
          case 10:
          c=305;
          break;
          case 9:
          c=274;
          break;
          case 8:
          c=244;
          break;
          case 7:
          c=213;
          break;
          case 6:
          c=182;
          break;
          case 5:
          c=152;
          break;
          case 4:
          c=121;
          break;
          case 3:
	  c=91;
	  break;
          case 2:
          c=60;
          break;
          case 1:
          c=31;
          break;
          case 0:
          c=0;
          break;
          default:
          printf("没有这个月份！\n");
          break;
  }       
         // printf("请输入几号：\n");
         // scanf("%d",&d);
         // sum=c+d;
         // printf("是一年之中的第%d天\n",sum);
           
		if(c==1||c==3||c==5||c==7||c==8||c==10||c==12)
  {
			
	  for(i=0;i<=34;i++)
	{
		j++;
		if(i<date )
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		
		printf("%2d    ",j-date+1);	
	}
	}
	return 0;
  }
	

 	if(c==2)
{

	  for(i=0;i<=31;i++)
	{
		j++;
		if(i<date )
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		
		printf("%2d    ",j-date+1);
	}
	}

	return 0;


}
	if(c==4||c==6||c==9||c==11)
{

	  for(i=0;i<=32;i++)
	{
		j++;
		if(i<date)
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		
		printf("%2d    ",j-date+1);
	
		if(j>=30)
	{
		return 0;
	}
	}
	}


}
	printf("\n");
}
         
          else
  {       
          printf("不是润年！\n");
          printf("请输入月份：\n");
          scanf("%d",&b);
	    d=b-1;
          switch(d)
  {
          case 11:
          c=334;
          break;
          case 10:
          c=304;
          break;
          case 9:
          c=273;
          break;
          case 8:
          c=243;
          break;
          case 7:
          c=212;
          break;
          case 6:
          c=181;
          break;
          case 5:
          c=151;
          break;
          case 4:
          c=120;
          break;
          case 3:
          c=90;
          break;
          case 2:
          c=59;
          break;
          case 1:
          c=31;
	  break;
          case 0:
          c=0;
          break;
          default:
          printf("没有这个月份！\n");
          break;
 }
         //printf("请输入几号：\n");
         //scanf("%d",&d);
         //sum=c+d;
         //printf("是一年之中的第%d天\n",sum);
 
		if(c==1||c==3||c==5||c==7||c==8||c==10||c==12)
  {
			
	  for(i=0;i<=34;i++)
	{
		j++;
		if(i<date )
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		
		printf("%2d    ",j-date+1);	
	}
	}
	return 0;
  }
	

 	if(c==2)
{
	




	  for(i=0;i<=28;i++)
	{
		j++;
		if(i<date )
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
	
		printf("%2d    ",j-date+1);
	}
	}
	return 0;


}
	if(c==4||c==6||c==9||c==11)
{

	  for(i=0;i<=32;i++)
	{
		j++;
		if(i<date)
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		
		printf("%2d    ",j-date+1);
	
		if(j>=30)
	{
		return 0;
	}
	}
	}


}
	printf("\n");
}
 
 
 
          
          printf("是%d月份\n",b);             
	  mt=c+yt;
	  printf("mt:%d \n",mt);
	  date= mt%7;
	  printf("date:%d \n",date);
	  printf("SU    MO    TU    WE    TH    FR    SA   \n");
	/*  for(i=0;i<=34;i++)
	{
		j++;
		if(i<date )
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		if(0<=j<=9)
		{
			printf("%2d    ",j-date+1);	
		}
		else
		{
		printf("%d    ",j-date+1);
		}
	}
	}*/

		if(c==1||c==3||c==5||c==7||c==8||c==10||c==12)
  {
			
	  for(i=0;i<=34;i++)
	{
		j++;
		if(i<date )
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		
		printf("%2d    ",j-date+1);	
	}
	}
	return 0;
  }
	

 	if(c==2)
{

	  for(i=0;i<=28;i++)
	{
		j++;
		if(i<date )
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
	
		printf("%2d    ",j-date+1);
	}
	}
	return 0;


}
	if(c==4||c==6||c==9||c==11)
{

	  for(i=0;i<=32;i++)
	{
		j++;
		if(i<date)
		printf("      ");
		if(i%7==0)
		printf("\n");
		if(j>=date)
	{
		
		printf("%2d    ",j-date+1);
	
		if(j>=30)
	{
		return 0;
	}
	}
	}


}
	printf("\n");
}
