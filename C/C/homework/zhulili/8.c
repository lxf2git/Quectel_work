#include<stdio.h>
int main()
{
	float height=100.0,lucheng=100.0;
	int i;
	for(i=0;i<10;i++)
	{
		
		height=height/2;
		lucheng=lucheng+2*height;
		if(i==9)
		{
			printf("%f\n",height);
		}
    }
	printf("%f\n",lucheng);
	 return 0;
}






