#include"mf.h"
void fun()
{
		int n,i=0;
		scanf("%d",&n);
		do
		{
				i++;
				n=n/10;
		}while(n!=0);
		printf("是%d位数！\n",i);
}
