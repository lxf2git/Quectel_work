//约瑟夫游戏
#include<stdio.h>
#define N 10
#define M 9
//N游戏人数
//M需要死亡人数 
void game(int a[])
{
	int i,j=0,k,b=0;
	for(i=0;b!=M;i++)
	{
		if(a[i]!=0)
		{
			j++;
			if(j==3)
			{			
				j=0;
				for(k=i;;k++)
				{			
					if(a[k]!=0)
					{	
						a[k]=0;
						b++;//			printf("%d   ",k);
						break;
					}
					if(k==N-1)
					k=-1;
				}
			}
		}
		if(i==N-1)
		i=-1;
	}
	for(i=0;i<N;i++)
	{
		if(a[i]!=0)
		printf("%d \n",i+1);
	}
}
int main()
{
	int i;
	int a[N];
	for(i=0;i<N;i++)
	{      
		a[i]=1;
	}
	game(a);
	return 0;
}
