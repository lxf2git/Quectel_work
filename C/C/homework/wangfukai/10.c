#include<stdio.h>

int main()
{
	int a,j;j=0;
	for(a=1;a<=1000;a++)
	if((a%3==2)&&(a%5==3)&&(a%7==1))
        {
	j++;
	if(j%6==0)
	printf("%d\n",a);
	else printf("%d",a);
	}	
	return 0;
	
}
