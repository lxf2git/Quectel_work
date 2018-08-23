#include"main.h"
int new_user()
{
	printf("Your ID:9527\n");
    int n,m;
	printf("please set your password :\n");    //请输入密码
    do
    {			
	    scanf("%d",&n); 	// 密码为456789        
   	
		if(n==123456) 
		{
	  		printf("password is simpleness\n");     //密码过于简单
	  		printf("please again input\n");         //重新输入
		}	
		else 
		{
			printf("please test and verify\n");  //请验证密码
			scanf("%d",&m);
		    if(n==m)
            {
				printf("please into showMenu \n");//请进入主菜单

			}
			else 
		       {
			      printf("password set error\n");
				  exit(0);
			   }	
		}
	}while(n==123456);	
  	return(n);
}

