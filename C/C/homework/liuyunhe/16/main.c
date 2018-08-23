#include"main.h"
int main()
{
		int nian,yue,a,b,c,d,f;
		printf("请输入 年 月");
	    scanf("%d%d",&nian,&yue);
		int sc;
		
		sc=rili(nian,yue);

	     if(nian%4==0&&nian%100!=0)
		  {
			  f=1;
		  }
		  else
		  {
			  if(nian%400==0)
			  {
			       f=1;
			  }
			  else
			  {
                   f=0;
	          }		
		  }
		  if(f==1)
		  {
				  if(yue>2)
				  {
						  sc=sc+1;
						printf("if%d\n",sc);	
				  }
		  }
		xingqi(sc,yue,f);
		return 0;
}
