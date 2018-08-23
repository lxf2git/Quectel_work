#include<stdio.h>

void yushu();

int main()
{
	yushu();
	return 0;
}
void yushu()
{
	int i,j;
	j=0;
	for(i=1;i<=1000;i++)
	{
		if((i%3==2)&&(i%5==3)&&(i%7==1))
		{
			printf("%3d ",i);
			j++;
			if(j%6==0)
				printf("\n");
		}
	}
	printf("\n");
}

