#include"main.h"
int showMenu(int n)
{  
	int m;	
    if (n==4567890)	
	{      
		   printf("please choose your project:\n");
		   
		   do
	       {			   
	            printf("1:存款  2:查询\n");
	            printf("3:取款  4:退出\n");
	       		scanf("%d",&m);
		   		switch(m)
		   		{
		   		   case 1:
                      printf("Tanks your patronage\n");  //谢谢惠顾
					  deposit();
					  break;
			       case 2:
					  inquire();
					  break;
				   case 3:
				      withdrawing();
				      break;
				   case 4:
				      break;
				default:
					 printf("input in error\n");
		    	}
		  }while(m==1||m==2||m==3);	
	 }
	else 
	{   
		printf("password is error \n");
	}
	return 0;
}
