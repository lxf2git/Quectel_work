#include<stdio.h>

int recur(int n)
{
	int ret;
	if(n>0)
	{
		ret = n*recur(n-1);
	}
	else if(n==0)
	{
		ret =  1;
	}

	return ret;
}
int main()
{
	int ret;
	ret = recur(3);//3*2*1	
	printf("ret:%d\n",ret);
	return 0;

}
