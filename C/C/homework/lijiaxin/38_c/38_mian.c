#include"n_power.h"

int main()
{
		int *p;
		int integer,n;
		printf("请输入一个整数及所要求得的次方数:\n");
		scanf("%d%d",&integer,&n);
		p=&integer;
		power(p,n);
		printf("%d",integer%1000);
}
