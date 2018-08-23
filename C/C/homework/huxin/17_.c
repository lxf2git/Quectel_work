#include<stdio.h>
int main()
{
	int a[10],max,min,j,i;
	int flag=0,flag1=0;
	printf("please input in : \n");
	scanf("%d",&a[0]);
	max=a[0];
	min=a[0];
	for(i=1;i<10;i++)
	{
		scanf("%d",&a[i]);
		if(max<a[i])
		{
			max = a[i];
			flag = i;
		}
		     	if(min>a[i])
		{
			min = a[i];
			flag1 = i;
		}
	}
	a[flag]=a[9];
	a[9]=max;
        a[flag1]=a[0];
	a[0]=min;
    for(j=0;j<10;j++)
	{
        printf("%d \n",a[j]);
	}
	return 0;
}
