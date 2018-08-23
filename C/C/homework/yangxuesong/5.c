#include<stdio.h>
int main()
{
	int x,y,z,i=0;
	for(z=0;z<21;z++)
	{
		for(y=0;y<51;y++)
			{
				for(x=0;x<101;x++)
				if(x==100-y*2-z*5)
				{	i++;
					break;
				}	
			}
	}
	printf("%d",i);
	return 0;

}
