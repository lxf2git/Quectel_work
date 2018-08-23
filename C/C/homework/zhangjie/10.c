#include<stdio.h>
void chu();
int main()
{
	chu();
	printf("\n");
	return 0;
} 

void chu()
{
	int i,j=0;
	for(i=1;i<=1000;i++)
	{
		if((i%3==2)&&(i%5==3)&&(i%7==1))
		{
			j++;
			printf("%d ",i);
			if(j%6==0)
			printf("\n");
		}
	}
}
