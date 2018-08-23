#include<stdio.h>
#define N (4)

int main()
{
		int a, b, c;
		int unit, deca, hund, thou;
		printf("please input a b (9~100)\n");
		scanf("%d%d",&a, &b);
		printf("a =%d\nb = %d\n",a,b); 	
		unit = a%10;
		hund = a/10%10;
		deca = b%10;
		thou =  b/10%10;

		c = unit + deca*10 + hund * 100 + thou *1000;

		printf("c = %d\n",c); 


		return 0; 
}
