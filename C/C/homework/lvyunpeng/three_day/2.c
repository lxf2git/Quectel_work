#include<stdio.h>
int six(int i,int j);
int main()
{
	int i,t=0;

	for(i=0;i<1001;i++)
	{
			if(i%3==2&&i%5==3&&i%7==1)
		{
			t++;
			six(i,t);

		}	



	}
		printf("一共有：%d\n",t);	
		return 0;
}	
int six(int i,int t)
{
		for(;;)
	{	
		
		if(t<7)
		{	
			printf("%d ",i);
			return 0;
			
			
		}
		
		
		else
{
		if(t==7)	
		{	
			
			printf("\n");
			printf("%d ",i);
			return 0;
		}
		else
		{
			printf("%d ",i);
			return 0;
		}	
			
}			
						


	
		}


		return 0;
}

















