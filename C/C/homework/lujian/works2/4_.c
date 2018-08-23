#include<stdio.h> 
int main()
{
	float  h=100,l=0;
	int i=0;
	if(i==0)
	{
	printf("the %d ci ,h=%5.2f l=%5.2f \n",i,h,l);
	i++;
	}
	if(i==1)
	{
	l=h;
	h/=2.0;
	printf("the %d ci ,h=%5.2f l=%5.2f \n",i,h,l);
	}
	for(i=2;i<=10;i++)
	{
			l+=h*2;
			h/=2.0;
	printf("the %d ci ,h=%5.2f l=%5.2f \n",i,h,l);
		
	}
	printf("the highet is h = %5.2f\n",h);
	printf("the total miters l=%5.2f\n",l);

	return(0);
}




