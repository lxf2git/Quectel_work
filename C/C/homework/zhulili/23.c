#include<stdio.h>
#define N 6
int main()
{
	int i,num,position,m=0,k=0;
	int  a[N]={0},q=0;
	printf("请输入六位的数组：\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("逆排序的指定位置和个数：");
	scanf("%d,%d",&position,&num);
		if(num==1)
		{
			a[position]=a[position];
		}
		else 
		{
			k=position;
			for(position;position<k+num/2;position++)
			{			
				m=a[position-1];
				a[position-1]=a[position+num-2-q];
				a[position+num-2-q]=m;
				q+=2;
			}	
		}	
		for(i=0;i<N;i++)
		printf("%d ",a[i]);
		return 0;

}
