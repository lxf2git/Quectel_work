#include<stdio.h>
int main()
{
	int x,n;
	printf("输入一个数：\n");
	scanf("%d",&x);
	n=1;
	for(;;)
{	 x=x/10; 
	  if(x==0)
	   break; 
	 else
	  ++n; 
}	
	printf("这个数是%d位\n",n);
return 0;
}
