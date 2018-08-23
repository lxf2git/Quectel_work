#include<stdio.h>

int main()
{
		int i,j,k;  //i:1分 j：2分 k：5分    一共1￥
		int count=0;	//count
		for(i=0;i<=100;i++)
			for(j=0;j<=50;j++)
				for(k=0;k<=20;k++)
				{
					if(100==k*5+j*2+i*1)
					{
						count++;
						printf("100=1*%d+2*%d+5*%d\n",i,j,k);
					}
				}
		printf("total:%d\n",count);
		return 0;

}
