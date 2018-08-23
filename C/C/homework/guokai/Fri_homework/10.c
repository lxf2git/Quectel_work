#include<stdio.h>
#include<stdlib.h>
int counter();
void password();
int save(int s);
int main()
{
	char choose;
    int m,n,word;
	int cont,passwd,a=0,b=0;
    printf("请新建立用户,您的id为:\n");
    m=counter(); 
    password();	
	printf("请选择\n进入操作菜单(a)\n退出操作(b)\n");
	scanf("%c",&choose);
	switch(choose)
    	 {
			 case'a':
   					printf("请输入用户id\n密码\n");
   					scanf("%d",&cont);
   					scanf("%d",&passwd);
   					a=counter();password();
   					if(cont==a&&passwd==b)
   						{
   							printf("请选择需要的操作\n取钱(1)\n存钱(2)\n查询余额(3)\n退出菜单(0)\n");
   							scanf("%c",&choose);
            				int passwd,cont,out,a,s,b;
   							switch(choose)
     							{
        		   		case 1:
					    	  	printf("请输入取出金额\n");
								scanf("%d",out);
								b=save(s);
							 	if(out<=b)
							 	printf("当前余额为：%d",save(s)-out);                            
		   		   		case 2:
				 				printf("请输入存入金额\n");
					            save(s);
				   		case 3:
								a=save(s);
								printf("当前余额为：%d",a);
                   		case 4:
								break;
     							}
   						}
					break;
             case'b':
					printf("退出本次操作");
					exit (0);
		 }	
return 0;
}

int counter()  //获得id
{  
   int count=0;
   count++;
   printf("id:%d\n",count);
   return count;
}
void password()  //创建新密码
{  	int word;	
   printf("请输入新建密码\n");   
   scanf("%d",&word);
   printf("您的密码为:%d\n",word);
}
int save(int s)       //存款余额
{ 
	int input;
   scanf("%d\n",&input);	
  s=+input ;
  printf("当前余额为：%d\n",s);
  return s;
}
