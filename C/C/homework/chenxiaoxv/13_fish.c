#include<stdio.h>

int main()
{
	int a,b,c,d,e,f;
 	a=0;
	for(;;a++)
	{
		if(0==(a-1)%5)
	{ 
	b=((a-1)/5);
		if(0==(b*4-1)%5)
		{
		c=(b*4-1)/5;
			if(0==(c*4-1)%5)
			{
			d=(c*4-1)/5;
				if(0==(d*4-1)%5)
				{
				e=(d*4-1)/5;
					if(0==(e*4-1)%5)
					{
					f=(e*4-1)/5;
					printf("%d\n",a);
					return 0;
					}
				}
			}
		}
	}		
			
}	

return 0;
}


