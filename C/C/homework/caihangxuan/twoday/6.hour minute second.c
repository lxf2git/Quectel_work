#include<stdio.h>
int main()
{
        float hour,minte,second,nu;
	        printf("input hour");
        	scanf("%f",&hour);
        	printf("input minte");
        	scanf("%f",&minte);
        	printf("input second");
        	scanf("%f",&second);
        	nu=minte+second/60+hour*60;
        printf("%f\n",nu);
}

