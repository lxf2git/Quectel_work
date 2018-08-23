#include<stdio.h>
int main()
{
	int man=10,i,j=0;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for(;;)
	{
		
			for(i=0;i<10;i++)
			{
				if(a[i]!=0)
				{
				if(man!=1)
				{
					j++;
					if(j==3)
					{
						a[i]=0;
						man--;
						printf("man:%d\n",man);
						j=0;
					}
				}
				else
				{
					printf("最后的生存者:%d",a[i]);
					return 0;
				}
				}
			}	
		
	}

}
