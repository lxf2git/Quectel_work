#include"count.h"

int main()
{
	int a;
	int wei;
	do
	{
	printf("please input a + number\n");
	scanf("%d",&a);
	wei=count(a);
	printf("%d\n",wei);
	}while(a>0);
}
