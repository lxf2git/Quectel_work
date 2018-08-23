#include<stdio.h>
#define N 10
int main()
{
		int arr[N]={0};
		int i,j=0,count=0;
		for(i=0;i<N;i++)
		{
				if(arr[i]==0)
				{
						j++;
						if(j==3)
						{
								arr[i]=1;
								j=0;
								count++;
						}
				}
				if(i==N-1)
				{
						i = -1;
				}
				if(count==N-1)
				{
					break;
				}

		}
		for(i=0;i<N;i++)
		{
				if(arr[i]==0)
					printf("%d\n",i+1);
		}
		return 0;	
}
