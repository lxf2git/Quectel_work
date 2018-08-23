#include<stdio.h>
int main()
{
		int card,passwd,a,b,c,d,f,e,g,h,z,x,m,i,j,k;
		      static long count=0;
		for(;;)
		{
				for(;;)
				{			
		printf("欢迎光临银行\n");
		printf("有卡请输入1\n没卡请输入0\n");
		scanf("%d",&card);
		

		if(card==0)
		{
				printf("得到ID\n");
			  count++;
			  printf("ID号:%d\n",count);
			  
			  do
			  {
			  	printf("请输入密码");
				scanf("%d",&a);
				printf("请在次输入密码");
				scanf("%d",&b);
			  }while(a!=b);
			  printf("注册成功\n");
		      break;
		}	  
		j=count;
		k=a;
		if(card==1)
		{
		      printf("输入ID\n");
			  scanf("%d",&x);
				if(x==j)			
				printf("请输入密码\n");
				scanf("%d",&m);
				if(m==k)
				{
				printf("密码正确\n");
				break;
				}
				else	
				{
						printf("密码错误\n");
				
				for(i=1;i<=3;i++)
				{
				printf("请在次输入密码");
				scanf("%d",&m);
				if(m==k)
					break;
			    }}
		
           
		}}
		e=0;
		h=0;
		z=0;
             for(;;)
			{ 
			  printf("请输入\n1:存钱\n2:取钱\n3:查询\n4:退出\n");
			  scanf("%d",&d);
			  switch(d)
			  {
			       case 1:
				      printf("输入存款金额\n");
					  scanf("%d",&f);
			              e=e+f;
						break;
				   case 2:
						for(;;)
						{
					printf("输入取款金额\n");
						scanf("%d",&g);
						h=h+g;
						if(g>z)
					printf("余额不足请重新输入\n");
						else
							break;
						}
							break;
					case 3:
					printf("剩余存款为:%d\n",z);
					break;
			//		case 4:
			//	   return 0;	
             }
                 z=e-h;
				 if(d==4)
						 break;
			  }
}}
