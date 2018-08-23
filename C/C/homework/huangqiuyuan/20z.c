#include<stdio.h>
int id,passwd,nid,npasswd;
void adrr( )
 	{	
		 
	//	int id,passwd;
		printf("请输入ID号：");
		scanf("%d",&id);
		printf("请输入密码：\n");
		scanf("%d",&passwd);
	//	allpw();
	}


int creat( )
	{
		int qu,cun,x=0,q,p;
		for(nid=2;nid<10;nid++)
	{	printf("您的新ID：%d\n",nid);
		break;	
	}	
		printf("请输入新帐号的密码：");
		scanf("%d",&npasswd);
		printf("创建成功！\n");
		return 0;
	}

void  allpw( )
	{	
		int q,qu,cun,x,y;
		if(id==1&&passwd==123)
		{
		  x=100;
		  //y=0;
		  //y=x+y;
		printf("您的账户余额：%d\n",x);
		printf("取款请按1\n存款请按0\n");
		scanf("%d",&q);
			if(q==1)
			{printf("取款金额：");
				scanf("%d",&qu);
					x=x-qu;
					printf("余额：%d\n",x);
			//	return 0;
			}
			if(q==0)
			{printf("存款金额：");
				scanf("%d",&cun);
					x=x+cun;
					printf("余额：%d\n",x);
			//	return 0;
			}
			//	else
			//		printf("错误命令，重新选择！");
			//	return 0;
		}				
		if(id==nid&&passwd==npasswd)
		{
		x=0;
		//y=x+y	
		printf("您的账户余额：%d\n",x);
		printf("取款请按1\n存款请按0\n");
		scanf("%d",&q);
			if(q==1)
			{printf("取款金额：");
				scanf("%d",&qu);
					x=x-qu;
					printf("余额：%d\n",x);
					//return 0;
			}
			if(q==0)
			{printf("存款金额：");scanf("%d",&cun);x=x+cun;printf("余额：%d\n",x);//return 0;
			}
		          // else
			    //      printf("错误命令，重新选择！");	
		//	return 0;

		}
	}
int main()
{	
	int i;//id,passwd;
  	for(;;)
{
	printf("登录帐号请按1\n创建帐号请按0\n退出按#\n",i);
	for(;;)
	{
	scanf("%d",&i);
	 if (i==1)
	{
		adrr();
		allpw( );
		break;}
	    if(i==0)
	      { creat( );
	//	allpw( );
	        	break;}
		  if(i=='#');
			{break;}
		//	else
		//	{ printf("输入错误！\n");
		  //		break;}
	}
	       		if(i=='#')
			  break;

		
}
       return 0;

}


