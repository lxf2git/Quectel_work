#include<stdio.h>

int main()
{
		int x[10] = {1,2,3,4,5,6,7,8,9,10};
		int m,n,a;
		int i,j,k,t;

		printf("请指定位置:\n");
		scanf("%d",&m);
		printf("请输入个数:\n");
		scanf("%d",&n);
		a=m+n/2-1;
		j=m+n-2;
		for(i=m-1;i<a;i++)
		{				
				t=x[i];
				x[i]=x[j];
				x[j]=t;
				j--;				
		}
		for(k=0;k<10;k++)
		{
				printf("%d ",x[k]);
		}
		printf("\n");

		return 0;
}
