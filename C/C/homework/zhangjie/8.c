#include<stdio.h>
int main()
{
	int i,j;
	float m,n,k;
	i=100;
	k=1;
	m=100;
	for(j=1;j<=9;j++)
	{
		k=k*2;
		m=m+(200/k);
	}
		n=i/(k*2);
	printf("第10次弹起的高度为%6.2f\n",n);
	printf("第10次落地时共经过%.2f米\n",m);	
	return 0;
}
