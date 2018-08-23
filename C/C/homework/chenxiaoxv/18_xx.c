#include<stdio.h>
void fun(int b[]);

int main()
{
	int a[10];
	printf("input十个数:");
	fun(a);
}


void fun(int b[])
{
	int i=0;
	float p=0;
	float s=0;///int s=0
	float max=0;
	float min=0;
	int a[5];
	min=a[5];
	for(i=0;i<10;i++)
	{
		scanf("%d",&b[i]);
		if(max<b[i])
		{
			max=b[i];
		}
		 if(0<=min-b[i])
		{	
			
			min=b[i];	
		}
		
	
		s=s+b[i];
	
	}

	/*	int j;
		for(j=0;j<10;j++)
		{
		 	printf("%d ",b[j]);
	*///	} 
	//	printf("%d\n%d\n",min,max);
		p=(s-min-max)/8;
		printf("%f\n",p);

}	







