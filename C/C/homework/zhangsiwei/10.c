#include<stdio.h>
void shushu();
int main()
{	
	
	shushu();
	printf("\n");
	
	return 0;
}
void shushu()
{
	int i;
	int b;
	b=0;
	for(i=1;i<1001;i++)
	{
		if(i%3==2&&i%5==3&&i%7==1)
		{
				b++;
				
			if(b<6)
			{
					printf("%d ",i);
			}
			else
			{
					printf("%d",i);
					printf("\n");
					b=0;
			}
		}
	}
}

