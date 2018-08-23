#include<stdio.h>
int main()
{
	int c=1,a,b,i;	
	scanf("%d%d",&a,&b);
	for(i=0;i<b;i++)
	     c*=a;
	if(c<10)
			printf("00%d",c);
	else    if(c<100&&c>=10)
		printf("0%d",c);
	else	if(c<1000&&c>=100)
		printf("%d",c);	
	else    if(c%10==0)
	printf("000");
	else
	{
	 c%=1000;
   	 printf("%d",c);	
	}
return 0;
}
