#include<stdio.h>
int main()
{
  int i,a,b,kongge,j,k,yiyueyiri;
  int runnian=0;
  int pingnian=0;
  scanf("%d%d",&a,&b);
  switch(b)
  {
		   case(1):
				  for(i=1900;i<a;i++)
				  {
				      if((i%400==0)||(i%4==0&&i%100!=0))
						  runnian++;
				      else
						  pingnian++;
				  }	  
				       yiyueyiri=(1+runnian*2+pingnian)%7;
				  		 printf("  s  m  t  w  t  f  s\n");
				   		kongge=yiyueyiri%7;
				   		for(k=0;k<kongge;k++)
						   printf("   ");
				   		for(j=1;j<=31;j++)
				   		{
				    		printf("%3d",j);
							if(((j+kongge)%7)==0)
							 printf("\n");		
				   		}
				  		 break;
		  case(2):
				  for(i=1900;i<a;i++)
				  {	 	  
			      if((i%400==0)||(i%4==0&&i%100!=0))
						  runnian++;
				  else
						  pingnian++;
				  }
					yiyueyiri=(4+runnian*2+pingnian)%7;
	   				printf("  s  m  t  w  t  f  s\n");
					kongge=yiyueyiri%7;
					for(k=0;k<kongge;k++)
			         printf("   ");
					if((i%400==0)||(i%4==0&&i%100!=0))
					{ 
							for(j=1;j<=29;j++)
							{
									printf("%3d",j);
									if(((j+kongge)%7)==0)
											printf("\n");
							}
					}				
					else
					{
							for(j=1;j<=28;j++)
							{
							 printf("%3d",j);
							 if(((j+kongge)%7)==0)
							 printf("\n");
							}
					}
						break;
		  case(3):
			       for(i=1900;i<a;i++)
			        {
                      if((i%400==0)||(i%4==0&&i%100!=0))
   							  runnian++;
					  else
   							  pingnian++;
					}
				   if((i%400==0)||(i%4==0&&i%100!=0))
 				   yiyueyiri=(4+runnian*2+pingnian)%7+1;
				   else
				   yiyueyiri=(4+runnian*2+pingnian)%7;	   
				   printf("  s  m  t  w  t  f  s\n");
				   kongge=yiyueyiri%7;
				   for(k=0;k<kongge;k++)
  						   printf("   ");
				   for(j=1;j<=31;j++)
				   {
						   printf("%3d",j);
						   if(((j+kongge)%7)==0)
		 						   printf("\n");
				   }
				   break; 
		  case(4):
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(7+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(7+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=30;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
		  case(5):        
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(2+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(2+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=31;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
		 case(6):					
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(5+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(5+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=30;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
          case (7):                 
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(7+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(7+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=31;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
		  case(8):
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(3+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(3+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=31;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
		  case(9):
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(6+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(6+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=30;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
		  case(10):
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(1+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(1+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=31;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
		  case(11):
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(4+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(4+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=30;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
		  case(12):
				for(i=1900;i<a;i++)
		        {
                if((i%400==0)||(i%4==0&&i%100!=0))
				 runnian++;
		        else
			     pingnian++;
			    }
		        if((i%400==0)||(i%4==0&&i%100!=0))
				 yiyueyiri=(6+runnian*2+pingnian)%7+1;
				 else
				yiyueyiri=(6+runnian*2+pingnian)%7;     
			    printf("  s  m  t  w  t  f  s\n");
		        kongge=yiyueyiri%7;
			    for(k=0;k<kongge;k++)
				printf("   ");
				for(j=1;j<=31;j++)
				{
				printf("%3d",j);
				if(((j+kongge)%7)==0)
				printf("\n");
				 }
				break;
  }
} 
