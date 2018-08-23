#include<stdio.h>
int main()
{
		int nian,yue,d,xing,a,tian,i,m,n=0;
scanf("%d%d",&nian,&yue);
printf(" sun mon tue wed thu fri sat\n");
if((nian%4==0&&nian%100!=0)||nian%400==0)
{
		if(yue<=7)
		{
		if(yue>2)
		d=30*(yue-2)+29+yue/2;
       else d=31*(yue-1);}
      else d=213+31*(yue-8)-(yue-8)/2;
		
	  for(m=1900;m<nian;m++)
	  {
if((m%4==0&&m%100!=0)||m%400==0)
			n++;
	  }

      tian=365*(nian-1900)+d+n;
	  xing=tian%7+1;
	  for(a=1;a<=xing;a++)
	  {
			  if(xing==7)
					  break;
					  printf("    ");
	  }
		if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
		{
		for(i=1;i<=31;i++)
		{

				printf("%4d",i);
				if((i+xing)%7==0)
				
					printf("\n");
				if(i==31)
						printf("\n");
				
		}}	
		else if(yue==4||yue==6||yue==9||yue==11)
		for(i=1;i<=30;i++)
		{
				printf("%4d",i);
				
				if((i+xing)%7==0)
					printf("\n");
				if(i==30)
						printf("\n");
		}
		else if(yue==2)
			for(i=1;i<=29;i++)
			{  
				printf("%4d",i);
				if((i+xing)%7==0)
					printf("\n");
				if(i==29)
						printf("\n");
			}
}
else
{
		if(yue<=7)
		
		if(yue>2)
		d=30*(yue-1)+yue/2-2;
       else d=31*(yue-1);
      else d=212+31*(yue-8)-(yue-8)/2;
	  for(m=1900;m<nian;m++)
	  {
if((m%4==0&&m%100!=0)||m%400==0)
			n++;
	  }

      tian=365*(nian-1900)+d+n;
	  xing=tian%7+1;
	  
	  for(a=1;a<=xing;a++)
	  {
	  if(xing==7)
	  
break;
			  printf("    ");}
		if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
		
		for(i=1;i<=31;i++)
		{

				printf("%4d",i);
				if((i+xing)%7==0)
				
					printf("\n");
				if(i==31)
						printf("\n");
				
		}	
		else if(yue==4||yue==6||yue==9||yue==11)
		for(i=1;i<=30;i++)
		{
				printf("%4d",i);
				
				if((i+xing)%7==0)
					printf("\n");
				if(i==30)
						printf("\n");
		}
		else if(yue==2)
			for(i=1;i<=28;i++)
			{  
				printf("%4d",i);
				if((i+xing)%7==0)
          printf("\n");
				if(i==28)
						printf("\n");
}}}
