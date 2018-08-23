#include<stdio.h>
#define N 10
void init(float a[]);
void average(float b[]);
int main()
{
		float score[N];
		init(score);
		average(score);
		return 0;
}
void init(float a[])
{
		int i;
		for(i=0;i<N;i++)
		{
				scanf("%f",a+i);
		}
}
void average(float b[])
{
		int i;
		float j,sum=0;
		for(i=0;i<N;i++)
		{
				if(b[0]>b[i])
				{
						j=b[0];
						b[0]=b[i];
						b[i]=j;
				}
				
		}
	//	printf("%f\n",b[0]);
		for(i=1;i<N;i++)
		{
				if(b[1]<b[i])
				{
						j=b[i];
						b[1]=b[i];
						b[i]=j;
				}
		}
	//	printf("%f\n",b[1]);
		for(i=2;i<N;i++)
		{
				sum+=b[i];
		}
		printf("%f",sum/(N-2));

}
