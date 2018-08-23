#include<stdio.h>
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},i,live=10,count=0;
	for(;;)
	{
		for(i=0;i<10;i++)
			{	 	
				if(a[i]!=0)
				{
					count++;
					if(count==3)
					{
						printf("%d has been killed!\n",a[i]);
						a[i]=0;
						count=0;
						live--;
					}
				}		
				if(live==1&&a[i]!=0)
				{	
					printf("%d keeps alive! \n",a[i]);
					return 0;

				}	

			}

 	}
return 0;
}
