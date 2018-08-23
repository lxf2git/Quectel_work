#include<stdio.h>

int main()
{
	int i,j;
	j=0;
	for(i=1;i<1000;i++)
	if(i%3==2&&i%5==3&&i%7==1)
	{
			j++;
			if(j%6==0)
			printf("%d\n",i);
			else
		printf("%d",i);
    }
}
