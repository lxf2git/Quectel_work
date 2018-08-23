#include<stdio.h>
#include<stdlib.h>
int counter();
int save;
int main()
{
   int m,n,newcounter,newpassword,number,out,in;
   int password;
   char choose;   
   printf("请新建立用户,您的id为:\n");
   m=counter();
   printf("请输入新建密码\n");
   scanf("%d",&password);
   printf("请选择\n进入操作菜单(a)\n退出操作(b)\n");
   getchar();
   scanf("%c",&choose); 
   getchar();
   switch(choose)
   {
   			case 'a':
					n=counter();
					printf("请输入用户id\n密码\n");
					scanf("%d\n",&newcounter);
					scanf("%d\n",&newpassword);
                    if(newcounter==n&&newpassword==password)
					{
					     printf("请选择需要的操作\n取钱(1)\n存钱(2)\n查询余额(3)\n退出菜单(0)\n");
						 scanf("%d",&number);
						 switch(number)
						 {
						      case 1:
									  printf("请输入取出金额\n");
									  scanf("%d",&out);
									  if(out<=save)
									  	printf("当前余额为：%d",save-out);
							  case 2:
						              printf("请输入存入金额\n");
						              scanf("%d\n",&in);
						              save+=in;			  
						      case 3:
									  printf("余额为:%d\n",save);
							  case 4:
							          break;		  
						 }            
						             
					}
			case 'b':
			         exit(0);		
   }                                        
return 0;
}
int counter()//id
{
   int count=0;
   count++;
   printf("id:%d\n",count);
   return count;
}
