#include<stdio.h> 

int main()
{
	int a[11], i;

	for (i= 0; i<11; i++)
	{
		a[i] = i;
	//		printf("%d",a[i]); 
	}
		for (i =0; i<10; i++)
		{
				if(i%3==0)
					a[i] = 0;
		
		}

	
		
			a[1] =0;
			a[2]=0;
			a[7]=0;
			a[5] = 0;
			a[10] =0;
			a[8]= 0;

	//printf("a[1]=%d\n",a[1]); 
 				
	 		
		for (i =0; i<11; i++)
		{
			//	printf("%d",a[i]); 


						if (a[i] != 0)
						{
						printf("%d\n",a[i]);
	 					}		
		}
	  return 0; 
}
