#include<stdio.h>
int main()
{
	int i = 0,j = 0,k = 0,all = 0;
	
		for(i=0;i<=100;i++)
			for(j=0;j<=50;j++)	
				for(k=0;k<=20;k++)
					
					if(i+j*2+k*5 == 100)
					{		
							all++;
						printf("%d,%d,%d\n",i,j,k);
					}			
						
		printf("%d\n",all);		
		
return 0;
				
}
		
