#include<stdio.h>

int main()
{
	int a,m,d,x;
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
	return 0;

}
