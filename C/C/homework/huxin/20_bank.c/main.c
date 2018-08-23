#include"main.h"
int ba=0;
int main()
{
   int n,x,y;
   printf("press 1 found new_user\n"); //按1 创建新用户
   printf("press 2 into showMenu\n");  //按2  进入主菜单
   scanf("%d",&n);
   
   if(n==1||n==2)
   {
      if(n==1)
	  {
	    x=new_user();    // 创建新用户
	    showMenu(x);   //进入主菜单
      }
	  else
	  {
        y=password();  //输密码
	    showMenu(y);   //进入主菜单
	  }
       
   }
   else
   {
    	printf("input is error\n");  //输入有误
   }
   return 0;
}
