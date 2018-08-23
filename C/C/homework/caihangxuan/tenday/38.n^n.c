#include<stdio.h> 
int main()
{
	int n_ride,_int,times,ride,last[3]={};
	printf("请输入一个正数。\n");
	scanf("%d",&_int);
	printf("请输入平数。\n");
	scanf("%d",&n_ride);
	ride=_int;
	for(times=1;times<n_ride;times++)
	{
		_int=_int*ride;
	}
	printf("%d\n",_int);
	printf("%d\n",_int%1000);
}
