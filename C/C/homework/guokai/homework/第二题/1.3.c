#include<stdio.h>
int main()
{
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if(a%400==0||(a%4==0&&a%100!=0))
 {
 switch(b)
			 {
			   case 1: 
					 printf("一年的第%d天\n",c);
					 break;
			   case 2:
					 printf("一年的第%d天\n",31+c);
			    	 break;
			   case 3:
				     printf("一年的第%d天\n",31+29+c);
				     break;	 
               case 4:
				     printf("一年的第%d天\n",31+29+31+c);
				     break;
			   case 5:
				     printf("一年的第%d天\n",31+29+31+30+c);
					 break;
			   case 6:
                     printf("一年的第%d天\n",31+29+31+30+31+c);
                     break;
			   case 7:
				     printf("一年的第%d天\n",31+29+31+30+31+30+c);
					 break;
			   case 8:
				     printf("一年的第%d天\n",31+29+31+30+31+30+31+c);
					 break;
			   case 9:	
				     printf("一年的第%d天\n",31+29+31+30+31+30+31+31+c);
					 break;
               case 10:
					 printf("一年的第%d天\n",31+29+31+30+31+30+31+31+30+c);
					 break;
			   case 11:
				     printf("一年的第%d天\n",31+29+31+30+31+30+31+31+30+31+c);	   
					 break;
			   case 12:
				     printf("一年的第%d天\n",31+29+31+30+31+30+31+31+30+31+30+c);	             
					 break;
			   	 }             
 }			
else 
          {
switch(b)
               {
					   case 1:
							   printf("一年的第%d天\n",c);
							   break;
					   case 2:	
							   printf("一年的第%d天\n",31+c);
							   break;
					   case 3:	   
                               printf("一年的第%d天\n",31+28+c);
							   break;
					   case 4:
						       printf("一年的第%d天\n",31+28+31+c);
						       break;
					   case 5:
						       printf("一年的第%d天\n",31+28+31+30+c);
						       break;
					   case 6:
						       printf("一年的第%d天\n",31+28+31+30+31+c);
						       break;
					   case 7:
						       printf("一年的第%d天\n",31+28+31+30+31+30+c);                               break;
					   case 8:
						       printf("一年的第%d天\n",31+28+31+30+31+30+31+c);	   
			                   break;
					   case 9:
						       printf("一年的第%d天\n",31+28+31+30+31+30+31+31+c);
					           break;
					   case 10:
							   printf("一年的第%d天\n",31+28+31+30+31+30+31+31+30+c);               
					           break;
					   case 11:	   
							   printf("一年的第%d天\n",31+28+31+30+31+30+31+31+30+31+c);
							   break;
					   case 12:
						       printf("一年的第%d天\n",31+28+31+30+31+30+31+31+30+31+30+c);	   


			                   
			   }



          }		
return 0;
}
