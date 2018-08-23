#include<stdio.h>

int main()
{
	int a[500]={};
	int i=0;int j; int b=0,c=0;
	int sum_1=0,sum_2=0;
	float  ave_1=0,ave_2=0;
	printf("please input numbers\n");
	for(i=0;i<500;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		break;
	}
	
	for(j=0;j<500;j++)
	{
		if(a[j]%2==0)
		{
			b++;
			sum_1=sum_1+a[j];
		}
		else {
			c++;
			sum_2=sum_2+a[j];
		     }
	}
		ave_1=sum_1/b;
		ave_2=sum_2/c;
		printf("%f\n",ave_1);
		printf("%f\n",ave_2);
	

		
	return 0;
}
