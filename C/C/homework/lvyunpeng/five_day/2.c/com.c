#include"com.h"
int com()
{

	int ex=0,b,i,j,sum=0,a[10];
	printf("please number:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	//printf("%d\n",a[i]);
	for(i=0;i<10;i++)
	{
		sum+=a[i];
		if(a[0]<=a[i])
		{
			b=a[i];

		}
	
	}
	printf("max:%d\n",b);
	for(i=0;i<10;i++)
	{
		if(a[9]>=a[i])
		{
			a[9]=a[i];
		//	printf("%d",a[9]);
		}
	/*	if(a[9]>a[0])
		{
			a[9]=a[0];
		}*/
	}
	printf("min:%d\n",a[9]);
	ex=(sum-b-a[9])/8;
	printf("平均值:%d\n",ex);


}
