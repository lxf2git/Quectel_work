#include"main.h"
int main()
{
	int i,a[10],sum=0;
	float average;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,10);
	
	/*for(i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	}*/
	for(i=1;i<=8;i++)
	sum+=a[i];
	average=(float)sum/8;
	printf("average=%f\n",average);
}
