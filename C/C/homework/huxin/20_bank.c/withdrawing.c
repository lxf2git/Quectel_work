#include"main.h"
extern int ba;
int withdrawing()
{
	int n=0,m=1;
	printf("please input you withdrawing money\n");//请输入你取钱金额
	scanf("%d",&n);
	if(ba>=n)
	{		
	   printf("please again affirm money\n");     //请确认金额
	   scanf("%d",&m);
	   while(1)
	   {
         	if(n!=m)
	    	{
	     		printf("withdrawing is error\n");  //取款失败
	      		break;
 	  		}
	    	else
	   		{	 
	     		printf("withdrawing succeed\n");   //取款成功
				ba=ba-n;
	     		break;
        	}
		}
	}
    else
	{
		printf("balance not enough \n");            //余额不足
	}	
    return(n); 	
}
