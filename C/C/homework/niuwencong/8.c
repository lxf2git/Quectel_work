#include<stdio.h>
int main()
{
	int i,j;
	float a=50;
	float s=100;
	printf("要查询的次数:\n");
	scanf("%d",&j);
	for(i=2;i<=j;i++)
	{
		s=s+2*a;
		a=a/2;
	}
	printf("第%d次落地共经过:%f米\n",j,s);
	printf("第%d次反弹%f米\n",j,a);
return 0;

}


