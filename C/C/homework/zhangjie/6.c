#include<stdio.h>
int main()
{
	int i,j,k;
	float m;
	scanf("%d:%d:%d",&i,&j,&k);
	m=(60*i)+j+((k*0.1)/6);
	printf("%.2f分钟\n",m);
	return 0;
}
