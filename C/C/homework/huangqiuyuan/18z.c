#include<stdio.h>
int main()
{	
	int i,j;
	float average;
	printf("评委打分：\n");
	int a[10];
	for(i=0;i<10;i++)
	scanf("%d\n",&a[i]);

	int max=a[0],min=a[0],plus=0;
	for(i=0;i<10;i++)
{	
	if(a[i]>max)
	 {max=a[i];
	  }
}
	for(j=0;j<10;j++)
{
	if(a[j]<min)
	 {min=a[j];
	  }
}	
	for(i=0;i<10;i++)
	{plus=plus+a[i];}
	
	average=(plus-max-min)/8;

	printf("去掉一个最高分和一个最低分平均分，平均分：%f\n",average);


	return 0;
}
