#include<stdio.h>
void hanshu();
int main()
{
	hanshu();
	return 0;
}
void hanshu()
{
	int i,y;
	y=1;
	for(i=1;i<6;i++)
	{
		
		y=y*5+1;
		
	}
	printf("%d\n",y);
}
